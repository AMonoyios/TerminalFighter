#include "Headers/FrameRateManager.h"
#include "Headers/ScreenRenderer.h"
#include "Headers/KeyboardKeys.h"

#include <conio.h>

int main(int argc, char* argv[]) {
    const int TARGET_FPS = 1000;
    FrameRateManager frameRateManager(TARGET_FPS);

    const int SCREEN_WIDTH = 50;
    const int SCREEN_HEIGHT = 20;

    ScreenRenderer::Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

    bool running = true;

    while (running) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == KeyboardKeys::ESCAPE_KEY) {
                running = false;
            }
        }

        ScreenRenderer::DrawScreen(frameRateManager.GetFPS(), SCREEN_WIDTH, SCREEN_HEIGHT);
        frameRateManager.Wait();
    }
    
    return 0;
}
