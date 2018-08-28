/*
    MICROCHIP SOFTWARE NOTICE AND DISCLAIMER:

    You may use this software, and any derivatives created by any person or
    entity by or on your behalf, exclusively with Microchip's products.
    Microchip and its subsidiaries ("Microchip"), and its licensors, retain all
    ownership and intellectual property rights in the accompanying software and
    in all derivatives hereto.

    This software and any accompanying information is for suggestion only. It
    does not modify Microchip's standard warranty for its products.  You agree
    that you are solely responsible for testing the software and determining
    its suitability.  Microchip has no obligation to modify, test, certify, or
    support the software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE, ITS INTERACTION WITH MICROCHIP'S
    PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT, WILL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT
    (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY,
    INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF
    ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWSOEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL
    LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED
    THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF
    THESE TERMS.
*/
#include <xc.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "mtouch_sensor.h"
#include "../mcc.h"

#if _XTAL_FREQ == 64000000
    #define DELAY_SCALER                                     (uint8_t)3   
#elif _XTAL_FREQ >= 32000000
    #define DELAY_SCALER                                     (uint8_t)2   
#elif _XTAL_FREQ >= 16000000
    #define DELAY_SCALER                                     (uint8_t)1
#else
    #define DELAY_SCALER                                     (uint8_t)0
#endif

#define DELAY_CYCLE(cycle)                                  ((mtouch_sensor_time_t)cycle << DELAY_SCALER)

#define Sensor_calculate_active_thrs(oversampling)          ((mtouch_sensor_packetsample_t)(oversampling)<<2)
#define Sensor_calculate_cal_thrs(oversampling)             ((mtouch_sensor_packetsample_t)(oversampling)<<1)
#define Sensor_calculate_balance_point(oversampling)        ((mtouch_sensor_packetsample_t)(oversampling)<<9)


#define FH_NOISE_THRS                                       (mtouch_sensor_packetsample_t)100
#define FH_OVERLIMIT_THRS                                   (uint8_t)6
#define MTOUCH_SENSOR_SAMPLEDELAY_MIN                       (uint8_t)DELAY_CYCLE(0)
#define MTOUCH_SENSOR_SAMPLEDELAY_MAX                       (uint8_t)DELAY_CYCLE(15)
#define FRQ_0                                               (uint8_t)MTOUCH_SENSOR_SAMPLEDELAY_MIN
#define FRQ_1                                               (uint8_t)(MTOUCH_SENSOR_SAMPLEDELAY_MAX/2)
#define FRQ_2                                               (uint8_t)MTOUCH_SENSOR_SAMPLEDELAY_MAX

typedef uint16_t mtouch_sensor_adcsample_t;
#define MTOUCH_SENSOR_ADCSAMPLE_MIN ((mtouch_sensor_adcsample_t)0)
#define MTOUCH_SENSOR_ADCSAMPLE_MAX ((mtouch_sensor_adcsample_t)1023)

typedef uint8_t mtouch_sensor_packetcounter_t;
#define MTOUCH_SENSOR_PACKET_ADCSAMPLES ((mtouch_sensor_packetcounter_t)32)
#define MTOUCH_SENSOR_PACKETCOUNTER_MIN ((mtouch_sensor_packetcounter_t)0)
#define MTOUCH_SENSOR_PACKETCOUNTER_MAX ((mtouch_sensor_packetcounter_t)UINT8_MAX)

typedef uint16_t mtouch_sensor_packetsample_t;
#define MTOUCH_SENSOR_PACKETSAMPLE_MIN ((mtouch_sensor_packetsample_t)0)
#define MTOUCH_SENSOR_PACKETSAMPLE_MAX ((mtouch_sensor_packetsample_t)UINT16_MAX)


typedef uint8_t mtouch_sensor_delay_t;

typedef uint8_t mtouch_sensor_addcap_t;
#define ADD_CAP_LIMIT               (mtouch_sensor_addcap_t)31

typedef uint8_t mtouch_sensor_time_t;
#define MIN_ACQ_TIME                ((mtouch_sensor_time_t)DELAY_CYCLE(1))
#define MAX_ACQ_TIME                ((mtouch_sensor_time_t)DELAY_CYCLE(48))
#define MIN_PRECHARGE_TIME          ((mtouch_sensor_time_t)DELAY_CYCLE(1))
#define MAX_PRECHARGE_TIME          ((mtouch_sensor_time_t)DELAY_CYCLE(48))

