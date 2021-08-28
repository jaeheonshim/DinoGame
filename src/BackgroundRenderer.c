#include <raylib.h>
#include <math.h>

#include "main.h"

typedef struct {
    float pos;
} BgData;

static Texture2D spritesheet;
static Rectangle ground1;
static Rectangle ground2;

static BgData ground1Data;
static BgData ground2Data;

static const float scrollVelocity = 100;

Rectangle generateSrcRect(Rectangle rect, float pos);
Rectangle generateDestRect(float pos, float scale, float yPos);

void InitBackground(Texture2D ss) {
    spritesheet = ss;

    ground1.x = 0;
    ground1.y = 100;
    ground1.width = ss.width / 2.0;
    ground1.height = 26;

    ground2.x = ss.width / 2.0;
    ground2.y = 100;
    ground2.width = ss.width / 2.0;
    ground2.height = 26;

    ground1Data.pos = 0;
    ground2Data.pos = ground1.width;
}

void DrawBackground(float scale, float yPos) {
    Vector2 origin = {0, 0};
    
    DrawTexturePro(spritesheet, generateSrcRect(ground1, ground1Data.pos), generateDestRect(ground1Data.pos, scale, yPos), origin, 0, WHITE);
    DrawTexturePro(spritesheet, generateSrcRect(ground2, ground2Data.pos), generateDestRect(ground2Data.pos, scale, yPos), origin, 0, WHITE);
}

Rectangle generateSrcRect(Rectangle rect, float pos) {
    rect.x += (pos >= 0 ? 0 : abs(pos));
    rect.width -= abs(pos);
    
    return rect;
}

Rectangle generateDestRect(float pos, float scale, float yPos) {
    float xOffset = (GAMEWIDTH - ground1.width) / 2 * scale;
    Rectangle dest = {xOffset + (pos >= 0 ? abs(pos) : 0) * scale, yPos, (ground1.width - abs(pos)) * scale, ground1.height * scale};
    return dest;
}

void ScrollBackground(float delta) {
    ground1Data.pos -= delta * scrollVelocity;
    ground2Data.pos -= delta * scrollVelocity;

    if(ground1Data.pos + ground1.width <= 0) {
        ground1Data.pos = ground2Data.pos + ground2.width;
    }

    if(ground2Data.pos + ground2.width <= 0) {
        ground2Data.pos = ground1Data.pos + ground1.width;
    }
}