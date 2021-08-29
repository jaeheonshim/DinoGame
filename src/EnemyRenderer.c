#include <raylib.h>
#include <stdio.h>
#include "Enemies.h"
#include "main.h"

static Texture2D ss;

static Rectangle smallEnemy1 = {447, 2, 34, 70};
static Rectangle smallEnemy2 = {480, 2, 68, 70};
static Rectangle smallEnemy3 = {548, 2, 102, 70};

Rectangle ScaleDest(Rectangle rect, float scale, float posY);
Rectangle ClipSrc(Rectangle src, Rectangle dest);
Rectangle GetTexture(Enemy enemy);

void InitEnemyRenderer(Texture2D spritesheet) {
    ss = spritesheet;
}

void RenderEnemies(float scale, float posY) {
    float frontBound = (GAMEWIDTH - GROUNDWIDTH) / 2;
    float backBound = GAMEWIDTH - frontBound;
    struct EnemyListItem *list = GetEnemyList();

    while(list != NULL) {
        Rectangle collider = GetEnemyCollider(list->enemy);
        Rectangle texture = GetTexture(list->enemy);
        DrawTexturePro(ss, ClipSrc(texture, collider), ScaleDest(collider, scale, posY), (Vector2) {0, 0}, 0, WHITE);
        DrawRectangleLinesEx(ScaleDest(collider, scale, posY), 2, RED);

        list = list->next;
    }
}

Rectangle GetTexture(Enemy enemy) {
    switch(enemy.type) {
        case SMALL1:
            return smallEnemy1;
        case SMALL2:
            return smallEnemy2;
        case SMALL3:
            return smallEnemy3;
        default:
            return smallEnemy1;
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