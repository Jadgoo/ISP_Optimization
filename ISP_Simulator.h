/*
    Author: Tolga Furkan Aktas
    Date: March 27, 2018
    Advisor: Yuhao Zhu

*/

#ifndef ISP_SIMULATOR_H
#define ISP_SIMULATOR_H

#include <iostream>

using namespace std;

class ISP_Simulator{

public:

    int numFrames = 0;

    typedef struct Camera{

        unsigned int numClock;
        bool isBusy;
        unsigned int onCycle;

    }Cam;

    typedef struct ISP{
        unsigned int numClock;
        bool isBusy;
        unsigned int onCycle;
    }ISP;

    typedef struct CV{

        unsigned int numClock;
        bool isBusy;
        unsigned int onCycle;

    }CV;

    unsigned int atCycle, numCycles;

    unsigned int camCycle,ispCycle,CVCycle;

    Camera cam;
    ISP isp;
    CV cv;

    int run(unsigned int clockCycles, Cam camera, ISP isp, CV cv);

    ISP_Simulator(unsigned int numCycles, unsigned int camLat, unsigned int ispLat, unsigned int CVLat);


};

#endif /* ISP_SIMULATOR_H*/
