#include "GameManager.hpp"

#include <raylib.h>

bool GameManager::Init()
{
   return true;
}

bool GameManager::Update()
{
   DrawRectangle(75, 75, 100, 100, { 0, 255, 0, 255 });
   DrawRectangle(50, 50, 100, 100, { 255, 0, 0, 255 });

   DrawText("Hello Window", 128, 128, 24, RED);
   return true;
}

void GameManager::Close()
{

}