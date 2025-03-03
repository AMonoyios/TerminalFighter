#include "Headers/FrameRateManager.h"

FrameRateManager::FrameRateManager(double targetFPS) : targetFrameDuration(1000.0 / targetFPS) {
    lastFrameTime = high_resolution_clock::now();
}

void FrameRateManager::Wait() {
    time_point<steady_clock> now = high_resolution_clock::now();
    double elapsedMs = duration<double, std::milli>(now - lastFrameTime).count();

    double waitTime = targetFrameDuration - elapsedMs;
    if (waitTime > 0) {
        this_thread::sleep_for(milliseconds(static_cast<int>(waitTime)));
    }

    time_point<steady_clock> frameEnd = high_resolution_clock::now();
    double frameTime = duration<double, std::milli>(frameEnd - lastFrameTime).count();
    lastFrameTime = frameEnd;

    frameTimes.push_back(frameTime);
    if (frameTimes.size() > 10) { // Keep last 10 frames
        frameTimes.pop_front();
    }
}

double FrameRateManager::GetFPS() const {
    if (frameTimes.empty()) {
        return 0.0;
    }
    
    double avgFrameTime = 0;
    for (double t : frameTimes) {
        avgFrameTime += t;
    }
    avgFrameTime /= frameTimes.size();

    return avgFrameTime > 0 ? (1000.0 / avgFrameTime) : targetFrameDuration;
}
