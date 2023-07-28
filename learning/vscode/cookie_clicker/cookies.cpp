#include "raylib.h"
#include <string>
using namespace std;

int main()
{
    int width = 800;
    int height = 450;
    int contador{1};
    InitWindow(width, height, "Cookies");
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawCircle(400, 225, 50, BROWN);

        const char *strContador = std::to_string(contador).c_str();

        if (IsKeyDown(KEY_SPACE)) contador++;
        DrawText(strContador, 399, 300, 30, WHITE);
        EndDrawing();
    };
}
