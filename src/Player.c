#include <raylib.h>
#include <stdbool.h>

static const float jumpVel = 1000;
static const float xPos = 170;

static const float runFrame = 0.1;

static float y = 0;
static float velY = 0;
static float accelY = -3000;
static bool jumping = false;

static float stateTime = 0;

static Texture2D ss;
static Rectangle idle1 = {1336, 0, 88, 94};
static Rectangle idle2 = {1424, 0, 88, 94};
static Rectangle run1 = {1512, 0, 88, 94};
static Rectangle run2 = {1600, 0, 88, 94};

Rectangle GetTextureRect() {
    if(jumping) {
        return idle1;
    }
    
    if((int) (stateTime / runFrame) % 2 == 0) {
        return run1;
    } else {
        return run2;
    }
}

void InitPlayer(Texture2D spritesheet) {
    ss = spritesheet;
}

void DrawPlayer(float scale, float yPos) {
    Rectangle destRect = {xPos * scale, yPos + -(y * scale) - 65 * scale, idle1.width * scale, idle1.height * scale};
    Vector2 origin = {0, 0};
    DrawTexturePro(ss, GetTextureRect(), destRect, origin, 0, WHITE);
}

void UpdatePlayer(float delta) {
    stateTime += delta;
    velY += accelY * delta;
    y += velY * delta;

    if(y <= 0) {
        y = 0;
        velY = 0;
        jumping = false;
    }
}

void JumpPlayer() {
    if(!jumping) {
        velY = jumpVel;
        jumping = true;
    }
}