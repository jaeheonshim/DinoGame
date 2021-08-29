#include <raylib.h>

typedef enum {SMALL, LARGE} EnemyType;

typedef struct {
    EnemyType type;
    float pos;
} Enemy;

struct EnemyListItem {
    Enemy enemy;
    struct EnemyListItem *next;
};

Rectangle GetEnemyCollider(Enemy enemy, float scale, float posY);
void QueueEnemy(Enemy enemy);
void DequeueEnemy(void);
int CountEnemies();
void UpdateEnemies(float delta, float scrollVelocity);
struct EnemyListItem *GetEnemyList();