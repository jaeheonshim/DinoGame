#include <raylib.h>

static const float jumpVel = 1000;

static float y = 0;
static float velY = 0;
static float accelY = -3000;

void DrawPlayer(float scale, float yPos) {
    DrawCircle(100 * scale, yPos + -(y * scale), 10 * scale, PURPLE);
}

void UpdatePlayer(float delta) {
    velY += accelY * delta;
    y += velY * delta;

    if(y <= 0) {
        y = 0;
        velY = 0;
    }
}

void JumpPlayer() {
    velY = jumpVel;
}