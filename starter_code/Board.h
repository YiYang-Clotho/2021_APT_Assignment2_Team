#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Tile.h"
#include "Types.h"
#include <iostream>
#include <vector>
using namespace std;

class Board
{
public:
   Board();
   Board(Board &other);
   ~Board();
   
   // print current board
   vector<vector<char> > printBoard();

   // save the position of the tile
   void putTile2Board(Tile *tile, vector<vector<char> > position);

private:
   //Tile* tile;
   vector<vector<char> > position;
   int row;
   int col;
};

#endif // ASSIGN2_BOARD_H
