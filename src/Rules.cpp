#include "Rules.h"
#include <iostream>
#define QWIRKLE 6

using std::cout;
using std::endl;
using std::vector;
using std::string;

Rules::Rules(){
    
}

// Check the legal move of a tile placed
bool Rules::boardRules(unsigned int row, unsigned int col, Board *board, 
                Colour colour, Shape shape, int turn)
{
    bool check = true;
     
    if (turn == 0)
    {
        return check;
    }
    else
    {
        bool horizontalCheck = horCheck(row, col, board, colour, shape);
        bool verticalCheck = verCheck(row, col, board, colour, shape);

        if (horizontalCheck == false || verticalCheck == false)
        {
            check = false;
        }
        
    }

    if (board->position[row][col]->tile != nullptr)
    {
        check = false;
    }

    return check;
    
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
    while (up >= 0 
                && (board->position[up][col]->tile != nullptr))
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
    while (down <= BOARD_SIZE - 1 
                && (board->position[down][col]->tile != nullptr))
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
int Rules::scoreRules(int row, int col, Board *board, int turn){
    int score = 0;
    int upScore = 0; 
    int downScore = 0; 
    int leftScore = 0;
    int rightScore = 0;
    if(turn == 0)
    {
        score = 1;
    }
    else
    {
        // if current tile is on the first col
        if(col == 0)
        {
            // if it's on the first row, check right and down
            if(row == 0)
            {
                downScore += downTileScore(row, col, board);
                rightScore += rightTileScore(row, col, board);
            }
            // if it's on the last row, check right and up
            else if(row == BOARD_SIZE - 1)
            {
                upScore += upTileScore(row, col, board);
                rightScore += rightTileScore(row, col, board);
            }
            // if it's in the middle, check vertical and right
            else
            {
                downScore += downTileScore(row, col, board);
                rightScore += rightTileScore(row, col, board);
                upScore += upTileScore(row, col, board);
            } 
        }
        // if current tile is on the last col
        else if(col == BOARD_SIZE - 1)
        {
            // if it's on the first row, check left and down
            if(row == 0)
            {
                downScore += downTileScore(row, col, board);
                leftScore += leftTileScore(row, col, board);
            }
            // if it's on the last row, check left and up
            else if(row == BOARD_SIZE - 1)
            {
                upScore += upTileScore(row, col, board);
                leftScore += leftTileScore(row, col, board);
            }
            // if it's in the middle, check vertival and left
            else
            {
                upScore += upTileScore(row, col, board);
                downScore += downTileScore(row, col, board);
                leftScore += leftTileScore(row, col, board);
            } 
        }

        if(col != 0 && col != BOARD_SIZE - 1)
        {
            // the tile is on the first row, check horizont and down
            if(row == 0)
            {
                leftScore += leftTileScore(row, col, board);
                rightScore += rightTileScore(row, col, board);
                downScore += downTileScore(row, col, board);
            }
            // the tile is on the last row, check horizont and up
            else if(row == BOARD_SIZE - 1)
            {
                leftScore += leftTileScore(row, col, board);
                rightScore += rightTileScore(row, col, board);
                upScore += upTileScore(row, col, board);
            }
        }
        
        // the tile is in the middle, check 4 direction
        if(row != 0 && row != BOARD_SIZE - 1
                    && col != 0 && col != BOARD_SIZE - 1)
        {
            upScore += upTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
            leftScore += leftTileScore(row, col, board);
            downScore += downTileScore(row, col, board);
        }

    }
    if (upScore > 0)
    {
        upScore++;
    }
    if (downScore > 0)
    {
        downScore++;
    }
    if (leftScore > 0)
    {
        leftScore++;
    }
    if (rightScore > 0)
    {
        rightScore++;
    }
    score += upScore;
    score += downScore;
    score += leftScore;
    score += rightScore;
    if(this->qwirkle == true)
    {
        score += QWIRKLE;
        cout << "QWIRKLE!!!" << endl;
    }

    return score;
}

// check tile number on the right hand side of the current tile
int Rules::rightTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty =  false;
    for(int counter = col + 1; counter <= BOARD_SIZE - 1; counter++)
    {
        if(board->position[row][counter]->tile != nullptr && empty == false)
        {
            score++;
        }
        else
        {
            empty = true;
        }    
    }

    if(score == 5)
    {
        this->qwirkle = true;
    }

    return score;
}

// check tile number below the current tile
int Rules::downTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty = false;
    for(int counter = row + 1; counter <= BOARD_SIZE - 1; counter++)
    {
       if( board->position[counter][col]->tile != nullptr && empty == false)
        {
            score++;
        }
        else
        {
            empty = true;
        }
    }
    if(score == 5)
    {
        this->qwirkle = true;
    }

    return score;
}

// check tile number on the left hand side of the current tile
int Rules::leftTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty = false;
    for(int counter = col - 1; counter >= 0; counter--)
    {
        if(board->position[row][counter]->tile != nullptr && empty == false)
        {
            score++;
        }
        else
        {
            empty = true;
        }
    }
    if(score == 5)  
    {
        this->qwirkle = true;
    }

    return score;
}

// check any tile upper the current tile
int Rules::upTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty = false;
    for(int counter = row - 1; counter >= 0; counter--)
    {
        if(board->position[counter][col]->tile != nullptr && empty == false)
        {
            score++;
        }
        else
        {
            empty = true;
        }     
    }
    if(score == 5)
    {
        this->qwirkle = true;
    }

    return score;
}