typedef struct
{
 const  enum mtouch_sensor_names        sensor_name;
 const  uint8_t                         adpch;     
        mtouch_sensor_time_t            precharge_time;
        mtouch_sensor_time_t            acquisition_time;
        mtouch_sensor_packetcounter_t   oversampling;
        mtouch_sensor_addcap_t          addcap;
        mtouch_sensor_sample_t          rawSample;
        unsigned                        enabled:1;
        unsigned                        sampled:1;
        unsigned                        acitve:1;
        unsigned                        calibrated:1;       
        unsigned                        acqTime_cal:1;
} mtouch_sensor_t;

/*
 * =======================================================================
 * LOCAL FUNCTIONS
 * =======================================================================
 */
static void                     Sensor_setSamplePeriod      (void);
static void                     Sensor_scheduleNextScan     (void);
static inline void              MTOUCH_Sensor_Service       (void);

static void                     Sensor_SetTrisBit           (enum mtouch_sensor_names sensor,uint8_t TrisBit);
static inline void              Sensor_setSampled           (mtouch_sensor_t* sensor);
static inline void              Sensor_Sampled_Reset        (mtouch_sensor_t* sensor);
static inline void              Sensor_setActive            (mtouch_sensor_t* sensor);
static inline void              Sensor_setInactive          (mtouch_sensor_t* sensor);

static        bool              Sensor_isEnabled            (mtouch_sensor_t* sensor);

static inline bool              Sensor_isCalibrated         (mtouch_sensor_t* sensor);
static inline void              Sensor_setCalibrated        (mtouch_sensor_t* sensor);
static inline void              Sensor_setCalibratAcqTime   (mtouch_sensor_t* sensor);
static inline bool              Sensor_isCalibratingAcqTime (mtouch_sensor_t* sensor);
static enum mtouch_sensor_error Sensor_autoCalibration      (mtouch_sensor_t* sensor);

static void                     Sensor_FrequencyHopping     (void);
static void                     Sensor_FrequencyHopping_Autotune_Process(void);

static void                     Sensor_RawSample_Update     (mtouch_sensor_t* sensor);
static void                     Sensor_postAcquisitionProcess(enum mtouch_sensor_names name);
static void                     Sensor_DefaultCallback       (enum mtouch_sensor_names sensor);

static mtouch_sensor_packetsample_t medianFilter(enum mtouch_sensor_names sensor);

/*
 * =======================================================================
 *  Callback Function Pointers
 * =======================================================================
 */
static void (*callback_sampled)(enum mtouch_sensor_names sensor) = Sensor_DefaultCallback;

/*
 * =======================================================================
 *  Local Variables
 * =======================================================================
 */
static mtouch_sensor_packetsample_t     sensor_medianBuffer[MTOUCH_SENSORS][3];
static mtouch_sensor_packetsample_t     packet_sample[MTOUCH_SENSORS];
static enum mtouch_sensor_names         currentScanSensor = 0;
static bool                             sampling_flag = false;
static volatile bool                    scanInterrupted = false;

/*
 * =======================================================================
 *  Sensor runtime data
 * =======================================================================
 */
static uint8_t                          freq_index = 0;
static uint8_t                          freq_hop[3] = {FRQ_0,FRQ_1,FRQ_2};
static mtouch_sensor_delay_t            sample_delay = FRQ_0;    

/*
 * =======================================================================
 *  Sensor Configurations
 * =======================================================================
 */
const mtouch_sensor_t mtouch_sensor_init[MTOUCH_SENSORS] = {
    {Sensor_ANE2,0x22,DELAY_CYCLE(10),DELAY_CYCLE(5),32,0,0,0,0,0,0,0},
    {Sensor_ANE3,0x23,DELAY_CYCLE(10),DELAY_CYCLE(5),32,0,0,0,0,0,0,0},
    {Sensor_ANE4,0x24,DELAY_CYCLE(10),DELAY_CYCLE(5),32,0,0,0,0,0,0,0},
    {Sensor_ANE5,0x25,DELAY_CYCLE(10),DELAY_CYCLE(5),32,0,0,0,0,0,0,0},
    {Sensor_ANE6,0x26,DELAY_CYCLE(10),DELAY_CYCLE(5),32,0,0,0,0,0,0,0},
};

