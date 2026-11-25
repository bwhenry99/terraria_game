#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include <cinttypes>

struct Block
{
   enum type
   {
      AIR = 0,
      DIRT,

      BLOCK_TYPE_COUNT
   };

   uint16_t blockType = 0;
};

class Map
{
public:
   Map(unsigned int aWidth, unsigned int aHeight);
   ~Map();

   Block* GetBlockSafe(unsigned int aX, unsigned int aY);
   Block& GetBlockUnsafe(unsigned int aX, unsigned int aY);

private:
   unsigned int mWidth = 0;
   unsigned int mHeight = 0;
   Block* mBlocks = nullptr;
};

#endif // !GAME_MAP_HPP
