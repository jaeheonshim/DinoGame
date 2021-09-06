#include <stdbool.h>
#include <raylib.h>

static int isDead;

static Sound deadFx;

void InitGame() {
    deadFx = LoadSound("assets/death.ogg");
}

void OnDeath() {
    if(!isDead) {
        PlaySound(deadFx);
        isDead = 1;
    }
}

int IsDead() {
    return isDead;
}