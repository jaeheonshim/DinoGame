#include <raylib.h>

void InitPlayer(Texture2D spritesheet);
void DrawPlayer(float scale, float yPos);
void UpdatePlayer(float delta);
void JumpPlayer();
bool IsColliding(float scale, float yPos);