#ifndef ScreenRenderer_h
#define ScreenRenderer_h

#include <string>
#include <vector>

using namespace std;

class ScreenRenderer {

private:
    static vector<string> screenBuffer;
    static int screenWidth;
    static int screenHeight;

    static void FlushBuffer();
    
public:
    static void DrawScreen(double fps, int width, int height);
    static void Initialize(int width, int height);

};

#endif
