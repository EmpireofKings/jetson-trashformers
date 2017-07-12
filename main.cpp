#include "include/Humanoid.h"
#include "include/BehaviorController.h"
#include <iostream>
#include <thread>

int main (int argc, char** argv){
    Humanoid* humanoid = new Humanoid(argc, argv);
    int inputChar; 
    

    humanoid->arm->SetClaw(610, 1023);
       
    //Send STOP command to init zigbeecontroller
    humanoid->behaviorController->ChangeState(BehaviorController::ControllerState::STOP);

    //humanoid->detectnetController->JoinDetectThread();
    printf("Exiting..");

    return 0;
}
