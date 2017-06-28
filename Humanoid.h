#ifndef HUMANOID_H_ 
#define HUMANOID_H_

#include "/home/nvidia/jetson-inference/detectnet-camera/detectnet-camera.h"
#include <stdio.h>

class Humanoid {
    public:
        Humanoid();
        virtual ~Humanoid();
        
        double GetCupCenterY();
        double GetCupCenterX();

        void WalkForward();
        void Stop();

    private:
        
};

#endif

