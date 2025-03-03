#ifndef FrameRateManager_h
#define FrameRateManager_h

#include <chrono>
#include <thread>
#include <deque>

using namespace std;
using namespace std::chrono;

class FrameRateManager {

private:
    high_resolution_clock::time_point lastFrameTime;
    double targetFrameDuration;
    deque<double> frameTimes;

public:
    FrameRateManager(double targetFPS);
    
    void Wait();
    double GetFPS() const;
};

#endif
