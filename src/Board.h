#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Tile.h"
#include "Types.h"
<<<<<<< HEAD:src/Board.h
#include "Node.h"
using std::vector;
=======
>>>>>>> 4ca592634ea308da6e6f7af8c7a7d68796ec1e16:starter_code/Board.h

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

   vector<vector<Node*> > position;

private:
<<<<<<< HEAD:src/Board.h
   
=======
   vector<vector<char> > position;
   Tile *tile;
   int row;
   int col;
>>>>>>> 4ca592634ea308da6e6f7af8c7a7d68796ec1e16:starter_code/Board.h
};

#endif // ASSIGN2_BOARD_H
