#include <iostream>
#include <raylib.h>

int main()
{
    SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE);
    InitWindow(512, 256, "my window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello Window", 128, 128, 24, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}