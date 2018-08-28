/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF67K40
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RE2 procedures
#define RE2_SetHigh()               do { LATEbits.LATE2 = 1; } while(0)
#define RE2_SetLow()                do { LATEbits.LATE2 = 0; } while(0)
#define RE2_Toggle()                do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define RE2_GetValue()              PORTEbits.RE2
#define RE2_SetDigitalInput()       do { TRISEbits.TRISE2 = 1; } while(0)
#define RE2_SetDigitalOutput()      do { TRISEbits.TRISE2 = 0; } while(0)
#define RE2_SetPullup()             do { WPUEbits.WPUE2 = 1; } while(0)
#define RE2_ResetPullup()           do { WPUEbits.WPUE2 = 0; } while(0)
#define RE2_SetAnalogMode()         do { ANSELEbits.ANSELE2 = 1; } while(0)
#define RE2_SetDigitalMode()        do { ANSELEbits.ANSELE2 = 0; } while(0)

// get/set RE3 procedures
#define RE3_SetHigh()               do { LATEbits.LATE3 = 1; } while(0)
#define RE3_SetLow()                do { LATEbits.LATE3 = 0; } while(0)
#define RE3_Toggle()                do { LATEbits.LATE3 = ~LATEbits.LATE3; } while(0)
#define RE3_GetValue()              PORTEbits.RE3
#define RE3_SetDigitalInput()       do { TRISEbits.TRISE3 = 1; } while(0)
#define RE3_SetDigitalOutput()      do { TRISEbits.TRISE3 = 0; } while(0)
#define RE3_SetPullup()             do { WPUEbits.WPUE3 = 1; } while(0)
#define RE3_ResetPullup()           do { WPUEbits.WPUE3 = 0; } while(0)
#define RE3_SetAnalogMode()         do { ANSELEbits.ANSELE3 = 1; } while(0)
#define RE3_SetDigitalMode()        do { ANSELEbits.ANSELE3 = 0; } while(0)

// get/set RE4 procedures
#define RE4_SetHigh()               do { LATEbits.LATE4 = 1; } while(0)
#define RE4_SetLow()                do { LATEbits.LATE4 = 0; } while(0)
#define RE4_Toggle()                do { LATEbits.LATE4 = ~LATEbits.LATE4; } while(0)
#define RE4_GetValue()              PORTEbits.RE4
#define RE4_SetDigitalInput()       do { TRISEbits.TRISE4 = 1; } while(0)
#define RE4_SetDigitalOutput()      do { TRISEbits.TRISE4 = 0; } while(0)
#define RE4_SetPullup()             do { WPUEbits.WPUE4 = 1; } while(0)
#define RE4_ResetPullup()           do { WPUEbits.WPUE4 = 0; } while(0)
#define RE4_SetAnalogMode()         do { ANSELEbits.ANSELE4 = 1; } while(0)
#define RE4_SetDigitalMode()        do { ANSELEbits.ANSELE4 = 0; } while(0)

// get/set RE5 procedures
#define RE5_SetHigh()               do { LATEbits.LATE5 = 1; } while(0)
#define RE5_SetLow()                do { LATEbits.LATE5 = 0; } while(0)
#define RE5_Toggle()                do { LATEbits.LATE5 = ~LATEbits.LATE5; } while(0)
#define RE5_GetValue()              PORTEbits.RE5
#define RE5_SetDigitalInput()       do { TRISEbits.TRISE5 = 1; } while(0)
#define RE5_SetDigitalOutput()      do { TRISEbits.TRISE5 = 0; } while(0)
#define RE5_SetPullup()             do { WPUEbits.WPUE5 = 1; } while(0)
#define RE5_ResetPullup()           do { WPUEbits.WPUE5 = 0; } while(0)
#define RE5_SetAnalogMode()         do { ANSELEbits.ANSELE5 = 1; } while(0)
#define RE5_SetDigitalMode()        do { ANSELEbits.ANSELE5 = 0; } while(0)