static mtouch_sensor_t mtouch_sensor[MTOUCH_SENSORS];

/*
 * =======================================================================
 * MTOUCH_Sensor_Init()
 * =======================================================================
 */
enum mtouch_sensor_error MTOUCH_Sensor_Initialize(enum mtouch_sensor_names sensor)
{
    switch(sensor)                                                              /* Overwrite TRIS,ANSEL and WPU*/
    {
        case 0:  
            WPUEbits.WPUE2 = 0;
            ANSELEbits.ANSELE2 = 0;
            break; 
        case 1:  
            WPUEbits.WPUE3 = 0;
            ANSELEbits.ANSELE3 = 0;
            break; 
        case 2:  
            WPUEbits.WPUE4 = 0;
            ANSELEbits.ANSELE4 = 0;
            break; 
        case 3:  
            WPUEbits.WPUE5 = 0;
            ANSELEbits.ANSELE5 = 0;
            break; 
        case 4:  
            WPUEbits.WPUE6 = 0;
            ANSELEbits.ANSELE6 = 0;
            break; 
        default: return MTOUCH_SENSOR_ERROR_invalid_index;
    }
    MTOUCH_Sensor_Enable(sensor);
    MTOUCH_Sensor_Calibrate(sensor);
    Sensor_Sampled_Reset(&mtouch_sensor[sensor]);
    
    return MTOUCH_SENSOR_ERROR_none;
}

static void Sensor_SetTrisBit(enum mtouch_sensor_names sensor,uint8_t TrisBit)
{
    switch(sensor)                                                     
    {
        case 0:  
            TRISEbits.TRISE2 = TrisBit;
            break; 
        case 1:  
            TRISEbits.TRISE3 = TrisBit;
            break; 
        case 2:  
            TRISEbits.TRISE4 = TrisBit;
            break; 
        case 3:  
            TRISEbits.TRISE5 = TrisBit;
            break; 
        case 4:  
            TRISEbits.TRISE6 = TrisBit;
            break; 
        default: break;
    }
}

/*
 * =======================================================================
 * MTOUCH_Sensor_ADCC_Initilaize
 * =======================================================================
 *  initialization for ADCC for CVD mode
 */
void MTOUCH_Sensor_ADCC_Initialize(void)
{
    // ADCCS  
    ADCLK = 0x1f;
    // ADNREF VSS; ADPREF VDD; 
    ADREF = 0x00;
    // ADCAP 0; 
    ADCAP = 0x00;
    // ADLTHL 0; 
    ADLTHL = 0x00;
    // ADLTHH 0; 
    ADLTHH = 0x00;
    // ADUTHL 0; 
    ADUTHL = 0x00;
    // ADUTHH 0; 
    ADUTHH = 0x00;
    // ADSTPTL 0; 
    ADSTPTL = 0x00;
    // ADSTPTH 0; 
    ADSTPTH = 0x00;
    
    // ADDSEN enabled; ADGPOL digital_low; ADIPEN enabled; ADPPOL VSS; 
    ADCON1 = 0x41;
    // ADCRS 0; ADMD Average Burst mode; ADACLR enabled; ADPSIS ADRES; 
    ADCON2 = 0x8B;

    // ADCALC First derivative of Single measurement; ADTMD enabled; ADSOI ADGO is cleared until ADTIF is triggered 
    ADCON3 = 0x0F;

    // ADGO stop; ADFM right; ADON enabled; ADCONT Enabled; ADCS FOSC/ADCLK; 
    ADCON0 = 0xC4;
   
    // Clear the ADC Threshold interrupt flag
    PIR1bits.ADTIF = 0;
    // Enabling ADCC threshold interrupt.
    PIE1bits.ADTIE = 1;
}


