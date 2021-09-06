#include <raylib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Game.h"
#include "Enemies.h"
#include "util.h"

static const float jumpVel = 1100;
static const float xPos = 170;

static const float runFrame = 0.1;

static float y = 0;
static float velY = 0;
static float accelY = -3500;
static bool jumping = false;

static float stateTime = 0;

static Sound jumpFx;

static Texture2D ss;
static Rectangle idle1 = {1336, 0, 88, 94};
static Rectangle idle2 = {1424, 0, 88, 94};
static Rectangle run1 = {1512, 0, 88, 94};
static Rectangle run2 = {1600, 0, 88, 94};
static Rectangle dead = {1688, 0, 88, 94};

static Rectangle collider1 = {xPos + 20, 0, 40, 55};
static Rectangle collider2 = {xPos + 45, 0, 40, 30};

void DrawCollider(float scale);
bool IsColliding(float scale, float yPos);

Rectangle GetTextureRect() {
    if(IsDead()) {
        return dead;
    }
    
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

    jumpFx = LoadSound("assets/jump.ogg");
}

void DrawPlayer(float scale, float yPos) {
    collider1.y = (yPos / scale) - y - 30;
    collider2.y = (yPos / scale) - y - 60;

    Rectangle destRect = {xPos * scale, yPos + -(y * scale) - 65 * scale, idle1.width * scale, idle1.height * scale};
    Vector2 origin = {0, 0};
    DrawTexturePro(ss, GetTextureRect(), destRect, origin, 0, WHITE);
    DrawCollider(scale);
}

void DrawCollider(float scale) {
    Rectangle rect1 = ScaleRect(collider1, scale);
    Rectangle rect2 = ScaleRect(collider2, scale);
    
    DrawRectangleLinesEx(rect1, 3, BLUE);
    DrawRectangleLinesEx(rect2, 3, BLUE);
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
        PlaySound(jumpFx);
        velY = jumpVel;
        jumping = true;
    }
}

bool IsColliding(float scale, float yPos) {
    struct EnemyListItem *list = GetEnemyList();
    while(list != NULL) {
        Rectangle collider = ScaleDest(GetEnemyCollider(list->enemy), scale, yPos);
        if(CheckCollisionRecs(ScaleRect(collider1, scale), collider) || CheckCollisionRecs(ScaleRect(collider2, scale), collider)) {
            return true;
        }

        list = list->next;
    }

    return false;
}