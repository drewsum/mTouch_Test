
#include <string.h>
#include <ctype.h>

#include "ring_buffer_LUT.h"

#include "mcc_generated_files/mtouch/mtouch_button.h"

void ringBufferLUT(char * line) {
 
    // THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
    // ACT ON IT

    if (USB_DTR == 1) {
    
        // If we receive the string 'LED On'
        if((0 == strcmp(line, "LEDs On"))) {

            // Set RD0
            LATF = 0x00;

            // Get some space on terminal
            printf("\n\r");

            printf("    LATF = 0x00\n\r");

            // Get some space on terminal
            printf("\n\r");

        }


        // Else if we've received LED Off
        else if((0 == strcmp(line, "LEDs Off"))) {

            // Clear RD0
            LATF = 0xFF;

            // Get some space on terminal
            printf("\n\r");

            printf("    LATF = 0xFF\n\r");

            // Get some space on terminal
            printf("\n\r");

        }

        // Return state of all mTouch pushbuttons
        else if((0 == strcmp(line, "Button States?"))) {

            // Get some space on terminal
            printf("\n\r");

            // Print state of buttons
            printf("    Button 0: %d\n\r", MTOUCH_Button_isPressed(Button0));
            printf("    Button 1: %d\n\r", MTOUCH_Button_isPressed(Button1));
            printf("    Button 2: %d\n\r", MTOUCH_Button_isPressed(Button2));
            printf("    Button 3: %d\n\r", MTOUCH_Button_isPressed(Button3));
            printf("    Button 4: %d\n\r", MTOUCH_Button_isPressed(Button4));

            // Get some space on terminal
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

        // Clear screen, don't reset
        else if((0 == strcmp(line, "Clear"))) {

            // Clear the screen
            printf("\033[2J");

            // Move cursor to home
            printf("\033[H");

        }

        // Identification string
        else if((0 == strcmp(line, "*IDN?")) || (0 == strcmp(line, "IDN"))) {

                   // Get some space on terminal
            printf("\n\r"); 

            // Tell term who we are
            printf("    mTouch Test Board, REVA");

            // Get some space on terminal
            printf("\n\r");

        }

        // help, print options
        else if((0 == strcmp(line, "Help"))) {

            // Get some space on terminal
            printf("\n\r");
            // Print help message
            printf("   List of supported commands:\n\r"
                    "   LEDs On: Turns all LEDs On\n\r"
                    "   LEDs Off: Turns all LEDs Off\n\r"
                    "   Button States?: Returns state of all five mTouch buttons\n\r"
                    "   Reset: Clears the terminal and resets the micro\n\r"
                    "   Clear: Clears the terminal but doesn't reset the micro\n\r"
                    "   *IDN?: Returns device identification\n\r"
                    "   Help: This message, lists commands\n\r");

            // Get some space on terminal
            printf("\n\r");

        }

    }
    
}