void MTOUCH_Sensor_InitializeAll(void)
{
    enum mtouch_sensor_names sensor; 
    
    memcpy(mtouch_sensor,mtouch_sensor_init,sizeof(mtouch_sensor_init));
    
    for (sensor = 0; sensor < MTOUCH_SENSORS; sensor++)
    {
        MTOUCH_Sensor_Initialize(sensor);
    }
}

bool MTOUCH_Sensor_SampleAll(void)
{
    enum mtouch_sensor_names sensor;   
    
    for (sensor = 0; sensor < MTOUCH_SENSORS; sensor++)
    {
        if(MTOUCH_Sensor_wasSampled(sensor)==false && MTOUCH_Sensor_isEnabled(sensor))
        {   
            if(MTOUCH_Sensor_isSampling() == false)
                Sensor_scheduleNextScan();
            return false;
        }
    }
    
    Sensor_FrequencyHopping();
    
    return true;
}

/*
 * =======================================================================
 * MTOUCH_Sensor_Scan_Initialize
 * =======================================================================
 *  initialization for ADC and pin module for guard/Tx
 */
void MTOUCH_Sensor_Scan_Initialize(void)
{
    MTOUCH_Sensor_ADCC_Initialize();
    
}
    
    
/*
 * =======================================================================
 * Sensor_scheduleNextScan()
 * =======================================================================
 */
static void Sensor_scheduleNextScan(void)
{
    mtouch_sensor_t* sensor;
    bool skipScan = (bool)false;
    bool state = (bool)GIE;
    
    
    while(MTOUCH_Sensor_wasSampled(currentScanSensor) || !MTOUCH_Sensor_isEnabled(currentScanSensor))
    {
        if(++currentScanSensor == MTOUCH_SENSORS)
        {
            currentScanSensor = 0;
            sampling_flag = false;
            skipScan = true;                    /* finished one round of sensor scan */
            break;
        }
    }
    
    
    if(skipScan==false)
    {
        sensor = &mtouch_sensor[currentScanSensor];
        if(Sensor_isCalibrated(sensor))
        {
            ADACQ = (uint8_t)sensor->acquisition_time;
            ADPRE = (uint8_t)sensor->precharge_time;
        }
        else
        {
            if(Sensor_isCalibratingAcqTime(sensor))
            {
                ADPRE = (uint8_t)sensor->precharge_time;
                ADACQ = (uint8_t)sensor->acquisition_time;
            }
            else
            {
                ADPRE = MAX_PRECHARGE_TIME;
                ADACQ = MAX_ACQ_TIME;
            }
        }

        ADPRE +=(uint8_t)sample_delay;           /* apply additional delay for freq hopping */
        ADPCH = (uint8_t)sensor->adpch;
        ADRPT = (uint8_t)(sensor->oversampling>>1);
        ADCAP = (uint8_t)sensor->addcap;
        ADCON0bits.ADON = 1;
        sampling_flag= true;
        Sensor_SetTrisBit(currentScanSensor,1);
        GIE = 0;
        ADCON0bits.GO = 1;
        ADACC = Sensor_calculate_balance_point(sensor->oversampling);
        GIE = state;
        scanInterrupted = false;
    }
}

/*
 * 
 *=======================================================================
 * Automatic Sensor Calibration for internal capacitor and acquisition time
 *=======================================================================
 *
 */
static enum mtouch_sensor_error Sensor_autoCalibration(mtouch_sensor_t* sensor)
{
    enum mtouch_sensor_names name = sensor->sensor_name;
 
    if(!Sensor_isCalibratingAcqTime(sensor))                   /* Calibrating internal capacitor */
    {
        if(ADFLTR > Sensor_calculate_balance_point(sensor->oversampling))
        {
            if(++(sensor->addcap) >= ADD_CAP_LIMIT)
                Sensor_setCalibratAcqTime(sensor);
        }
        else
        {
             Sensor_setCalibratAcqTime(sensor);
        }
    }
    else                                                       /* Calibrating acquisition time */
    {
        if((mtouch_sensor_packetsample_t)abs(packet_sample[name] - ADFLTR) < Sensor_calculate_cal_thrs(sensor->oversampling))
        {
            sensor->precharge_time = MAX_PRECHARGE_TIME;
            Sensor_setCalibrated(sensor);
        }
        else
        {

            if((sensor->acquisition_time) >= (mtouch_sensor_time_t)(MAX_ACQ_TIME - DELAY_CYCLE(1)))
            {
                sensor->precharge_time = MAX_PRECHARGE_TIME;
                Sensor_setCalibrated(sensor);
            }
            else
            {
                sensor->acquisition_time += DELAY_CYCLE(1); 
            }
        }   
    }
    
