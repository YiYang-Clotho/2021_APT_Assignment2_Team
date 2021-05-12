#ifndef ASSIGN2_RULES_H
#define ASSIGN2_RULES_H

#include "Tile.h"
#include "Board.h"
#include "Player.h"
#include <vector>

using std::vector;

class Rules{
public: 
    Rules();
    bool boardRules(unsigned int rowsInt, unsigned int columns, vector<vector<Tile*>> board, Tile* tile, int turn);

    bool rightDuplicationTiles(int rows, int columns, vector<vector<Tile*>> board, Tile* tile);
    bool downDuplicationTiles(int rows, int columns, vector<vector<Tile*>> board, Tile* tile);
    bool leftDuplicationTiles(int rows, int columns, vector<vector<Tile*>> board, Tile* tile);
    bool upDuplicationTiles(int rows, int columns, vector<vector<Tile*>> board, Tile* tile);

    bool rightVerticalLineCheck(int rows, int columns, vector<vector<Tile*>> board, Tile* tile);
    bool downVerticalLineCheck(int rows, int columns, vector<vector<Tile*>> board, Tile* tile);
    bool leftVerticalLineCheck(int rows, int columns, vector<vector<Tile*>> board, Tile* tile);
    bool upVerticalLineCheck(int rows, int columns, vector<vector<Tile*>> board, Tile* tile);
    
    
    int scoreRules(unsigned int rowsInt, unsigned int columns, vector<vector<Tile*>> board, int turn);
    int downTileScore(int rowsInt, int columns, vector<vector<Tile*>> board);
    int rightTileScore(int rowsInt, int columns, vector<vector<Tile*>> board);
    int leftTileScore(int rowsInt, int columns, vector<vector<Tile*>> board);
    int upTileScore(int rowsInt, int columns, vector<vector<Tile*>> board);

private:
    bool qwirkle = false;
};

#endif //
ASSIGN2_RULES_H