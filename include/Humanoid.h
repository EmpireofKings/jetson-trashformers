#ifndef SEPERATE_H_
#define SEPERATE_H_

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

