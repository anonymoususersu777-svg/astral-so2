// language: C++, file: esp.cpp, target: Standoff 2 1.0.0
#include <cstdint>

namespace Off {
    constexpr uintptr_t EntityList    = 0x2E4F10;
    constexpr uintptr_t LocalPlayer   = 0x1A3C58;
    constexpr uintptr_t ViewMatrix    = 0x4F2B90;
    constexpr uintptr_t Player_Health = 0x9C;
    constexpr uintptr_t Player_Pos    = 0x150;
}

struct Vec3 { float x, y, z; };

bool g_espBoxes  = true;
bool g_espHealth = true;

extern "C" bool worldToScreen(const Vec3& w, Vec3& s, float* m, float W, float H) {
    float cx = w.x*m[0] + w.y*m[4] + w.z*m[8]  + m[12];
    float cy = w.x*m[1] + w.y*m[5] + w.z*m[9]  + m[13];
    float cw = w.x*m[3] + w.y*m[7] + w.z*m[11] + m[15];
    if (cw < 0.01f) return false;
    s.x = (W/2)*(1 + cx/cw);
    s.y = (H/2)*(1 - cy/cw);
    return true;
}

extern "C" void renderESP(float W, float H) {
    (void)W; (void)H;
    // read game process memory via /proc/<pid>/mem with offsets above
}