// get/set RE6 procedures
#define RE6_SetHigh()               do { LATEbits.LATE6 = 1; } while(0)
#define RE6_SetLow()                do { LATEbits.LATE6 = 0; } while(0)
#define RE6_Toggle()                do { LATEbits.LATE6 = ~LATEbits.LATE6; } while(0)
#define RE6_GetValue()              PORTEbits.RE6
#define RE6_SetDigitalInput()       do { TRISEbits.TRISE6 = 1; } while(0)
#define RE6_SetDigitalOutput()      do { TRISEbits.TRISE6 = 0; } while(0)
#define RE6_SetPullup()             do { WPUEbits.WPUE6 = 1; } while(0)
#define RE6_ResetPullup()           do { WPUEbits.WPUE6 = 0; } while(0)
#define RE6_SetAnalogMode()         do { ANSELEbits.ANSELE6 = 1; } while(0)
#define RE6_SetDigitalMode()        do { ANSELEbits.ANSELE6 = 0; } while(0)

// get/set IO_RF0 aliases
#define IO_RF0_TRIS                 TRISFbits.TRISF0
#define IO_RF0_LAT                  LATFbits.LATF0
#define IO_RF0_PORT                 PORTFbits.RF0
#define IO_RF0_WPU                  WPUFbits.WPUF0
#define IO_RF0_OD                   ODCONFbits.ODCF0
#define IO_RF0_ANS                  ANSELFbits.ANSELF0
#define IO_RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define IO_RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define IO_RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define IO_RF0_GetValue()           PORTFbits.RF0
#define IO_RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define IO_RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define IO_RF0_SetPullup()          do { WPUFbits.WPUF0 = 1; } while(0)
#define IO_RF0_ResetPullup()        do { WPUFbits.WPUF0 = 0; } while(0)
#define IO_RF0_SetPushPull()        do { ODCONFbits.ODCF0 = 0; } while(0)
#define IO_RF0_SetOpenDrain()       do { ODCONFbits.ODCF0 = 1; } while(0)
#define IO_RF0_SetAnalogMode()      do { ANSELFbits.ANSELF0 = 1; } while(0)
#define IO_RF0_SetDigitalMode()     do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set IO_RF1 aliases
#define IO_RF1_TRIS                 TRISFbits.TRISF1
#define IO_RF1_LAT                  LATFbits.LATF1
#define IO_RF1_PORT                 PORTFbits.RF1
#define IO_RF1_WPU                  WPUFbits.WPUF1
#define IO_RF1_OD                   ODCONFbits.ODCF1
#define IO_RF1_ANS                  ANSELFbits.ANSELF1
#define IO_RF1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define IO_RF1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define IO_RF1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define IO_RF1_GetValue()           PORTFbits.RF1
#define IO_RF1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define IO_RF1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define IO_RF1_SetPullup()          do { WPUFbits.WPUF1 = 1; } while(0)
#define IO_RF1_ResetPullup()        do { WPUFbits.WPUF1 = 0; } while(0)
#define IO_RF1_SetPushPull()        do { ODCONFbits.ODCF1 = 0; } while(0)
#define IO_RF1_SetOpenDrain()       do { ODCONFbits.ODCF1 = 1; } while(0)
#define IO_RF1_SetAnalogMode()      do { ANSELFbits.ANSELF1 = 1; } while(0)
#define IO_RF1_SetDigitalMode()     do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set IO_RF2 aliases
#define IO_RF2_TRIS                 TRISFbits.TRISF2
#define IO_RF2_LAT                  LATFbits.LATF2
#define IO_RF2_PORT                 PORTFbits.RF2
#define IO_RF2_WPU                  WPUFbits.WPUF2
#define IO_RF2_OD                   ODCONFbits.ODCF2
#define IO_RF2_ANS                  ANSELFbits.ANSELF2
#define IO_RF2_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define IO_RF2_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define IO_RF2_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define IO_RF2_GetValue()           PORTFbits.RF2
#define IO_RF2_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define IO_RF2_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define IO_RF2_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define IO_RF2_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define IO_RF2_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define IO_RF2_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define IO_RF2_SetAnalogMode()      do { ANSELFbits.ANSELF2 = 1; } while(0)
#define IO_RF2_SetDigitalMode()     do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set IO_RF3 aliases
#define IO_RF3_TRIS                 TRISFbits.TRISF3
#define IO_RF3_LAT                  LATFbits.LATF3
#define IO_RF3_PORT                 PORTFbits.RF3
#define IO_RF3_WPU                  WPUFbits.WPUF3
#define IO_RF3_OD                   ODCONFbits.ODCF3
#define IO_RF3_ANS                  ANSELFbits.ANSELF3
#define IO_RF3_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define IO_RF3_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define IO_RF3_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define IO_RF3_GetValue()           PORTFbits.RF3
#define IO_RF3_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define IO_RF3_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define IO_RF3_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define IO_RF3_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define IO_RF3_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define IO_RF3_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define IO_RF3_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define IO_RF3_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

