#include <raylib.h>

static Texture2D spritesheet;
static Rectangle ground1;
static Rectangle ground2;

void InitBackground(Texture2D ss) {
    spritesheet = ss;

    ground1.x = 0;
    ground1.y = 100;
    ground1.width = ss.width / 2;
    ground1.height = 30;

    ground2.x = ss.width / 2;
    ground2.y = 100;
    ground2.width = ss.width / 2;
    ground2.height = 30;
}

void DrawBackground(float scale) {
    Rectangle destRect = {0, 0, ground1.width * scale, ground1.height * scale};
    Vector2 origin = {0, 0};
    DrawTexturePro(spritesheet, ground1, destRect, origin, 0, WHITE);
}