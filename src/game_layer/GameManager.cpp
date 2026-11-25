#include "GameManager.hpp"

#include <raylib.h>

bool GameManager::Init()
{
   mAssetManager.LoadAllAssets();
   mMap = new Map(cMAP_WIDTH, cMAP_HEIGHT);

   mMap->GetBlockUnsafe(0, 0).blockType = Block::type::DIRT;
   mMap->GetBlockUnsafe(1, 1).blockType = Block::type::DIRT;
   mMap->GetBlockUnsafe(2, 2).blockType = Block::type::DIRT;
   mMap->GetBlockUnsafe(3, 3).blockType = Block::type::DIRT;
   mMap->GetBlockUnsafe(4, 4).blockType = Block::type::DIRT;

   return true;
}

bool GameManager::Update()
{
   float deltaTime = GetFrameTime();
   if (deltaTime > 1.0 / 5.0) { deltaTime = 1.0 / 5.0; } //constrain dt to 5 fps

   ClearBackground({ 75, 75, 150, 255 });
   for (unsigned int i = 0; i < cMAP_WIDTH; i++)
   {
      for (unsigned int j = 0; j < cMAP_HEIGHT; j++)
      {
         if (mMap->GetBlockUnsafe(i, j).blockType == Block::AIR)
         {
            // don't need to do anything for air blocks, proceed to next block
            continue;
         }

         float blockSize = 32.f;
         float x = i * blockSize;
         float y = j * blockSize;

         
         DrawTexturePro(mAssetManager.mDirtTexture,
            Rectangle{ 0.0, 0.0, static_cast<float>(mAssetManager.mDirtTexture.width), static_cast<float>(mAssetManager.mDirtTexture.height) },
            Rectangle{ x, y, blockSize, blockSize }, { 0,0 }, 0.0, WHITE);

      }
   }
   return true;
}

void GameManager::Close()
{

}