#include "GameManager.hpp"

#include <raylib.h>

Rectangle GetBlockTexture(Block::type aType, int aIndex);

bool GameManager::Init()
{
   mAssetManager.LoadAllAssets();
   mMap = new Map(cMAP_WIDTH, cMAP_HEIGHT);

   mMap->GetBlockUnsafe(0, 0).blockType = Block::type::DIRT;
   mMap->GetBlockUnsafe(1, 1).blockType = Block::type::IRON;
   mMap->GetBlockUnsafe(2, 2).blockType = Block::type::ICE;
   mMap->GetBlockUnsafe(3, 3).blockType = Block::type::GOLD_BLOCK;
   mMap->GetBlockUnsafe(4, 4).blockType = Block::type::GRASS;

   mCamera.target = { 0.0f, 0.0f };
   mCamera.zoom = 50.0f;
   mCamera.rotation = 0.0f;
   mCamera.offset = { 0.0f, 0.0f };

   return true;
}

bool GameManager::Update()
{
   float deltaTime = GetFrameTime();
   if (deltaTime > 1.0 / 5.0) { deltaTime = 1.0 / 5.0; } //constrain dt to 5 fps

   BeginMode2D(mCamera);

   if (IsKeyDown(KEY_UP))    { mCamera.target.y -= 10.0f * deltaTime; }
   if (IsKeyDown(KEY_DOWN))  { mCamera.target.y += 10.0f * deltaTime; }
   if (IsKeyDown(KEY_LEFT))  { mCamera.target.x -= 10.0f * deltaTime; }
   if (IsKeyDown(KEY_RIGHT)) { mCamera.target.x += 10.0f * deltaTime; }

   ClearBackground({ 75, 75, 150, 255 });
   for (unsigned int i = 0; i < cMAP_WIDTH; i++)
   {
      for (unsigned int j = 0; j < cMAP_HEIGHT; j++)
      {
         Block block = mMap->GetBlockUnsafe(i, j);
         if (block.blockType == Block::AIR)
         {
            // don't need to do anything for air blocks, proceed to next block
            continue;
         }

         float blockSize = 1.f;
         float x = i * blockSize;
         float y = j * blockSize;

         
         DrawTexturePro(mAssetManager.mBlockTextureAtlas,
            GetBlockTexture((Block::type)block.blockType, 0),
            Rectangle{ x, y, blockSize, blockSize }, { 0,0 }, 0.0, WHITE);

      }
   }

   EndMode2D();

   return true;
}

void GameManager::Close()
{

}

Rectangle GetBlockTexture(Block::type aType, int aIndex)
{
   return Rectangle{ (int)aType * 32.f, (float)aIndex * 32.f, 32.f, 32.f };
}