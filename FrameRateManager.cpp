#include "Headers/FrameRateManager.h"

FrameRateManager::FrameRateManager(unsigned short int targetFPS) : targetFPS(targetFPS) {
    lastFrameTime = high_resolution_clock::now();
}

void FrameRateManager::Wait() {
    time_point<steady_clock> now = high_resolution_clock::now();
    duration<double> frameTime = now - lastFrameTime;

    double targetFrameTime = 1.0 / targetFPS;
    double sleepTime = targetFrameTime - frameTime.count();

    if (sleepTime > 0.0) {
        this_thread::sleep_for(duration<double>(sleepTime));
    }

    lastFrameTime = high_resolution_clock::now();

    frameCount++;
    elapsedTime += frameTime.count();
    if (elapsedTime >= 1.0) {
        fps = frameCount / elapsedTime;
        frameCount = 0;
        elapsedTime = 0.0;
    }
}

double FrameRateManager::GetFPS() const {
    return fps;
}
