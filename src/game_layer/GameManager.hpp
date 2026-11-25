#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "AssetManager.hpp"
#include "GameMap.hpp"

static unsigned int cMAP_WIDTH = 128;
static unsigned int cMAP_HEIGHT = 128;

class GameManager
{
public:
   GameManager() = default;
   ~GameManager() = default;

   bool Init();
   bool Update();
   void Close();

   AssetManager mAssetManager;
   Map* mMap = nullptr;

};

#endif // !GAME_MANAGER_HPP