    return MTOUCH_SENSOR_ERROR_none;
}

/*
 * =======================================================================
 * Sensor_postAcquisitionProcess()
 * =======================================================================
 * 
 */

static void Sensor_postAcquisitionProcess(enum mtouch_sensor_names name)
{
    mtouch_sensor_t* sensor = &mtouch_sensor[name];      
    
    if(Sensor_isEnabled(sensor))
    {
        if((mtouch_sensor_packetsample_t)abs(packet_sample[name] - sensor->rawSample) > Sensor_calculate_active_thrs(sensor->oversampling))
            Sensor_setActive(sensor);
        else
            Sensor_setInactive(sensor);
        
        Sensor_RawSample_Update(sensor);
        callback_sampled(name);
    }
    else
    {
        Sensor_setInactive(sensor);
    }
}

void MTOUCH_Sensor_ScanInterruptNotify(void)
{
    scanInterrupted = true;
}


void ADCC_ThresholdISR_mTouch(void)
{
    PIR1bits.ADTIF = 0;
    MTOUCH_Sensor_Service();
}

/*
 * =======================================================================
 * MTOUCH_Sensor_Service()
 * =======================================================================
 * This function is a callback of ADACC ADTIF interrupt service
 */
static inline void MTOUCH_Sensor_Service(void)
{
    mtouch_sensor_t* sensor;
    
    Sensor_SetTrisBit(currentScanSensor,0);
    
    if(scanInterrupted)
    {
        ADCON0bits.ADON = 0;
    }
    else
    {                  
        ADCON0bits.ADON = 0;
        sensor = &mtouch_sensor[currentScanSensor];
        if(!Sensor_isCalibrated(sensor))
        {
            Sensor_autoCalibration(sensor);
        }
        else
        {
            Sensor_setSampled(sensor); 
        }
        packet_sample[currentScanSensor] = ADFLTR;                   
    }
    Sensor_scheduleNextScan();
}
/*
 * =======================================================================
 * Sensor_setSamplePeriod()
 * =======================================================================
 * This function rotates the sensor scan frequency from the frequency pool 
 */
static void Sensor_setSamplePeriod(void)
{
    if(++freq_index >= sizeof(freq_hop) )
        freq_index = 0;    

    sample_delay = freq_hop[freq_index];     
}
/*
 * =======================================================================
 * Sensor Raw Sample
 * =======================================================================
 */ 
mtouch_sensor_sample_t MTOUCH_Sensor_RawSample_Get(enum mtouch_sensor_names name) /* Global */
{
    if (name < MTOUCH_SENSORS)
    {
        return mtouch_sensor[name].rawSample;
    }
    else
        return (mtouch_sensor_sample_t)0;
}

static void Sensor_RawSample_Update(mtouch_sensor_t* sensor) /* Local */
{
    mtouch_sensor_sample_t result = medianFilter(sensor->sensor_name);
    
    if (GIE == (uint8_t)1)
    {
        GIE = (uint8_t)0;
        sensor->rawSample = result;
        GIE = (uint8_t)1;
    }
    else
    {
        sensor->rawSample = result;
    }
}


static mtouch_sensor_packetsample_t medianFilter(enum mtouch_sensor_names sensor)
{
    static uint8_t bufferIndex[MTOUCH_SENSORS];
    
    sensor_medianBuffer[sensor][bufferIndex[sensor]++] = packet_sample[sensor];
    
    if(bufferIndex[sensor]>=3)
        bufferIndex[sensor] = 0;
    
    if(sensor_medianBuffer[sensor][0]>=sensor_medianBuffer[sensor][1])
    {
        if(sensor_medianBuffer[sensor][1]>=sensor_medianBuffer[sensor][2])
            return sensor_medianBuffer[sensor][1];
        else
        {   
            if(sensor_medianBuffer[sensor][0]>=sensor_medianBuffer[sensor][2])
                return sensor_medianBuffer[sensor][2];
            else
                return sensor_medianBuffer[sensor][0];
        }
            
    }
    else
    {   
        if(sensor_medianBuffer[sensor][0]>=sensor_medianBuffer[sensor][2])
            return sensor_medianBuffer[sensor][0];
        else
        {
            if(sensor_medianBuffer[sensor][1]>=sensor_medianBuffer[sensor][2])
                return sensor_medianBuffer[sensor][2];
            else
                return sensor_medianBuffer[sensor][1];
        }     
    }
}

