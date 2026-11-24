#include "GameManager.hpp"

#include <raylib.h>

bool GameManager::Init()
{
   mAssetManager.LoadAllAssets();
   return true;
}

bool GameManager::Update()
{
   float deltaTime = GetFrameTime();
   if (deltaTime > 1.0 / 5.0) { deltaTime = 1.0 / 5.0; } //constrain dt to 5 fps

   DrawTexturePro(mAssetManager.mDirtTexture, { 0,0, (float)mAssetManager.mDirtTexture.width, (float)mAssetManager.mDirtTexture.height },
      { 50, 50, 100, 100 }, {}, 0.0, WHITE);
   return true;
}

void GameManager::Close()
{

}