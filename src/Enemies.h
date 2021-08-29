#include <raylib.h>

typedef enum {SMALL1, SMALL2, SMALL3} EnemyType;

typedef struct {
    EnemyType type;
    float pos;
} Enemy;

struct EnemyListItem {
    Enemy enemy;
    struct EnemyListItem *next;
};

Rectangle GetEnemyCollider(Enemy enemy);
void QueueEnemy(Enemy enemy);
void DequeueEnemy(void);
int CountEnemies();
void UpdateEnemies(float delta, float scrollVelocity);
struct EnemyListItem *GetEnemyList();