static void Sensor_FrequencyHopping(void)
{
    enum mtouch_sensor_names sensor;
    
    Sensor_FrequencyHopping_Autotune_Process();
   
    for (sensor = 0; sensor < MTOUCH_SENSORS; sensor++)
    {
        Sensor_postAcquisitionProcess(sensor);
    }
    
    Sensor_setSamplePeriod();
}

/*
 *=========================================================================
 * AFA for ADCC
 *
 *=========================================================================
 */
static void Sensor_FrequencyHopping_Autotune_Process(void)
{
    enum mtouch_sensor_names sensor;
    uint8_t frequencyIndex;
    uint8_t newfrequencyFound,selectedFrequency;
    uint16_t variance,maxVariance;
    
    
    static uint8_t varianceOverLimitCounter[3] = {0,0,0};
    
    maxVariance = 0;
    
    for(sensor = 0; sensor < MTOUCH_SENSORS; sensor++)
    {
        variance = (mtouch_sensor_packetsample_t)abs(packet_sample[sensor] - sensor_medianBuffer[sensor][freq_index]);
        if(variance > maxVariance)
            maxVariance = variance;
    }
    
    if(maxVariance > FH_NOISE_THRS)
    {
        if(++varianceOverLimitCounter[freq_index] >= FH_OVERLIMIT_THRS)
        {
            newfrequencyFound = 0;
            selectedFrequency = freq_hop[freq_index];
            do
            {
                if(selectedFrequency>MTOUCH_SENSOR_SAMPLEDELAY_MIN)
                    selectedFrequency--;
                else
                    selectedFrequency = MTOUCH_SENSOR_SAMPLEDELAY_MAX;
                newfrequencyFound = 1;
                
                for(frequencyIndex = 0;frequencyIndex < sizeof(freq_hop);frequencyIndex++)
                {
                    if(frequencyIndex == freq_index)
                    {
                    
                    }
                    else if(selectedFrequency==freq_hop[frequencyIndex])
                    {
                        newfrequencyFound = 0;
                    }
                    else
                    {
                    
                    }
                }
                
            }while(!newfrequencyFound);
            
            freq_hop[freq_index] = selectedFrequency;
            
            for(frequencyIndex = 0;frequencyIndex < sizeof(freq_hop);frequencyIndex++)
            {
                varianceOverLimitCounter[frequencyIndex] = 0;
            }
        }
    }
    else if(maxVariance < (FH_NOISE_THRS >>1)) 
    {
        /* Max variance less than half limit - decrement auto-tune counter if non-zero */
        if(varianceOverLimitCounter[freq_index] > 0)
            varianceOverLimitCounter[freq_index]--;
    }
    else
    {
        /* Keep this frequency */
    }
}

/*
 * =======================================================================
 * Sensor Sampled Callback
 * =======================================================================
 */ 
static void Sensor_DefaultCallback(enum mtouch_sensor_names sensor) { }
void MTOUCH_Sensor_SetSampledCallback(void (*callback)(enum mtouch_sensor_names sensor))
{
    callback_sampled = callback;
}



/*
 * =======================================================================
 *  Enable/Disable Sensor
 * =======================================================================
 * 
 */
void MTOUCH_Sensor_Disable(enum mtouch_sensor_names sensor)
{
    if(sensor < MTOUCH_SENSORS)   
        mtouch_sensor[sensor].enabled = 0;
}

void MTOUCH_Sensor_Enable(enum mtouch_sensor_names sensor)
{
    if(sensor < MTOUCH_SENSORS)   
        mtouch_sensor[sensor].enabled = 1;
}

