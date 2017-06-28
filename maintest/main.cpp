#include <stdio.h>
#include "/home/nvidia/jetson-inference/detectnet-camera/detectnet-camera.h"

int main(int argc, char** argv) {
    runDetectNet(argc, argv); 
    printf("Success!\n");
}
