#ifndef DETECTNETCONTROLLER_H_
#define DETECTNETCONTROLLER_H_

#include <stdio.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <string>
#include "../util/detectnet-camera.h"

/**
 * Class to interface with a modified version of detectnet-camera.cpp
 * from jetson-inference by Dustin Franklin of NVIDIA. The modified version
 * can be found in ../util
 * 
 * DetectNetController access data from detectnet-camera such as an array
 * bounding box information and class IDs for each detect object.
 */
class DetectNetController {
    public:
        /**
         * Constructor for DetectNetController:
         *
         * Takes a model numer, camera port, and runs a thread which 
         * runs the main loop of detectnet-camera.cpp 
         */
        DetectNetController(int camPort, std::string model);
        virtual ~DetectNetController();

        /**
         * Reads the current unsorted bbarray from detectnet-camera
         * and returns an array that has been sorted based on 
         * distance from the camera's center
         */
        std::vector<std::array<float, 5>> SortBBArrayByTargetDistance();

        /**
         * Array that stores the sorted bb information 
         * Structure of each array: (x1, y1, x2, y2, classID)
         */
        std::vector<std::array<float, 5>> bbArraySorted;

        /**
         * If run in the main loop, this will complete the detectnet thread
         * and then continue the main loop. 
         */
        void JoinDetectThread();

        //Functions that read values from detectnet-controller.cpp

        /**
         * Reads camera data from detectnet and stores it in private variables
         */
        void ReadCameraResolution();

        /**
         * Reads unsorted BBarray from detectnet-camera
         */
        float** ReadUnsortedBBArray();


        /**
         * Reads integer that stores the number of detect objects from
         * detectnet-camera
         */
        volatile int* ReadNumberOfDetectedBB();

        /**
         * Reads a boolean that returns true if CTRL ^C is pressed.
         */
        bool ReadStopSignal();

        /**
         * Returns the x coordinate of the center of a given sorted sorted bounding box
         */
        float GetCenterXFromBB(std::array<float, 5> bb);

        /**
         * Returns the y coordinate of the center of a given sorted sorted bounding box
         */
        float GetCenterYFromBB(std::array<float, 5> bb);

        /**
         * Returns true if detectNet has finished loading the 
         * camera and is ready to start reading camera data 
         */
        bool IsDetectNetReady();
        
        /**
         * Set's the camera port for detectnet to use
         */
        void SetCameraPort(int source);

        /**
         * Returns camera width
         */
        float GetCameraWidth();

        /**
         * Returns camera height
         */
        float GetCameraHeight();

        /**
         * Returns X coordinate of center of camera
         */
        float GetCameraCenterX();

        /**
         * Returns Y coordinate of center of camera
         */
        float GetCameraCenterY();

        /**
         * Runs SortBBArrayByTargetDistance and returns
         */
        std::array<float, 5> GetTargetBB();

        /**
         * Returns the area of TargetBB
         */
        float GetAreaOfTargetBB();

        /**
         * Returns the distance of the X center of the target 
         * BB from the center of the frame
         */
        float GetErrorXOfTargetBB();

        /**
         * Returns the distance of the Y center of the target 
         * BB from the center of the frame
         */
        float GetErrorYOfTargetBB();

        /**
         * 
         */
        int GetClassIDFromUnsortedBBNum(int bbNum);
    

        enum class CupOrientation {
                VERTICAL=0,
                HORIZONTAL=1,
                UKNOWN=2
        };

        DetectNetController::CupOrientation GetCupOrientation();

    private:
        float* GetConfCPU();

        float** bbArrayUnsorted;
        volatile int numberOfDetectedBB;

        float cameraCenterX;
        float cameraCenterY;
        float cameraWidth;
        float cameraHeight;

        float GetDistanceFromTwoPoints(float x1, float y1, float x2, float y2);

        //Thread Control
        void runThread();
        std::thread* detectNetThread;

        //Arguments
        std::string m_model;
};

#endif

