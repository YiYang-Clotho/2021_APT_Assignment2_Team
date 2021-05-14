#include "Rules.h"

#include <iostream>

#define UP      board->position[hor - 1][ver]
#define RIGHT   board->position[hor][ver + 1]
#define DOWN    board->position[hor + 1][ver]
#define LEFT    board->position[hor][ver - 1]
#define QWIRKLE 6

using std::cout;
using std::endl;
using std::vector;

Rules::Rules(){
    
}

// Check the legal move of a tile placed
bool Rules::boardRules(unsigned int row, unsigned int col, Board *board, 
                Colour colour, Shape shape, int turn)
{
    bool check = true;
    bool upVerticalLine = true;
    bool downVerticalLine = true;
    bool leftHorizontalLine = true;
    bool rightHorizontalLine = true; 
     
    if (turn == 0)
    {
        return check;
    }
    else
    {
        for (unsigned int hor = 0; hor < BOARD_SIZE; hor++)
        {
            for (unsigned int ver = 0; ver < BOARD_SIZE; ver++)
            {
                if (hor == row && ver == col)
                {
                    // if you want to put to Upper left corner
                    if (row == 0 && col == 0)
                    {
                        if (DOWN->tile != nullptr)
                        {
                            downVerticalLine = downVerCheck(row, col, 
                                                    board, colour, shape);
                        }
                        if (RIGHT->tile != nullptr)
                        {
                            rightHorizontalLine = rightHorCheck(row, col, 
                                                    board, colour, shape);
                        }
                        if (DOWN->tile == nullptr && RIGHT->tile == nullptr)
                        {
                            check = false;
                        }
                        if(downVerticalLine == false
                                    || rightHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }

                    // if you want to put to Upper right corner
                    if (row == 0 && col == BOARD_SIZE - 1)
                    {
                        if (DOWN->tile == nullptr && LEFT->tile == nullptr)
                        {
                            std::cout << "check: " << check << std::endl;
                            check = false;
                            std::cout << "check: " << check << std::endl;
                        }
                        if (DOWN->tile != nullptr)
                        {
                            downVerticalLine = downVerCheck(row, col, 
                                                board, colour, shape);
                            std::cout << "down: " << downVerticalLine << std::endl;
                        }
                        if (LEFT->tile != nullptr)
                        {
                            leftHorizontalLine = leftHorCheck(row, col, 
                                                board, colour, shape);
                            std::cout << "left: " << leftHorizontalLine << std::endl;
                        }
                        if(downVerticalLine == false
                                    || leftHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }

                    // if you want to put to Bottom left corner
                    if (row == BOARD_SIZE - 1 && col == 0)
                    {
                        if (UP->tile == nullptr && RIGHT->tile == nullptr)
                        {
                            check = false;
                        }
                        if (UP->tile != nullptr)
                        {
                            upVerticalLine = upVerCheck(row, col, 
                                                board, colour, shape);
                        }
                        if (RIGHT->tile != nullptr)
                        {
                            rightHorizontalLine = rightHorCheck(hor, ver, 
                                                board, colour, shape);
                        }
                        if(upVerticalLine == false 
                            || rightHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }

                    // if you want to put to Bottom right corner
                    if (row == BOARD_SIZE - 1 && col == BOARD_SIZE - 1)
                    {
                        if (UP->tile == nullptr && LEFT->tile == nullptr)
                        {
                            check = false;
                        }
                        if (UP->tile != nullptr)
                        {
                            upVerticalLine = upVerCheck(row, col, 
                                                board, colour, shape);
                        }
                        if (LEFT->tile != nullptr)
                        {
                            leftHorizontalLine = leftHorCheck(row, col, 
                                            board, colour, shape);
                        }
                        if(upVerticalLine == false 
                            || leftHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }

                    // if you want to put to upper aside
                    if (row == 0 && (col > 0 && col < BOARD_SIZE - 1))
                    {
                        if (DOWN->tile == nullptr && RIGHT->tile == nullptr
                                && LEFT->tile == nullptr)
                        {
                            check = false;
                        }
                        if (DOWN->tile != nullptr)
                        {
                            downVerticalLine = downVerCheck(row, col, 
                                            board, colour, shape);
                        }
                        if (LEFT->tile != nullptr)
                        {
                            leftHorizontalLine = leftHorCheck(row, col, 
                                            board, colour, shape);
                        }

                        if (RIGHT->tile != nullptr)
                        {
                            rightHorizontalLine = rightHorCheck(row, col, 
                                            board, colour, shape);
                        }
                        if(downVerticalLine == false
                                    || leftHorizontalLine == false 
                                            || rightHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }

                    // if you want to put to bottom aside
                    if (row == BOARD_SIZE - 1 && 
                                        (col > 0 && col < BOARD_SIZE - 1))
                    {
                        if (UP->tile == nullptr && RIGHT->tile == nullptr
                                && LEFT->tile == nullptr)
                        {
                            check = false;
                        }
                        if (UP->tile != nullptr)
                        {
                            upVerticalLine = upVerCheck(row, col, 
                                            board, colour, shape);
                        }
                        if (LEFT->tile != nullptr)
                        {
                            leftHorizontalLine = leftHorCheck(row, col, 
                                                        board, colour, shape);
                        }
                        if (RIGHT->tile != nullptr)
                        {
                            rightHorizontalLine = rightHorCheck(row, col, 
                                                board, colour, shape);
                        }
                        if(upVerticalLine == false 
                            || leftHorizontalLine == false 
                                            || rightHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }
                    // if you want to put to left aside
                    if ((row > 0 && row < BOARD_SIZE - 1) 
                                                && col == 0)
                    {
                        if (DOWN->tile == nullptr && RIGHT->tile == nullptr
                                && UP->tile == nullptr)
                        {
                            check = false;
                        }
                        if (RIGHT->tile != nullptr)
                        {
                            rightHorizontalLine = rightHorCheck(row, col, 
                                            board, colour, shape);
                        }
                        if (DOWN->tile != nullptr)
                        {
                            downVerticalLine = downVerCheck(row, col, 
                                            board, colour, shape);
                        }
                        if (UP->tile != nullptr)
                        {
                            upVerticalLine = upVerCheck(row, col, 
                                            board, colour, shape);
                        }
                        if(upVerticalLine == false 
                            || downVerticalLine == false
                                    || rightHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }

                    // if you want to put to right aside
                    if ((row > 0 && row < BOARD_SIZE - 1) 
                                                && col == BOARD_SIZE - 1)
                    {
                        if (DOWN->tile == nullptr && LEFT->tile == nullptr
                                && UP->tile == nullptr)
                        {
                            check = false;
                        }
                        if (LEFT->tile != nullptr)
                        {
                            leftHorizontalLine = leftHorCheck(row, col, 
                                            board, colour, shape);
                        }
                        if (DOWN->tile != nullptr)
                        {
                            downVerticalLine = downVerCheck(row, col, 
                                            board, colour, shape);
                        }
                        if (UP->tile != nullptr)
                        {
                            upVerticalLine = upVerCheck(row, col, 
                                            board, colour, shape);
                        }

                        if(upVerticalLine == false 
                            || downVerticalLine == false
                                    || leftHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }

                    // if you want to put in the middle
                    if (row != 0 && col != 0 && row != BOARD_SIZE - 1 
                                            && col != BOARD_SIZE - 1)
                    {
                        if (DOWN->tile == nullptr && LEFT->tile == nullptr
                                && UP->tile == nullptr && RIGHT->tile == nullptr)
                        {
                            check = false;
                        }
                        if (RIGHT->tile != nullptr)
                        {
                            rightHorizontalLine = rightHorCheck(row, col, 
                                                board, colour, shape);
                        }
                        if (LEFT->tile != nullptr)
                        {
                            leftHorizontalLine = leftHorCheck(row, col, 
                                            board, colour, shape);
                        }
                        if (DOWN->tile != nullptr)
                        {
                            std::cout << "down check1: " << downVerticalLine << std::endl;
                            downVerticalLine = downVerCheck(row, col, 
                                                board, colour, shape);
                            std::cout << "down check2: " << downVerticalLine << std::endl;
                        }
                        if (UP->tile != nullptr)
                        {
                            upVerticalLine = upVerCheck(row, col, 
                                            board, colour, shape);
                        }
                        std::cout << "check0: " << check << std::endl;

                        if(upVerticalLine == false 
                            || downVerticalLine == false
                                    || leftHorizontalLine == false 
                                            || rightHorizontalLine == false)
                        {
                            std::cout << "check1: " << check << std::endl;
                            check = false;
                            std::cout << "check2: " << check << std::endl;
                        }
                    }
                }
            }
        }

        if (board->position[row][col]->tile != nullptr)
        {
            check = false;
        }

        std::cout << "check3: " << check << std::endl;
        return check;
    }
}

//check any common field between the current tile on left
bool Rules::rightHorCheck(int row, int col, Board *board, 
                                Colour colour, Shape shape)
{
    std::string colourStr = "colour";
    std::string shapeStr = "shape";
    std::string common = "";
    bool check = true;
    // Determine the adjacent tiles on the right, 
    // two tiles cannot be empty and should have same colour or shape
    if(board->position[row][col + 1]->tile != nullptr
        && board->position[row][col + 2]->tile != nullptr)
    {
        // same colour
        if(board->position[row][col + 1]->tile->colour == 
                board->position[row][col + 2]->tile->colour)
        {
            common = "colour";
        }
        // same shape
        if(board->position[row][col + 1]->tile->shape == 
                board->position[row][col + 2]->tile->shape)
        {
            common = "shape";
        }
    }
    // only have one tile on the right
    else if(board->position[row][col + 1]->tile != nullptr
            && ( board->position[row][col + 2]->tile == nullptr 
                || col == BOARD_SIZE - 1 ))
    {
        // same colour
        if(board->position[row][col + 1]->tile->colour == colour)
        {
            common = "colour";
        }
        // same shape
        else if(board->position[row][col + 1]->tile->shape == shape)
        {
            common = "shape";
        }
    }
    if(common.compare("colour") == 0 
            && (colour != board->position[row][col + 1]->tile->colour))
    {
        check = false;
    }
    
    if(common.compare("shape") == 0 
            && (shape != board->position[row][col + 1]->tile->shape))
    {
        check = false;
    }
    // check is false if there's no common shape or colour
    if(common.compare("") == 0)
    {
        check = false;
    }

    if(check == true)
    {
        check = rightDuplicat(row, col, board, colour, shape);
    }

    return check;
}

//check any common field between the current tile and below
bool Rules::downVerCheck(int row, int col, Board *board, 
                                Colour colour, Shape shape)
{
    std::string colourStr = "colour";
    std::string shapeStr = "shape";
    bool check = true;
    std::string common = "";
   std::cout << "check ver1: " << check << std::endl;
    // Determine the adjacent tiles on the right, 
    // two tiles cannot be empty and should have same colour or shape
    if(board->position[row + 1][col]->tile != nullptr
        && board->position[row + 2][col]->tile != nullptr)
    {
        // same colour
        if(board->position[row + 1][col]->tile->colour == 
                board->position[row + 2][col]->tile->colour)
        {
            common = "colour";
        }
        // same shape
        if(board->position[row + 1][col]->tile->shape == 
                board->position[row + 2][col]->tile->shape)
        {
            common = "shape";
        }
    }
    // only have one tile at the bottom
    else if(board->position[row + 1][col]->tile != nullptr
            && ( board->position[row + 2][col]->tile == nullptr 
                || row == BOARD_SIZE || row + 2 == BOARD_SIZE))
    {
        // same colour
        if(board->position[row + 1][col]->tile->colour == colour)
        {
            std::cout << "colour same" << std::endl;
            common = "colour";
        }
        // same shape
        else if(board->position[row + 1][col]->tile->shape == shape)
        {
            std::cout << "shape same" << std::endl;
            common = "shape";
        }
    }
    std::cout << common << std::endl;

    if(common.compare("colour") == 0 
            && (colour != board->position[row + 1][col]->tile->colour))
    {
        check = false;
    }
    
    if(common.compare("shape") == 0 
            && (shape != board->position[row + 1][col]->tile->shape))
    {
        check = false;
    }
    // check is false if there's no common shape or colour
    if(common.compare("") == 0)
    {
        check = false;
    }

    std::cout << "check ver1: " << check << std::endl;

    if(check == true)
    {
        std::cout << "check dup1: " << check << std::endl;
        check = downDuplicat(row, col, board, colour, shape);
        std::cout << "check dup2: " << check << std::endl;
    }

    return check;
}

//Helper method - check any common field between the current tile and the one upper if not empty
bool Rules::upVerCheck(int row, int col, Board *board, 
                            Colour colour, Shape shape)
{
    std::string colourStr = "colour";
    std::string shapeStr = "shape";
    bool check = true;
    std::string common = "";
   
        // Determine the adjacent tiles on the right, 
    // two tiles cannot be empty and should have same colour or shape
    if(board->position[row - 1][col]->tile != nullptr
        && board->position[row - 2][col]->tile != nullptr)
    {
        // same colour
        if(board->position[row - 1][col]->tile->colour == 
                board->position[row - 2][col]->tile->colour)
        {
            common = "colour";
        }
        // same shape
        if(board->position[row - 1][col]->tile->shape == 
                board->position[row - 2][col]->tile->shape)
        {
            common = "shape";
        }
    }
    // only have one tile on the right
    else if(board->position[row - 1][col]->tile != nullptr
            && ( board->position[row - 2][col]->tile == nullptr 
                || row == 0 ))
    {
        // same colour
        if(board->position[row - 1][col]->tile->colour == colour)
        {
            common = "colour";
        }
        // same shape
        else if(board->position[row - 1][col]->tile->shape == shape)
        {
            common = "shape";
        }
    }
    if(common.compare("colour") == 0 
            && (colour != board->position[row - 1][col]->tile->colour))
    {
        check = false;
    }
    
    if(common.compare("shape") == 0 
            && (shape != board->position[row - 1][col]->tile->shape))
    {
        check = false;
    }
    // check is false if there's no common shape or colour
    if(common.compare("") == 0)
    {
        check = false;
    }

    if(check == true)
    {
        check = upDuplicat(row, col, board, colour, shape);
    }

    return check;
}

// check any common field between the current tile and the left hand side
// if not return empty
bool Rules::leftHorCheck(int row, int col, Board *board, 
                                Colour colour, Shape shape)
{
    std::string colourStr = "colour";
    std::string shapeStr = "shape";
    std::string common = "";
    bool check = true;
    // Determine the adjacent tiles on the right, 
    // two tiles cannot be empty and should have same colour or shape
    if(board->position[row][col - 1]->tile != nullptr
        && board->position[row][col - 2]->tile != nullptr)
    {
        // same colour
        if(board->position[row][col - 1]->tile->colour == 
                board->position[row][col - 2]->tile->colour)
        {
            common = "colour";
        }
        // same shape
        if(board->position[row][col - 1]->tile->shape == 
                board->position[row][col - 2]->tile->shape)
        {
            common = "shape";
        }
    }
    // only have one tile on the right
    else if(board->position[row][col - 1]->tile != nullptr
            && ( board->position[row][col - 2]->tile == nullptr 
                || col == 0 ))
    {
        // same colour
        if(board->position[row][col - 1]->tile->colour == colour)
        {
            common = "colour";
        }
        // same shape
        else if(board->position[row][col - 1]->tile->shape == shape)
        {
            common = "shape";
        }
    }
    if(common.compare("colour") == 0 
            && (colour != board->position[row][col - 1]->tile->colour))
    {
        check = false;
    }
    
    if(common.compare("shape") == 0 
            && (shape != board->position[row][col - 1]->tile->shape))
    {
        check = false;
    }
    // check is false if there's no common shape or colour
    if(common.compare("") == 0)
    {
        check = false;
    }

    if(check == true)
    {
        check = leftDuplicat(row, col, board, colour, shape);
    }

    return check;
}

// check for duplication - for loop through the right hand of the board
bool Rules::rightDuplicat(int row, int col, Board *board, 
                            Colour colour, Shape shape)
{
    bool check = true;
    bool flag = true;
    int exist = 0;
    // check list number
    for(int counter = col + 1; counter <= BOARD_SIZE - 1; counter++)
    {
        if(board->position[row][counter]->tile != nullptr)
        {
            exist++;
        }
    }

    if (exist >= 6)
    {
        check = false;
    }
    else
    {
        // check the same tile
        for(int counter = col + 1; 
                            counter <= col + exist; counter++)
        {
            if(board->position[row][counter]->tile->colour == colour
                && board->position[row][counter]->tile->shape == shape)
            {
                check = false;
                flag = check;
            }
        }
    }

    if (flag == false)
    {
        return flag;
    }
    else
    {
        return true;
    }
}

// check for duplication - for loop through the down hand of the board
bool Rules::downDuplicat(int row, int col, Board *board, 
                            Colour colour, Shape shape)
{
    bool check = true;
    bool flag = true;
    int exist = 0;

    std::cout << "exist: " << exist << std::endl;

    // check list number
    for(int counter = row + 1; counter <= BOARD_SIZE - 1; counter++)
    {
        if(board->position[counter][col]->tile != nullptr)
        {
            exist++;
        }
    }
    std::cout << "exist: " << exist << std::endl;
    
    if (exist > 5)
    {
        check = false;
    }
    else
    {
        // check the same tile
        for(int counter = row + 1; counter <= row + exist; counter++)
        {
            if(board->position[counter][col]->tile->colour == colour
                && board->position[counter][col]->tile->shape == shape)
            {
                check = false;
                flag = check;
            }
        }
    }

    std::cout << "flag1: " << flag << std::endl;

    if (flag == false)
    {
        return flag;
        std::cout << "flag2: " << flag << std::endl;
    }
    else
    {
        return true;
        std::cout << "true" << std::endl;
    }
}

//check for duplication - for loop throught the left hand of board
bool Rules::leftDuplicat(int row, int col, Board *board,
                                    Colour colour, Shape shape)
{
    bool check = true;
    bool flag = true;
    int exist = 0;
    // check list number
    for(int counter = col - 1; counter >= 0; counter--)
    {
        if(board->position[row][counter]->tile != nullptr)
        {
            exist++;
        }
    }

    if (exist >= 6)
    {
        check = false;
    }
    else
    {
        // check the same tile
        for(int counter = col - 1; 
                            counter >= col - exist; counter--)
        {
            if(board->position[row][counter]->tile->colour == colour
                && board->position[row][counter]->tile->shape == shape)
            {
                check = false;
                flag = check;
            }
        }
    }

    if (flag == false)
    {
        return flag;
    }
    else
    {
        return true;
    }
}

// check for duplication - for loop throught the upper hand of board
bool Rules::upDuplicat(int row, int col, Board *board, 
                            Colour colour, Shape shape)
{
    bool check = true;
    bool flag = true;
    int exist = 0;

    // check list number
    for(int counter = row - 1; counter >= 0; counter--)
    {
        if(board->position[counter][col]->tile != nullptr)
        {
            exist++;
        }
    }
    
    if (exist > 5)
    {
        check = false;
    }
    else
    {
        // check the same tile
        for(int counter = row - 1; counter >= row - exist; counter--)
        {
            if(board->position[counter][col]->tile->colour == colour
                && board->position[counter][col]->tile->shape == shape)
            {
                check = false;
                flag = check;
            }
        }
    }

    if (flag == false)
    {
        return flag;
    }
    else
    {
        return true;
    }
}

// Calculate the player's score based on the tile they placed
// look for QWIRKLE!
int Rules::scoreRules(unsigned int row, unsigned int col, Board *board, int turn){
    int score = 0;
    int upScore = 1; 
    int downScore = 1; 
    int leftScore = 1;
    int rightScore = 1;
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
                std::cout << "downScore: " << downScore << std::endl;
                std::cout << "rightScore: " << rightScore << std::endl;
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
                std::cout << "downScore: " << downScore << std::endl;
                std::cout << "rightScore: " << rightScore << std::endl;
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

        if((col != 0 && col != BOARD_SIZE - 1) 
                && (row == 0 || row == BOARD_SIZE - 1))
        {
            // the tile is on the first row, check vertical and right
            if(row == 0)
            {
                leftScore += leftTileScore(row, col, board);
                rightScore += rightTileScore(row, col, board);
                downScore += downTileScore(row, col, board);
                std::cout << "downScore: " << downScore << std::endl;
                std::cout << "rightScore: " << rightScore << std::endl;
                std::cout << "leftScore: " << leftScore << std::endl;
            }
            // the tile is on the last row, check vertical and left
            else if(row == BOARD_SIZE - 1)
            {
                leftScore += leftTileScore(row, col, board);
                rightScore += rightTileScore(row, col, board);
                upScore += upTileScore(row, col, board);
            }
        }
        // the tile is in the middle, check 4 direction
        if((row != 0 && row != BOARD_SIZE - 1) 
                    && (col != 0 && col != BOARD_SIZE - 1))
        {
            upScore += upTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
            leftScore += leftTileScore(row, col, board);
            downScore += downTileScore(row, col, board);
        }

    }

    if(upScore > 1)
    {
        score += upScore;
    }
    if(downScore > 1)
    {
        score += downScore;
    }
    if(leftScore > 1)
    {
        score += leftScore;
    }
    if(rightScore > 1)
    {
        score += rightScore;
    }
    if(qwirkle == true)
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
    for(int counter = col + 1; counter < BOARD_SIZE - 1; counter++)
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
        qwirkle = true;
    }

    return score;
}

// check tile number below the current tile
int Rules::downTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty = false;
    for(int counter = row + 1; counter <= BOARD_SIZE; counter++)
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
        qwirkle = true;
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
        qwirkle = true;
    }
    return score;
}

// check any tile upper the current tile
int Rules::upTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty = false;
    for(unsigned int counter = row - 1; counter >= 0; counter--)
    {
        if(board->position[counter][col]->tile != nullptr
            && empty == false)
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
        qwirkle = true;
    }
    return score;
}