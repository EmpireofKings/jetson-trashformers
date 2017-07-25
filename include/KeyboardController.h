#ifndef KEYBOARDCONTROLLER_H_ 
#define KEYBOARDCONTROLLER_H_

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <termios.h>
#include "Controls.h"

#include "ZigbController.h"

/**
 * Allows for human input to send zigb commands 
 * through live input via console. WASD for movement etc..
 * See cpp file for all controls
 * 
 */

class KeyboardController{
    public:
        /**
         * Constructor for KeyboardController:
         * Takes an instance of ZigController
         */
        KeyboardController(ZigbController* zigb);
        virtual ~KeyboardController();

        /**
         * Sets up console for live input
         */    
        void Init();

        /**
         * Runs a while loop to read input and send zigb commonds.
         * (NOTE: THIS DOES NOT CREATE A SEPERATE THREAD)
         */
        void RunInput();

        /**
         * Disables live console input
         */
        void Terminate();


    private:
        ZigbController *zigb;
        struct termios old_tio, new_tio;
        unsigned char c;

};

#endif //KEYBOARDCONTROLLER_H_
