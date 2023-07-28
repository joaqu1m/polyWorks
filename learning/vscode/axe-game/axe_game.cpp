#include "raylib.h"

int main()
{
    // variável não inicializada:
    // float x;        // podemos inicializá-la posteriormente como em JS
    // variável inicializada:
    // float x = 400;
    // variável inicializada com Braced Initialization
    // float x{400};
    // variável inicializada com Braced Initialization, tendo seu valor padrão como 0
    // float x{};
    int width = 800;
    int height = 450;
    InitWindow(width, height, "Axe Game");
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawCircle(400, 225, 50, WHITE);
        DrawText("CIRCULO", 400, 275, 50, BLACK);
        EndDrawing();
    };
}
