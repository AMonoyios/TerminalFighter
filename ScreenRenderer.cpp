#include "Headers/ScreenRenderer.h"
#include "Headers/FrameRateManager.h"

#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void ScreenRenderer::Initialize(unsigned short int width, unsigned short int height) {
    SHORT screenWidth = static_cast<SHORT>(width);
    SHORT screenHeight = static_cast<SHORT>(height);
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { screenWidth, screenHeight };
    SMALL_RECT windowSize = { 0, 0, screenWidth, screenHeight };

    SetConsoleScreenBufferSize(hConsole, bufferSize);
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void ScreenRenderer::DrawScreen(double fps) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos = {0, 0};
    SetConsoleCursorPosition(hConsole, cursorPos);

    DrawTerrain();
    DrawBuildings();
    DrawInteractables();
    DrawPlayer();
    DrawGUI(fps);
}

void ScreenRenderer::DrawTerrain() {
    cout << "Drawing terrain..." << '\n';
    cout << "  Trees and bushes here!" << '\n';
}

void ScreenRenderer::DrawBuildings() {
    cout << "Drawing buildings..." << '\n';
    cout << "  House at (10, 10)" << '\n';
}

void ScreenRenderer::DrawInteractables() {
    cout << "Drawing interactables..." << '\n';
    cout << "  Enemy at (20, 15)" << '\n';
}

void ScreenRenderer::DrawPlayer() {
    cout << "Drawing player..." << '\n';
    cout << "  Player at (30, 10)" << '\n';
}

void ScreenRenderer::DrawGUI(double fps) {
    cout << "Drawing GUI..." << '\n';
    cout << "  FPS: " << fps << '\n';
}
