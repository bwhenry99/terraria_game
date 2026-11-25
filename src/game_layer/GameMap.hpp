#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include <cinttypes>

struct Block
{
   enum type
   {
      AIR = 0,
      DIRT,
      GRASS_BLOCK,
      STONE,
      GRASS,
      SAND,
      SAND_RUBY,
      SANDSTONE,
      WOOD_PLANK,
      STONE_BRICKS,
      CLAY,
      WOOD_LOG,
      LEAVES,
      COPPER,
      IRON,
      GOLD_ORE,
      COPPER_BLOCK,
      IRON_BLOCK,
      GOLD_BLOCK,
      BRICKS,
      SNOW,
      ICE,
      RUBY_BLOCK,
      PLATFORM,
      WORK_BENCH,
      GLASS,
      FURNACE,
      PAINTING,
      SAPLING,
      SNOW_BLUE_RUBY,
      BLUE_RUBY_BLOCK,
      DOOR,
      JAR,
      TABLE,
      WARDROBE,
      BOOKSHELF,
      SNOW_BRICKS,
      ICE_TABLE,
      ICE_WARDROBE,
      ICE_BOOKSHELF,
      ICE_PLATFORM,
      SAND_TABLE,
      SAND_WARDROBE,
      SAND_BOOKSHELF,
      SAND_PLATFORM,
      WOODEN_CHEST,
      ICE_CHEST,
      SAND_CHEST,
      BONE_CHEST,
      BONE_TABLE,
      BONE_WARDROBE,
      BONE_BOOKSHELF,
      BONE_PLATFORM,

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
