#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H
using std::vector;

#include <vector>
#include "Types.h"

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Board
{
public:
   Board();
   Board(Board &other);
   ~Board();
   
   // print current board
   void printBoard();

   // save the position of the tile
   void putTile2Board(Colour colour, Shape shape, int row, int col);

private:
   vector<vector<char> > position;
};

#endif // ASSIGN2_BOARD_H
