#include "Headers/ScreenRenderer.h"
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif

vector<string> ScreenRenderer::screenBuffer;
int ScreenRenderer::screenWidth = 0;
int ScreenRenderer::screenHeight = 0;

void ScreenRenderer::FlushBuffer() {
    system(CLEAR_SCREEN);

    for (const string& line : screenBuffer) {
        std::cout << line << '\n';
    }
}

void ScreenRenderer::Initialize(int width, int height) {
    screenWidth = width;
    screenHeight = height;

    screenBuffer.resize(screenHeight, string(screenWidth, ' '));
}

void ScreenRenderer::DrawScreen(double fps, int width, int height) {
    for (int i = 0; i < height; ++i) {
        screenBuffer[i] = string(width, ' ');
    }

    screenBuffer[0].replace(0, 10, "FPS: " + to_string(int(fps)));

    int midY = height / 2;
    int midX = width / 2 - 5;
    screenBuffer[midY].replace(midX, 10, "Running...");

    FlushBuffer();
}
