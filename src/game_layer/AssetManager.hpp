#include  <raylib.h>

class AssetManager
{
public:
   AssetManager() = default;
   ~AssetManager() = default;

   void LoadAllAssets();

   Texture mDirtTexture = {};

};