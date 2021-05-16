#include "Rules.h"
#include <iostream>
#define UP board->position[row - 1][col]
#define RIGHT board->position[row][col + 1]
#define DOWN board->position[row + 1][col]
#define LEFT board->position[row][col - 1]
#define QWIRKLE 6

using std::cout;
using std::endl;
using std::string;
using std::vector;

Rules::Rules()
{
}

// Check the legal move of a tile placed
bool Rules::boardRules(unsigned int row, unsigned int col, Board *board,
                       Colour colour, Shape shape, int turn)
{

    if (board->position[row][col]->tile != nullptr)
    {
        std::cout << std::endl;
        std::cout << "Cannot place the tile here." <<
        "There is already a tile on this position." << std::endl;
        return false;
    }

    if (turn == 0)
    {
        return true;
    }
    else
    {
        bool hasNeighbor = hasNeighbour(row, col, board);
        if (!hasNeighbor)
        {
            std::cout << std::endl;
            std::cout << "Cannot place the tile here." <<
            "Should have at least one neighbour." << std::endl;
            return false;
        }
        bool horizontalCheck = horCheck(row, col, board, colour, shape);
        bool verticalCheck = verCheck(row, col, board, colour, shape);
        if (horizontalCheck == false || verticalCheck == false)
        {
            return false;
        }
    }
    return true;
}

bool Rules::hasNeighbour(int row, int col, Board *board)
{
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
    {
        return false;
    }
    else if ((row - 1 >= 0 && UP->tile != nullptr)
        || (row + 1 <= BOARD_SIZE - 1 && DOWN->tile != nullptr )
        || (col - 1 >= 0 && LEFT->tile != nullptr )
        || (col + 1 <= BOARD_SIZE - 1 && RIGHT->tile != nullptr ))
    {
        return true;
    }
    
    return false;
}

