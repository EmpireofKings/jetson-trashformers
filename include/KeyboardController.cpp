#include "KeyboardController.h"

KeyboardController::KeyboardController(ZigbController* zigb) { //CONSTRUCTOR
    this->zigb = zigb;
}


void KeyboardController::Init(){
    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

}

void KeyboardController::RunInput(){
    while(true){
        c = getchar();
        //printf("%d \n", c);
        
        if(c == ' '){
            printf("Stopping!\n");
            zigb->Stop(); 
        }
        else if(c == 'w'){
            printf("Forward!\n");
            zigb->SendCommand(BUTTON_WALK_FORWARD);
        }
        else if(c == 's'){
            printf("Back!\n");
            zigb->SendCommand(BUTTON_WALK_BACKWARD);
        }
        else if(c == 'a'){
            printf("Left!\n");
            zigb->SendCommand(BUTTON_TURN_LEFT);
        }
        else if(c == 'd'){
            printf("Right!\n");
            zigb->SendCommand(BUTTON_TURN_RIGHT);
        }
    }
}

void KeyboardController::Terminate(){
    //turn off immediate console buffering
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
}

KeyboardController::~KeyboardController() {

}