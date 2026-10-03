// language: C++, file: aimbot.cpp, target: Standoff 2 1.0.0
#include <cmath>

bool  g_aimEnable = false;
float g_aimFov    = 90.0f;
float g_aimSmooth = 8.0f;

extern "C" void runAimbot(float W, float H) {
    (void)W; (void)H;
    if (!g_aimEnable) return;
    // target select + touch move
}
