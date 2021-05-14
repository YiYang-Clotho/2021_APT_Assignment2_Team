#ifndef ASSIGN2_RULES_H
#define ASSIGN2_RULES_H

#include "Tile.h"
#include "Player.h"

using std::vector;

class Rules{
public: 
    Rules();
    bool boardRules(unsigned int row, unsigned int col, Board *board,
                Colour colour, Shape shape, int turn);

    bool verCheck(int row, int col, Board *board, 
                            Colour colour, Shape shape);
    bool horCheck(int row, int col, Board *board, 
                            Colour colour, Shape shape);
    
    
    int scoreRules(int rowsInt, int columns, Board *board, int turn);
    int downTileScore(int rowsInt, int columns, Board *board);
    int rightTileScore(int rowsInt, int columns, Board *board);
    int leftTileScore(int rowsInt, int columns, Board *board);
    int upTileScore(int rowsInt, int columns, Board *board);

private:
    bool qwirkle = false;
};

#endif //
ASSIGN2_RULES_H