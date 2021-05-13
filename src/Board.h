#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Types.h"
#include "Node.h"
using std::vector;

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

   vector<vector<Node*> > position;

private:
   
};

#endif // ASSIGN2_BOARD_H