bool Rules::verCheck(int row, int col, Board *board,
                     Colour colour, Shape shape)
{
    vector<string> verArray;
    // up check, add tile's colour and shape in the array
    int up = row - 1;
    string tmpStr = "";
    tmpStr += colour;
    tmpStr += shape + '0';
    verArray.push_back(tmpStr);
    while (up >= 0 && (board->position[up][col]->tile != nullptr))
    {
        tmpStr = "";
        tmpStr += board->position[up][col]->tile->colour;
        tmpStr += board->position[up][col]->tile->shape + '0';
        // if the tile is exsit in current array
        for (unsigned int index = 0; index < verArray.size(); index++)
        {
            if (verArray[index].compare(tmpStr) == 0)
            {
                return false;
                cout << "The tile is exsit." << endl;
            }
        }

        verArray.push_back(tmpStr);
        up--;
    }

    // down check, add tile's colour and shape in the array
    int down = row + 1;
    while (down <= BOARD_SIZE - 1 && (board->position[down][col]->tile != nullptr))
    {
        tmpStr = "";
        tmpStr += board->position[down][col]->tile->colour;
        tmpStr += board->position[down][col]->tile->shape + '0';
        for (unsigned int index = 0; index < verArray.size(); index++)
        {
            if (verArray[index].compare(tmpStr) == 0)
            {
                return false;
                cout << "The tile is exsit." << endl;
            }
        }

        verArray.push_back(tmpStr);
        down++;
    }
    unsigned int countColour = 0;
    unsigned int countShape = 0;
    // check the array, if the colours or the shapes are the same
    for (unsigned int index = 0; index < verArray.size(); index++)
    {
        if (verArray[index][0] == colour)
        {
            countColour++;
        }
        if (verArray[index][1] == (shape + '0'))
        {
            countShape++;
        }
    }

    if (countColour == verArray.size() || countShape == verArray.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Rules::horCheck(int row, int col, Board *board,
                     Colour colour, Shape shape)
{
    vector<string> horArray;
    // up check, add tile's colour and shape in the array
    int left = col - 1;
    string tmpStr = "";
    tmpStr += colour;
    tmpStr += shape + '0';
    horArray.push_back(tmpStr);
    while (left >= 0 && (board->position[row][left]->tile != nullptr))
    {
        tmpStr = "";
        tmpStr += board->position[row][left]->tile->colour;
        tmpStr += board->position[row][left]->tile->shape + '0';
        // if the tile is exsit in current array
        for (unsigned int index = 0; index < horArray.size(); index++)
        {
            if (horArray[index].compare(tmpStr) == 0)
            {
                return false;
                cout << "The tile is exsit." << endl;
            }
        }

        horArray.push_back(tmpStr);
        left--;
    }

    // down check, add tile's colour and shape in the array
    int right = col + 1;
    while (right <= BOARD_SIZE - 1 &&
           (board->position[row][right]->tile != nullptr))
    {
        tmpStr = "";
        tmpStr += board->position[row][right]->tile->colour;
        tmpStr += board->position[row][right]->tile->shape + '0';
        for (unsigned int index = 0; index < horArray.size(); index++)
        {
            if (horArray[index].compare(tmpStr) == 0)
            {
                return false;
                cout << "The tile is exsit." << endl;
            }
        }

        horArray.push_back(tmpStr);
        right++;
    }

    unsigned int countColour = 0;
    unsigned int countShape = 0;
    // check the array, if the colours or the shapes are the same
    for (unsigned int index = 0; index < horArray.size(); index++)
    {
        if (horArray[index][0] == colour)
        {
            countColour++;
        }
        if (horArray[index][1] == (shape + '0'))
        {
            countShape++;
        }
    }

    if (countColour == horArray.size() || countShape == horArray.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Calculate the player's score based on the tile they placed
// look for QWIRKLE!
int Rules::scoreRules(int row, int col, Board *board, int turn)
{
    int scores = 0;
    int verScores = 0;
    int horScores = 0;
    if (turn == 0)
    {
        return 1;
    }
    else
    {
        verScores = verScore(row, col, board);
        horScores = horScore(row, col, board);
    }
    scores = verScores + horScores;

    if (verScores == 6 || horScores == 6)
    {
        std::cout << std::endl;
        std::cout << "QWIRKLE!!!" << std::endl;
        std::cout << std::endl;
    }

    return scores;
}

int Rules::verScore(int row, int col, Board *board)
{
    vector<string> verArray;
    Colour colour = board->position[row][col]->tile->colour;
    Shape shape = board->position[row][col]->tile->shape;

    // up check, add tile's colour and shape in the array
    int up = row - 1;
    string tmpStr = "";
    tmpStr += colour;
    tmpStr += shape + '0';
    verArray.push_back(tmpStr);
    while (up >= 0 && (board->position[up][col]->tile != nullptr))
    {
        tmpStr = "";
        tmpStr += board->position[up][col]->tile->colour;
        tmpStr += board->position[up][col]->tile->shape + '0';

        verArray.push_back(tmpStr);
        up--;
    }

    // down check, add tile's colour and shape in the array
    int down = row + 1;
    while (down <= BOARD_SIZE - 1 && (board->position[down][col]->tile != nullptr))
    {
        tmpStr = "";
        tmpStr += board->position[down][col]->tile->colour;
        tmpStr += board->position[down][col]->tile->shape + '0';

        verArray.push_back(tmpStr);
        down++;
    }

    int score = verArray.size();
    if (score == QWIRKLE)
    {
        score += QWIRKLE;
    }
    if (score == 1)
    {
        score = 0;
    }

    return score;
}

int Rules::horScore(int row, int col, Board *board)
{
    vector<string> horArray;
    Colour colour = board->position[row][col]->tile->colour;
    Shape shape = board->position[row][col]->tile->shape;

    // up check, add tile's colour and shape in the array
    int left = col - 1;
    string tmpStr = "";
    tmpStr += colour;
    tmpStr += shape + '0';
    horArray.push_back(tmpStr);
    while (left >= 0 && (board->position[row][left]->tile != nullptr))
    {
        tmpStr = "";
        tmpStr += board->position[row][left]->tile->colour;
        tmpStr += board->position[row][left]->tile->shape + '0';

        horArray.push_back(tmpStr);
        left--;
    }

    // down check, add tile's colour and shape in the array
    int right = col + 1;
    while (right <= BOARD_SIZE - 1 &&
           (board->position[row][right]->tile != nullptr))
    {
        tmpStr = "";
        tmpStr += board->position[row][right]->tile->colour;
        tmpStr += board->position[row][right]->tile->shape + '0';

        horArray.push_back(tmpStr);
        right++;
    }

    int score = horArray.size();
    if (score == QWIRKLE)
    {
        score += QWIRKLE;
    }
    if (score == 1)
    {
        score = 0;
    }
    return score;
}
