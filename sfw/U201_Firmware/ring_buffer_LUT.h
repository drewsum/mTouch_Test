/* 
 * File:   ring_buffer_LUT.h
 * Author: Drew Maatman
 *
 * Created on January 17, 2018, 8:00 PM
 */

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <xc.h>

#ifndef RING_BUFFER_LUT_H
#define	RING_BUFFER_LUT_H

#ifdef	__cplusplus
extern "C" {
#endif
   
// Bit that states if USB is active or not
extern volatile bit USB_DTR;
    
/*
  @Summary
    This routine compares the string passed to it and acts on it if it matches
    any of the strings entered. This is how commands should be programmed.

  @Description
    

  @Preconditions
    Having an MCC generated UART driver, and adding the stuff listed below
    Some variables in this file should be edited to use correct EUSART module
    if there are multiple modules within the microcontroller being used

  @Param
    Pointer to a string to be checked and acted on

  @Returns
    None

  @Comment
    

  @Example

*/
void ringBufferLUT(char * line);




#ifdef	__cplusplus
}
#endif

#endif	/* RING_BUFFER_LUT_H */

