#include "AssetManager.hpp"

void AssetManager::LoadAllAssets()
{
   mBlockTextureAtlas = LoadTexture(RESOURCES_PATH "textures.png");
}