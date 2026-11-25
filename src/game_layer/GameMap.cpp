#include "GameMap.hpp"


Map::Map(unsigned int aWidth, unsigned int aHeight)
   : mWidth(aWidth)
   , mHeight(aHeight)
{
   mBlocks = new Block[mWidth * mHeight];
}

Map::~Map()
{
   delete mBlocks;
}

Block* Map::GetBlockSafe(unsigned int aX, unsigned int aY)
{
   Block* block = nullptr;
   if (aX < mWidth && aY < mHeight)
   {
      block = &mBlocks[aX + (aY * mWidth)];
   }
   return block;
}

Block& Map::GetBlockUnsafe(unsigned int aX, unsigned int aY)
{
   return mBlocks[aX + (aY * mWidth)];
}