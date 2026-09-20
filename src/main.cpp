#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

int main()
{
    SetConfigFlags(ConfigFlags::FLAG_WINDOW_RESIZABLE);
    InitWindow(512, 256, "my window");

    rlImGuiSetup(true);
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    float property = 50.0f;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        rlImGuiBegin();

        // docking config 
        ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
        ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        ImGui::PopStyleColor(2);

        DrawRectangle(75, 75, 100, 100, { 0, 255, 0, 255 });
        DrawRectangle(50, 50, 100, 100, { 255, 0, 0, 255 });

        DrawText("Hello Window", 128, 128, 24, RED);

        ImGui::Begin("test");
        ImGui::Text("Hello from imgui");
        if (ImGui::Button("button"))
        {
           std::cout << property << std::endl;
        }

        ImGui::SliderFloat("slider", &property, 0, 100);
        ImGui::End();

        ImGui::Begin("window2");
        if (ImGui::Button("button"))
        {
           std::cout << "hello from window 2" << std::endl;
        }
        ImGui::End();

        rlImGuiEnd();
        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}