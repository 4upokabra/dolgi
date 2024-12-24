#include "raylib.h"
#include "Clock.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Clock");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        DrawClock(screenWidth, screenHeight);
    }

    CloseWindow();

    return 0;
}
