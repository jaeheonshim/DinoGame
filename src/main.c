#include <raylib.h>

#include "main.h"
#include "BackgroundRenderer.h"
#include "Player.h"

int main() {
    const int windowWidth = 800;
    const int windowHeight = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(windowWidth, windowHeight, "Dinosaur Game");
    InitAudioDevice();

    Texture2D sprites = LoadTexture("assets/spritesheet.png");
    Vector2 position = {0, 0};

    InitPlayer(sprites);
    InitBackground(sprites);

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();

        float scale = (float) GetScreenWidth() / GAMEWIDTH;
        float yPos = (float) GetScreenHeight() / 2;

        float delta = GetFrameTime();

        ClearBackground(WHITE);
        ScrollBackground(delta);
        UpdatePlayer(delta);

        if(IsKeyPressed(KEY_SPACE)) {
            JumpPlayer();
        }

        DrawBackground(scale, yPos);
        DrawPlayer(scale, yPos);
        
        EndDrawing();
    }

    CloseWindow();
}