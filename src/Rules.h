#ifndef ASSIGN2_RULES_H
#define ASSIGN2_RULES_H

#include "Tile.h"
#include "Player.h"

using std::vector;

class Rules
{
public:
    Rules();
    bool boardRules(unsigned int row, unsigned int col, Board *board,
                    Colour colour, Shape shape, int turn);

    bool verCheck(int row, int col, Board *board,
                  Colour colour, Shape shape);
    bool horCheck(int row, int col, Board *board,
                  Colour colour, Shape shape);
    bool hasNeighbour(int row, int col, Board *board);

    int scoreRules(int row, int col, Board *board, int turn);
    int verScore(int row, int col, Board *board);
    int horScore(int row, int col, Board *board);

private:
};

#endif //
ASSIGN2_RULES_H