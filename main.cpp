#include "Headers/FrameRateManager.h"
#include "Headers/ScreenRenderer.h"
#include "Headers/KeyboardKeys.h"

#include <conio.h>

int main(int argc, char* argv[]) {
    const unsigned short int TARGET_FPS = 30;
    FrameRateManager frameRateManager(TARGET_FPS);

    const unsigned short int SCREEN_WIDTH = 70;
    const unsigned short int SCREEN_HEIGHT = 20;
    ScreenRenderer::Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

    bool running = true;
    while (running) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == KeyboardKeys::ESCAPE_KEY) {
                running = false;
            }
        }

        ScreenRenderer::DrawScreen(frameRateManager.GetFPS());
        frameRateManager.Wait();
    }
    
    return 0;
}
