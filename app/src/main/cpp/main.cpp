// language: C++, file: main.cpp, target: Android arm64
#include <jni.h>
#include <android/log.h>
#include <pthread.h>
#include <unistd.h>

#define LOG(...) __android_log_print(ANDROID_LOG_INFO,"ASTRAL",__VA_ARGS__)

extern "C" {
    void renderESP(float, float);
    void runAimbot(float, float);
}

extern bool g_espBoxes, g_espHealth, g_aimEnable;
extern bool g_rageFastFire, g_rageInfAmmo, g_rageWallshot,
            g_rageNoRecoil, g_rageOneShot, g_rageFastPlant;

static void* renderLoop(void*) {
    float W = 1080.0f, H = 2400.0f;
    while (true) {
        renderESP(W, H);
        runAimbot(W, H);
        usleep(16000);
    }
    return nullptr;
}

extern "C" JNIEXPORT void JNICALL
Java_com_astral_menu_NativeBridge_init(JNIEnv*, jclass, jint pid) {
    LOG("ASTRAL init pid=%d", pid);
    pthread_t t;
    pthread_create(&t, nullptr, renderLoop, nullptr);
}

extern "C" JNIEXPORT void JNICALL
Java_com_astral_menu_NativeBridge_setFeature(JNIEnv*, jclass, jint id, jboolean on) {
    switch (id) {
        case 1: g_espBoxes      = on; break;
        case 2: g_espHealth     = on; break;
        case 3: g_aimEnable     = on; break;
        case 4: g_rageFastFire  = on; break;
        case 5: g_rageInfAmmo   = on; break;
        case 6: g_rageWallshot  = on; break;
        case 7: g_rageNoRecoil  = on; break;
        case 8: g_rageOneShot   = on; break;
        case 9: g_rageFastPlant = on; break;
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_astral_menu_NativeBridge_setFloat(JNIEnv*, jclass, jint id, jfloat v) {
    if (id == 2) { /* aspect ratio */ }
}
