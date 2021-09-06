#include <raylib.h>

#include "main.h"
#include "Game.h"
#include "BackgroundRenderer.h"
#include "Player.h"
#include "Enemies.h"
#include "EnemyRenderer.h"

int main() {
    const int windowWidth = 800;
    const int windowHeight = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitWindow(windowWidth, windowHeight, "Dinosaur Game");
    InitAudioDevice();

    Texture2D sprites = LoadTexture("assets/spritesheet.png");
    Vector2 position = {0, 0};

    InitGame();
    InitPlayer(sprites);
    InitBackground(sprites);
    InitEnemyRenderer(sprites);

    while(!WindowShouldClose()) {
        BeginDrawing();

        float scale = (float) GetScreenWidth() / GAMEWIDTH;
        float yPos = (float) GetScreenHeight() / 2;

        float delta = GetFrameTime();

        ClearBackground(WHITE);

        if(!IsDead()) {
            ScrollBackground(delta, 600);
            UpdateEnemies(delta, 600);
            UpdatePlayer(delta);
        }

        if(IsKeyDown(KEY_SPACE)) {
            JumpPlayer();
        }

        if(IsKeyPressed(KEY_ENTER)) {
            SpawnRandomEnemy();
        }

        if(IsKeyPressed(KEY_Z)) {
            DequeueEnemy();
        }

        if(IsColliding(scale, yPos)) {
            OnDeath();
        }

        DrawBackground(scale, yPos);
        RenderEnemies(scale, yPos);
        DrawPlayer(scale, yPos);
        
        EndDrawing();
    }

    CloseWindow();
}