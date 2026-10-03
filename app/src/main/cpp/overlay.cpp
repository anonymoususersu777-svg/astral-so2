// language: C++, file: overlay.cpp, target: Android arm64
#include <jni.h>
#include <android/log.h>
#include <GLES2/gl2.h>

#define LOG(...) __android_log_print(ANDROID_LOG_INFO,"ASTRAL",__VA_ARGS__)

void drawBox(float x, float y, float w, float h, float r, float g, float b) {
    GLfloat verts[] = { x,y, x+w,y, x+w,y, x+w,y+h, x+w,y+h, x,y+h, x,y+h, x,y };
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, verts);
    glEnableVertexAttribArray(0);
    glColor4f(r, g, b, 1.0f);
    glDrawArrays(GL_LINES, 0, 8);
}
