#ifndef _ROGUE_H
#define _ROGUE_H
#include"../imgui/imgui.h"
#include"../imgui/imgui_impl_glut.h"
#include"../imgui/imgui_impl_opengl2.h"
#include"../GL/freeglut.h"
#include"World.h"
#include"Sequence.h"
class Rogue{
    public:
        static void Init(int,char*[]);
        static void Render();
        static void handleKey(int);
        static void Run(int,char*[]);
    private:
        static void setStyle();
};
#endif
