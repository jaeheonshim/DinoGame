#include <raylib.h>

int main() {
    const int windowWidth = 800;
    const int windowHeight = 450;

    const int gameWidth = 1200;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(windowWidth, windowHeight, "Dinosaur Game");

    Texture2D sprites = LoadTexture("assets/spritesheet.png");
    Vector2 position = {0, 0};

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();

        float scale = (float) GetScreenWidth() / gameWidth;

        ClearBackground(RAYWHITE);
        DrawTextureEx(sprites, position, 0, scale, WHITE);

        EndDrawing();
    }

    CloseWindow();
}