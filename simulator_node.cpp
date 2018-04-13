#include "ISP_Simulator.h"

#include <iostream>


int main(int argc, char * argv[]){

    int cycles      = stoi(argv[1]);
    int camLatency  = stoi(argv[2]);
    int ispLatency  = stoi(argv[3]);
    int cvLatency   = stoi(argv[4]);


    cout << "NumCycles: " << cycles << endl;
    cout << "Camera Latency: " << camLatency << endl;
    cout << "ISP Latency: " << ispLatency << endl;
    cout << "CV Latency: " << cvLatency << endl;

    ISP_Simulator simulator(cycles,camLatency,ispLatency,cvLatency);

    cout << "Number of frames: " << simulator.numFrames << endl;


}
