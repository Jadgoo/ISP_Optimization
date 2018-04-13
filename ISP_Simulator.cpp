#include "ISP_Simulator.h"

ISP_Simulator::ISP_Simulator(unsigned int numCycles, unsigned int camLat, unsigned int ispLat, unsigned int CVLat){

    this->numCycles = numCycles;

    this->camCycle  = camLat;
    cam = Cam{camCycle,false,0};

    this->ispCycle  = ispLat;
    isp = ISP{ispCycle,false,0};

    this->CVCycle = CVLat;
    cv = CV{CVCycle,false,0};

    run(numCycles,cam,isp,cv);

}

int ISP_Simulator::run(unsigned int numCycles, Cam camera, ISP isp, CV cv){

    int ispQueue = 0;
    int cvQueue = 0;

    for(int i = 0; i < numCycles; i++){

        atCycle = i;

        //cout << "Clock : " << atCycle << endl;

        if(!camera.isBusy){

            //cout << "It gets to camStart" << endl;
            camera.isBusy = true;
            camera.onCycle = 0;

            //cout << "camera.onCycle = " << camera.onCycle << "\t" << "camera.numClock = " << camera.numClock << endl;

        }else{

            camera.onCycle++;

            //cout << "camera.onCycle = " << camera.onCycle << "\t" << "camera.numClock = " << camera.numClock << endl;

            if(camera.onCycle >= camera.numClock){

                //cout << "It gets to camDone" << endl;
                ispQueue++;
                camera.onCycle = 0;
                //camera.isBusy = false;
                //cout << "Incrementing isp queue to: " << ispQueue << "\t at cycle: " << atCycle << endl;
            }


        }

        if(!isp.isBusy){

            if(ispQueue > 0){

                //cout << "It gets to ispStart" << endl;
                isp.isBusy = true;
                isp.onCycle = 0;
            }

        }else{

            isp.onCycle++;

            if(isp.onCycle >= isp.numClock){

                //cout << "It gets to ispDone" << endl;
                ispQueue--;
                isp.onCycle = 0;
                //isp.isBusy = false;
                cvQueue++;
                //cout << "Incrementing cV queue to: " << cvQueue << "\t at cycle: " << atCycle << endl;
            }

        }

        //TODO: CV process last
        if(!cv.isBusy){

            if(cvQueue > 0){

                //cout << "It gets to cvStart. CV Queue: " << cvQueue << endl;
                cv.isBusy = true;
                cv.onCycle = 0;
            }
        }else{

            cv.onCycle++;

            if(cv.onCycle >= cv.numClock){

                //cout << "It gets to cvDone" << endl;
                //cout << "num frames before: " << numFrames << endl;


                cvQueue--;
                cv.onCycle = 0;
                //cv.isBusy = false;

                numFrames++;
                //cout << "\nClock: " << atCycle << "\t" << "numFrames: " << numFrames <<endl;;
                //cout << "num frames after: " << numFrames << endl;
            }
        }
    }

    cout << "Total number of frames:\t" << numFrames << endl;
    cout << "Left in ispQueue:\t\t" << ispQueue << endl;
    cout << "Left in cvQueue:\t\t"  << cvQueue  << endl;

    return numFrames;

}
