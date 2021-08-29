#include <raylib.h>
#include <stdio.h>
#include "Enemies.h"

static Texture2D ss;

static Rectangle smallEnemy = {447, 2, 34, 70};

void InitEnemyRenderer(Texture2D spritesheet) {
    ss = spritesheet;
}

void RenderEnemies(float scale, float posY) {
    struct EnemyListItem *list = GetEnemyList();

    while(list != NULL) {
        Rectangle collider = GetEnemyCollider(list->enemy, scale, posY);
        DrawTexturePro(ss, smallEnemy, collider, (Vector2) {0, 0}, 0, WHITE);

        list = list->next;
    }
}