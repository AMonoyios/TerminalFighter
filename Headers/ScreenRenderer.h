#ifndef ScreenRenderer_h
#define ScreenRenderer_h

#include <vector>

using namespace std;

class ScreenRenderer {

private:
    static void DrawTerrain();
    static void DrawBuildings();
    static void DrawInteractables();
    static void DrawPlayer();
    static void DrawGUI(double fps);
    
public:
    static void DrawScreen(double fps);
    static void Initialize(unsigned short int width, unsigned short int height);

};

#endif
