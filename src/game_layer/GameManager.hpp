#include "AssetManager.hpp"

class GameManager
{
public:
   GameManager() = default;
   ~GameManager() = default;

   bool Init();
   bool Update();
   void Close();

   AssetManager mAssetManager;

};