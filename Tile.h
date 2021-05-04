
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <string>
// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:

   Tile(std::string empty);
   Tile(Colour colour, Shape shape);
   Colour getColour();
   Shape getShape();
   std::string getEmpty();

private:
    Colour colour = '\0';
    Shape  shape = 0;
    std::string empty = "";
};

#endif // ASSIGN2_TILE_H
