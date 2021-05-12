
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H
#include <vector>
#include "Types.h"
using namespace std;

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile
{
public:
   Tile();
   Tile(Colour colour, Shape shape);
   Tile(Tile &other);
   Colour colour;
   Shape shape;
   ~Tile();

   // get colour of the tile
   Colour getColour();

   // get shape of the tile
   Shape getShape();

private:
   Colour colour = '\0';
   Shape  shape = 0;
   std::string empty = "";
};

#endif // ASSIGN2_TILE_H
