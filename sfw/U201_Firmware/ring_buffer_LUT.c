
#include <string.h>
#include <ctype.h>

#include "ring_buffer_LUT.h"

void ringBufferLUT(char * line) {
 
    // THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
    // ACT ON IT

    // If we receive the string 'LED On'
    if((0 == strcmp(line, "LED On"))) {

        // Set RD0
        LATCbits.LATC7 = 1;
        
        // Get some space on terminal
        printf("\n\r");
        
        printf("    RC7 Set\n\r");
   
        // Get some space on terminal
        printf("\n\r");
        
    }
    

    // Else if we've received LED Off
    else if((0 == strcmp(line, "LED Off"))) {

        // Clear RD0
        LATCbits.LATC7 = 0;
        
        // Get some space on terminal
        printf("\n\r");
        
        printf("    RC7 Cleared\n\r");

        // Get some space on terminal
        printf("\n\r");
        
    }

    // Else if we've received Talk to me, say a bunch of stuff back
    else if ((0 == strcmp(line, "Talk to me"))) {

        // Get some space on terminal
        printf("\n\r");
        
        printf("    Well, I've got a lot to talk about...\n\r");
        printf("    First thing's first, I'm talking to you through a "
                "UART to USB bridge, produced by FTDI\n\r");
        printf("    The part number is FT232\n\r");
        printf("    I'm a PIC18F67K40, and I don't know my revision number yet\r\n");

        // Get some space on terminal
        printf("\n\r");
        
    }
    
    
    // Else if we've received Add, parse and add all arguments
    else if ((line[0] == (int) 'A') &&
            (line[1] == (int) 'd') &&
            (line[2] == (int) 'd')) {
        
        // find how many numbers we have to add
        int num_arguments = 0;
        
        // Sum of all arguments to add
        float sum = 0.0;
        
        // loop through all of line to find number of ints to add
        for (int index = 0; index < strlen(line); index++) {
         
            // If we find a space (each arg needs a space)
            if((int) line[index] == 32) {
            
                num_arguments++;
                
            }
            
        }
        
        ////////////////////////////////////////////////////////////////////////
        // Where we currently are in line, start at 4 to pass "Add "
        int line_index = 4;
        
        
        // The current argument represented as a string
        char arg_str[64];
        
        // The start of the previous argument
        int last_arg_start;
        
        // Flag to tell if int or float
        uint8_t float_flag = 0;
        
        // Loop through arguments, adding to sum
        for (int arg_index = 0; arg_index < num_arguments; arg_index++) {
            
            last_arg_start = line_index;
            
            // pull out the argument in this pass
            while(isdigit(line[line_index]) || 
                    line[line_index] == (int) '-' || 
                    line[line_index] == (int)'.') {

                // Manually make string of argument from line
                arg_str[line_index - last_arg_start] = line[line_index];

                // move forward in line
                line_index++;
                
                // If we've found a decimal point, it's a float
                if(line[line_index] == (int)'.') {
                 
                    float_flag = 1;
                    
                }
                 
            }
            
            // Skip the space previous to the current argument
            line_index++;
            
            // End at last digit of argument
            arg_str[line_index - last_arg_start - 1] = '\0';
            
            // Start from here next time
            last_arg_start = line_index;

            // If it's a float, do float conversion
            if (float_flag == 0) {
             
                // convert to int and tack on to sum
                sum += atof(arg_str);
                
            }
            
            // If it's an int, do int conversion
            else {
             
                // convert to int and tack on to sum
                sum += atoi(arg_str);
                
            }
            
        }
        
        // print result
        printf("\n\r");
        printf("    The sum of all arguments entered is %f\n\r", sum);
        printf("\n\r");
        
    }
    
    // Else if we've received Add, parse and add all arguments
    else if ((line[0] == (int) 'M') &&
            (line[1] == (int) 'u') &&
            (line[2] == (int) 'l') &&
            (line[3] == (int) 't')) {
        
        // find how many numbers we have to add
        int num_arguments = 0;
        
        // product of all arguments to add
        long long prod = 1;
        
        // loop through all of line to find number of ints to add
        for (int index = 0; index < strlen(line); index++) {
         
            // If we find a space (each arg needs a space)
            if((int) line[index] == 32) {
            
                num_arguments++;
                
            }
            
        }
        
        ////////////////////////////////////////////////////////////////////////
        // Where we currently are in line, start at 4 to pass "Add "
        int line_index = 5;
        
        
        // The current argument represented as a string
        char arg_str[64];
        
        // The start of the previous argument
        int last_arg_start;
        
        // Loop through arguments, adding to sum
        for (int arg_index = 0; arg_index < num_arguments; arg_index++) {
            
            last_arg_start = line_index;
            
            // pull out the argument in this pass
            while(isdigit(line[line_index]) || line[line_index] == (int) '-') {

                // Manually make string of argument from line
                arg_str[line_index - last_arg_start] = line[line_index];

                // move forward in line
                line_index++;

            }
            
            // Skip the space previous to the current argument
            line_index++;
            
            // End at last digit of argument
            arg_str[line_index - last_arg_start - 1] = '\0';
            
            // Start from here next time
            last_arg_start = line_index;

            // convert to int and tack on to sum
            prod *= atoi(arg_str);
            
        }
        
        // print result
        printf("\n\r");
        printf("    The product of all arguments entered is %d\n\r", prod);
        printf("\n\r");
        
    }
    
    

    // Clear Screen, reset
    else if((0 == strcmp(line, "Reset"))) {
        
        // Clear the screen
        printf("\033[2J");

        // Move cursor to home
        printf("\033[H");
        
        // Reset
        RESET();

    }
    
    // help, print options
    else if((0 == strcmp(line, "Help"))) {
     
        // Get some space on terminal
        printf("\n\r");
        // Print help message
        printf("   List of supported commands so far:\n\r"
                "   LED On: Turns LED On\n\r"
                "   LED Off: Turns LED Off\n\r"
                "   Talk to me: Spews a bunch out\n\r"
                "   Add: Adds all arguments following command\n\r"
                "   Multiply: Multiplies all arguments\n\r"
                
                "   Reset: Clears the screen and resets the micro\n\r"
                
                "   Help: This message, lists commands\n\r");
        
        // Get some space on terminal
        printf("\n\r");
        
    }
    
    
}
