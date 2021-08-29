#include <raylib.h>
#include <stdio.h>
#include "Enemies.h"
#include "main.h"

static Texture2D ss;

static Rectangle smallEnemy = {447, 2, 34, 70};

Rectangle ScaleDest(Rectangle rect, float scale, float posY);
Rectangle ClipSrc(Rectangle src, Rectangle dest);

void InitEnemyRenderer(Texture2D spritesheet) {
    ss = spritesheet;
}

void RenderEnemies(float scale, float posY) {
    float frontBound = (GAMEWIDTH - GROUNDWIDTH) / 2;
    float backBound = GAMEWIDTH - frontBound;
    struct EnemyListItem *list = GetEnemyList();

    while(list != NULL) {
        Rectangle collider = GetEnemyCollider(list->enemy);
        DrawTexturePro(ss, ClipSrc(smallEnemy, collider), ScaleDest(collider, scale, posY), (Vector2) {0, 0}, 0, WHITE);

        list = list->next;
    }
}

Rectangle ClipSrc(Rectangle src, Rectangle dest) {
    float frontBound = (GAMEWIDTH - GROUNDWIDTH) / 2;
    float backBound = GAMEWIDTH - frontBound;

    if(dest.x <= frontBound) {
        src.x += frontBound - dest.x;
        src.width -= frontBound - dest.x;
    }

    if(dest.x + dest.width >= backBound) {
        src.width = backBound - dest.x;
    }

    return src;
}

Rectangle ScaleDest(Rectangle rect, float scale, float posY) {
    float frontBound = (GAMEWIDTH - GROUNDWIDTH) / 2;
    float backBound = GAMEWIDTH - frontBound;

    if(rect.x <= frontBound) {
        rect.width -= frontBound - rect.x;
        rect.x += frontBound - rect.x;
    }

    if(rect.x + rect.width >= backBound) {
        rect.width = backBound - rect.x;
    }

    rect.x *= scale;
    rect.y = posY - (rect.height - 27) * scale;
    rect.width *= scale;
    rect.height *= scale;

    return rect;
}