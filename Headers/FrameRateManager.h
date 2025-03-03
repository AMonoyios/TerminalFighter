#ifndef FrameRateManager_h
#define FrameRateManager_h

#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class FrameRateManager {

private:
    unsigned short int targetFPS;

    high_resolution_clock::time_point lastFrameTime;

    unsigned short int frameCount = 0;
    double elapsedTime = 0.0;
    double fps = 0.0;

public:
    FrameRateManager(unsigned short int targetFPS);
    
    void Wait();
    double GetFPS() const;
};

#endif