bool MTOUCH_Sensor_isEnabled(enum mtouch_sensor_names sensor)
{
    if(sensor < MTOUCH_SENSORS)   
        return (bool)mtouch_sensor[sensor].enabled;
    else
        return false;
}

static bool Sensor_isEnabled(mtouch_sensor_t* sensor)
{
    if(sensor!=NULL)
        return (bool)sensor->enabled;
    else
        return false;
}

/*
 * =======================================================================
 *  Sensor active status
 * =======================================================================
 * 
 */

static inline void Sensor_setActive(mtouch_sensor_t* sensor)
{
    sensor->acitve = 1;
}

static inline void Sensor_setInactive(mtouch_sensor_t* sensor)
{
    sensor->acitve = 0;
}

bool MTOUCH_Sensor_isActive(enum mtouch_sensor_names sensor)
{
    if(sensor<=MTOUCH_SENSORS)
        return (bool)mtouch_sensor[sensor].acitve;
    return false;
}

/*
 * =======================================================================
 *  Sensor calibrate status
 * =======================================================================
 * 
 */

void MTOUCH_Sensor_Calibrate(enum mtouch_sensor_names sensor)
{
    if(sensor < MTOUCH_SENSORS)
    {
        mtouch_sensor[sensor].calibrated = 0;
    }
}

bool MTOUCH_Sensor_isCalibrated(enum mtouch_sensor_names sensor)
{
    if(sensor < MTOUCH_SENSORS)
        return (bool)mtouch_sensor[sensor].calibrated;
    else
        return false;
}

static inline bool Sensor_isCalibrated(mtouch_sensor_t* sensor)
{
    return (bool)sensor->calibrated;
}

static inline void Sensor_setCalibrated(mtouch_sensor_t* sensor)
{
    sensor->calibrated = 1;
    sensor->acqTime_cal = 0;
}

static inline void Sensor_setCalibratAcqTime(mtouch_sensor_t* sensor)
{
    sensor->acqTime_cal = 1;
    sensor->acquisition_time = MIN_ACQ_TIME;
    sensor->precharge_time = MAX_PRECHARGE_TIME;
}

static inline bool Sensor_isCalibratingAcqTime(mtouch_sensor_t* sensor)
{
    return (bool)sensor->acqTime_cal;

}

/*
 * =======================================================================
 *  Sensor sample status
 * =======================================================================
 * 
 */

void MTOUCH_Sensor_Sampled_ResetAll(void)
{
    mtouch_sensor_t* sensor;
    for(sensor = &mtouch_sensor[0];sensor<= &mtouch_sensor[MTOUCH_SENSORS-1];sensor++)
    {      
        Sensor_Sampled_Reset(sensor);
    }
}

bool MTOUCH_Sensor_wasSampled(enum mtouch_sensor_names sensor) 
{
    if(sensor < MTOUCH_SENSORS)
        return (bool)mtouch_sensor[sensor].sampled;
    else
        return false;
}

static inline void Sensor_Sampled_Reset(mtouch_sensor_t* sensor) 
{
    sensor->sampled = 0;
}

static inline void Sensor_setSampled(mtouch_sensor_t* sensor) 
{
    sensor->sampled = 1;
}

bool MTOUCH_Sensor_isSampling(void)
{
    return sampling_flag;
}

/*
 * =======================================================================
 *  Sensor calibration values
 * =======================================================================
 * 
 */
uint8_t MTOUCH_Sensor_AdditionalCap_Get(enum mtouch_sensor_names name) 
{
    if(name < MTOUCH_SENSORS)
       return (uint8_t)mtouch_sensor[name].addcap;      
    else
       return 0;
}

uint8_t MTOUCH_Sensor_AcquisitionTime_Get(enum mtouch_sensor_names name) 
{
     if(name < MTOUCH_SENSORS)
        return (uint8_t)(mtouch_sensor[name].acquisition_time >> DELAY_SCALER);
     else
        return 0;
}

uint8_t MTOUCH_Sensor_PreChargeTime_Get(enum mtouch_sensor_names name) 
{
    if(name < MTOUCH_SENSORS)
       return (uint8_t)(mtouch_sensor[name].precharge_time >> DELAY_SCALER);
    else
       return 0;
}