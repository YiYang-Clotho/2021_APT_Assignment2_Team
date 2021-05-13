#ifndef ASSIGN2_RULES_H
#define ASSIGN2_RULES_H

#include "Tile.h"
#include "Player.h"

using std::vector;

class Rules{
public: 
    Rules();
    bool boardRules(unsigned int rowsInt, unsigned int columns, Board *board, Tile* tile, int turn);

    bool rightDuplicat(int rows, int columns, Board *board, Tile* tile);
    bool downDuplicat(int rows, int columns, Board *board, Tile* tile);
    bool leftDuplicat(int rows, int columns, Board *board, Tile* tile);
    bool upDuplicat(int rows, int columns, Board *board, Tile* tile);

    bool rightCheck(int rows, int columns, Board *board, Tile* tile);
    bool downCheck(int rows, int columns, Board *board, Tile* tile);
    bool leftCheck(int rows, int columns, Board *board, Tile* tile);
    bool upCheck(int rows, int columns, Board *board, Tile* tile);
    
    
    int scoreRules(unsigned int rowsInt, unsigned int columns, Board *board, int turn);
    int downTileScore(int rowsInt, int columns, Board *board);
    int rightTileScore(int rowsInt, int columns, Board *board);
    int leftTileScore(int rowsInt, int columns, Board *board);
    int upTileScore(int rowsInt, int columns, Board *board);

private:
    bool qwirkle = false;
};

#endif //
ASSIGN2_RULES_H