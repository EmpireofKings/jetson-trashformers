#include "Humanoid.h"

Humanoid::Humanoid() { //CONSTRUCTOR

    printf("Created Humanoid \n");

}

Humanoid::~Humanoid() {

}

double Humanoid::GetCupCenterX(){
    return 0.0;
}

double Humanoid::GetCupCenterY(){
    return 0.0;
}

void Humanoid::WalkForward(){

}

void Humanoid::Stop(){

}

int main( int argc, char** argv ){
    Humanoid *humanoid = new Humanoid();
    runDetectNet(argc, argv);
    return 0;
}
