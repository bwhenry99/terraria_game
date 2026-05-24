#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

int main()
{
    SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE);
    InitWindow(512, 256, "my window");
    rlImGuiSetup(true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        rlImGuiBegin();

        DrawRectangle(75, 75, 100, 100, { 0, 255, 0, 255 });
        DrawRectangle(50, 50, 100, 100, { 255, 0, 0, 255 });

        DrawText("Hello Window", 128, 128, 24, RED);

        ImGui::Begin("test");
        ImGui::Text("Hello from imgui");
        ImGui::End();

        rlImGuiEnd();
        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}