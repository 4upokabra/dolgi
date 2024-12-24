#define _CRT_SECURE_NO_WARNINGS

#include "raylib.h"
#include <ctime>
#include <cmath>
#include "Clock.h"
#include "DrawLineBresenham.h"

void DrawClock(int screenWidth, int screenHeight) {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    float hourAngle = (ltm->tm_hour % 12 + ltm->tm_min / 60.0) * 30.0 * DEG2RAD;
    float minuteAngle = (ltm->tm_min + ltm->tm_sec / 60.0) * 6.0 * DEG2RAD;
    float secondAngle = ltm->tm_sec * 6.0 * DEG2RAD;

    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    int hourLength = 100;
    int minuteLength = 150;
    int secondLength = 180;

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawCircle(centerX, centerY, 200, LIGHTGRAY);
    for (int i = 0; i < 12; ++i) {
        float angle = i * 30.0 * DEG2RAD;
        int x = centerX + 180 * cos(angle);
        int y = centerY + 180 * sin(angle);
        DrawText(TextFormat("%d", i == 0 ? 12 : i), x - 10, y - 10, 20, DARKGRAY);
    }

    DrawLineBresenham(centerX, centerY, centerX + hourLength * cos(hourAngle), centerY + hourLength * sin(hourAngle), BLACK);
    DrawLineBresenham(centerX, centerY, centerX + minuteLength * cos(minuteAngle), centerY + minuteLength * sin(minuteAngle), BLACK);
    DrawLineBresenham(centerX, centerY, centerX + secondLength * cos(secondAngle), centerY + secondLength * sin(secondAngle), RED);

    EndDrawing();
}
