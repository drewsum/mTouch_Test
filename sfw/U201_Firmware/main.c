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
extern volatile bit eusart2RxStringReady;

// Bit that states if USB is active or not
volatile bit USB_DTR = 0;

// Callback function for USB_DTR
void DTR_Callback(void) {
 
    if(PORTBbits.RB2 == 1) {
        USB_DTR = 1;
    }
    
    else {
        USB_DTR = 0;
    }
    
}

// Function called upon any button press
void mTouchCallback(void) {
    
    if (MTOUCH_Button_isPressed(Button0)) {
        LATFbits.LATF0 = !LATFbits.LATF0;
        printf("    Button 0 has been pressed\n\r");
    }
    
    if (MTOUCH_Button_isPressed(Button1)) {
        LATFbits.LATF1 = !LATFbits.LATF1;
        printf("    Button 1 has been pressed\n\r");
    }
    
    if (MTOUCH_Button_isPressed(Button2)) {
        LATFbits.LATF2 = !LATFbits.LATF2;
        printf("    Button 2 has been pressed\n\r");
    }
    
    if (MTOUCH_Button_isPressed(Button3)) {
        LATFbits.LATF3 = !LATFbits.LATF3;
        printf("    Button 3 has been pressed\n\r");
    }
    
    if (MTOUCH_Button_isPressed(Button4)) {
        LATFbits.LATF4 = !LATFbits.LATF4;
        printf("    Button 4 has been pressed\n\r");
        
    }
    
}

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // Set callback for USB_DTR
    IOCBF2_SetInterruptHandler(DTR_Callback);
    
    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Set Button callback functions
    MTOUCH_Button_SetPressedCallback(mTouchCallback);
    
    // Check if terminal is available on boot
    DTR_Callback();
    
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
        
        // Twiddle thumbs
        NOP();
        
    }
}
/**
 End of File
*/