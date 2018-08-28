


#include "ring_buffer_interface.h"



void ringBufferPull(void) {

    int charNumber = eusart2RxCount;
            
    // Clear line buffer
    for (int index = 0; index < EUSART_2_RX_BUFFER_SIZE; index++) {

        line[index] = '\0';

    }

    // Fill line from ring buffer
    for(int index = 0; index < charNumber; index++){

        line[index] = EUSART2_Read();

    }

    // Reset ring buffer
    eusart2RxTail = eusart2RxHead;

    // Try to kill off ending returns/newlines
    while((line[strlen(line) - 1] == (int) '\n') ||
          (line[strlen(line) - 1] == (int) '\r')) {
     
        // NULL
        line[strlen(line) - 1] = '\0';
        
    }
    

    // Clear ready flag
    eusart2RxStringReady = 0;

    // Check to see if line matches a command
    ringBufferLUT(line);

    
}

// This message is printed to the terminal on reset of microcontroller
// Can be left blank
void printResetMessage(void) {
 
    // Clear the screen
    printf("\033[2J");
    
    // Move cursor to home
    printf("\033[H");
    
    // Tell terminal we're up and running
    printf("PIC18F67K40 mTouch Demo\n\r"
            "Baud rate: 115200 kbps\n\r"
            "No parity, 8 bits, no flow control, 1 stop bit\n\r"
            "Commands are case sensitive\n\r"
            "Enter a command, or Help for list of commands\n\r");
            
    
    // Get some space on terminal
    printf("\n\r");
    
}
