#include <raylib.h>
#include <stdio.h>

#include "Enemies.h"

static struct EnemyListItem *first = NULL;
static struct EnemyListItem *last = NULL;

static Rectangle smallEnemy = {0, 0, 34, 70};

Rectangle GetEnemyCollider(Enemy enemy) {
    Rectangle rect = smallEnemy;
    rect.x = enemy.pos;

    return rect;
}

void QueueEnemy(Enemy enemy) {
    struct EnemyListItem *item = (struct EnemyListItem *) MemAlloc(sizeof(struct EnemyListItem));

    item->enemy = enemy;

    if(last != NULL) {
        last->next = item;
    } else {
        first = item;
    }

    last = item;
}

void DequeueEnemy(void) {
    struct EnemyListItem *item = first;
    if(item == NULL) return;

    Enemy enemy = item->enemy;
    first = item->next;

    if(first == NULL) {
        last = NULL;
    }

    MemFree(item);
}

int CountEnemies() {
    int i = 0;
    struct EnemyListItem *item = first;
    while(item != NULL) {
        i++;
        item = item->next;
    }

    return i;
}

void UpdateEnemies(float delta, float scrollVelocity) {
    float deltaX = (delta * scrollVelocity);
    struct EnemyListItem *list = GetEnemyList();
    while(list != NULL) {
        list->enemy.pos -= deltaX;
        if(list->enemy.pos < 0) {
            printf("Dequeue\n");
            DequeueEnemy();
        }

        list = list->next;
    }
}

struct EnemyListItem *GetEnemyList() {
    return first;
}