// get/set IO_RF4 aliases
#define IO_RF4_TRIS                 TRISFbits.TRISF4
#define IO_RF4_LAT                  LATFbits.LATF4
#define IO_RF4_PORT                 PORTFbits.RF4
#define IO_RF4_WPU                  WPUFbits.WPUF4
#define IO_RF4_OD                   ODCONFbits.ODCF4
#define IO_RF4_ANS                  ANSELFbits.ANSELF4
#define IO_RF4_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define IO_RF4_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define IO_RF4_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define IO_RF4_GetValue()           PORTFbits.RF4
#define IO_RF4_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define IO_RF4_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define IO_RF4_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define IO_RF4_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define IO_RF4_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define IO_RF4_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define IO_RF4_SetAnalogMode()      do { ANSELFbits.ANSELF4 = 1; } while(0)
#define IO_RF4_SetDigitalMode()     do { ANSELFbits.ANSELF4 = 0; } while(0)

// get/set RG6 procedures
#define RG6_SetHigh()               do { LATGbits.LATG6 = 1; } while(0)
#define RG6_SetLow()                do { LATGbits.LATG6 = 0; } while(0)
#define RG6_Toggle()                do { LATGbits.LATG6 = ~LATGbits.LATG6; } while(0)
#define RG6_GetValue()              PORTGbits.RG6
#define RG6_SetDigitalInput()       do { TRISGbits.TRISG6 = 1; } while(0)
#define RG6_SetDigitalOutput()      do { TRISGbits.TRISG6 = 0; } while(0)
#define RG6_SetPullup()             do { WPUGbits.WPUG6 = 1; } while(0)
#define RG6_ResetPullup()           do { WPUGbits.WPUG6 = 0; } while(0)
#define RG6_SetAnalogMode()         do { ANSELGbits.ANSELG6 = 1; } while(0)
#define RG6_SetDigitalMode()        do { ANSELGbits.ANSELG6 = 0; } while(0)

// get/set RG7 procedures
#define RG7_SetHigh()               do { LATGbits.LATG7 = 1; } while(0)
#define RG7_SetLow()                do { LATGbits.LATG7 = 0; } while(0)
#define RG7_Toggle()                do { LATGbits.LATG7 = ~LATGbits.LATG7; } while(0)
#define RG7_GetValue()              PORTGbits.RG7
#define RG7_SetDigitalInput()       do { TRISGbits.TRISG7 = 1; } while(0)
#define RG7_SetDigitalOutput()      do { TRISGbits.TRISG7 = 0; } while(0)
#define RG7_SetPullup()             do { WPUGbits.WPUG7 = 1; } while(0)
#define RG7_ResetPullup()           do { WPUGbits.WPUG7 = 0; } while(0)
#define RG7_SetAnalogMode()         do { ANSELGbits.ANSELG7 = 1; } while(0)
#define RG7_SetDigitalMode()        do { ANSELGbits.ANSELG7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/