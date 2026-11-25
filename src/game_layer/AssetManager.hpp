#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include  <raylib.h>

class AssetManager
{
public:
   AssetManager() = default;
   ~AssetManager() = default;

   void LoadAllAssets();

   Texture mDirtTexture = {};

};

#endif // !ASSET_MANAGER_HPP