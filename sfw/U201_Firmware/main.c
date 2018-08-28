/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF67K40
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <xc.h>

#include "ring_buffer_interface.h"

// Buffer ready to dump flag
extern volatile uint8_t eusart2RxStringReady;

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Tell terminal we're booted
    printResetMessage();
    
    while (1)
    {
        // Check to see if we've got received instructions waiting from USB debug
        if (eusart2RxStringReady) {
            ringBufferPull();
        }
        
        // Service the mTouch API
        MTOUCH_Service_Mainloop();
        
        // Act on buttons presses, light LED if button is pressed
        LATFbits.LATF0 = ~MTOUCH_Button_State_Get(Button0);
        LATFbits.LATF1 = ~MTOUCH_Button_State_Get(Button1);
        LATFbits.LATF2 = ~MTOUCH_Button_State_Get(Button2);
        LATFbits.LATF3 = ~MTOUCH_Button_State_Get(Button3);
        LATFbits.LATF4 = ~MTOUCH_Button_State_Get(Button4);
        
        // print button state if pressed
        if(MTOUCH_Button_State_Get(Button0)) {
            printf("    Button0 pressed\n\r");
        }
        
        if(MTOUCH_Button_State_Get(Button1)) {
            printf("    Button1 pressed\n\r");   
        }
        
        if(MTOUCH_Button_State_Get(Button2)) {
            printf("    Button2 pressed\n\r");
        }
        
        if(MTOUCH_Button_State_Get(Button3)) {
            printf("    Button3 pressed\n\r");
        }
        
        if(MTOUCH_Button_State_Get(Button4)) {
            printf("    Button4 pressed\n\r");
        }
        
        
        
        // Twiddle thumbs
        NOP();
        
    }
}
/**
 End of File
*/