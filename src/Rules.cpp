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
                    if (hor == 0 && ver == 0)
                    {
                        if (DOWN->tile != nullptr)
                        {
                            downVerticalLine = downVerCheck(hor, ver, 
                                                    board, colour, shape);
                            std::cout << "check down: " << downVerticalLine << std::endl;
                            
                        }
                        if (RIGHT->tile != nullptr)
                        {
                            rightHorizontalLine = rightHorCheck(hor, ver, 
                                                    board, colour, shape);
                            std::cout << "check right: " << rightHorizontalLine << std::endl;
                        }
                            
                        if (DOWN->tile == nullptr && RIGHT->tile != nullptr)
                        {
                            check = false;
                        }
                        
                    }

                    // if you want to put to Upper right corner
                    if (hor == BOARD_SIZE - 1 && ver == BOARD_SIZE - 1)
                    {
                        if (DOWN->tile == nullptr && LEFT->tile == nullptr)
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
                    }

                    // if you want to put to Bottom left corner
                    if (hor == 0 && ver == BOARD_SIZE - 1)
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
                        if (RIGHT->tile != nullptr)
                        {
                            rightHorizontalLine = rightHorCheck(hor, ver, 
                                                board, colour, shape);
                        }
                    }

                    // if you want to put to Bottom right corner
                    if (hor == BOARD_SIZE - 1 && ver == BOARD_SIZE - 1)
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
                        if (LEFT->tile != nullptr)
                        {
                            leftHorizontalLine = leftHorCheck(row, col, 
                                            board, colour, shape);
                        }
                    }

                    // if you want to put to upper aside
                    if (hor != 0 && ver == 0)
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
                    }

                    // if you want to put to bottom aside
                    if (hor != 0 && ver == BOARD_SIZE - 1)
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
                    }
                    // if you want to put to left aside
                    if (hor == 0 && ver != 0)
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
                    }

                    // if you want to put to right aside
                    if (hor == 0 && ver != 0)
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
                    }

                    // if you want to put in the middle
                    if (hor == 0 && ver != 0)
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
                            downVerticalLine = downVerCheck(row, col, 
                                                board, colour, shape);
                        }
                        if (UP->tile != nullptr)
                        {
                            upVerticalLine = upVerCheck(row, col, 
                                            board, colour, shape);
                        }
                        
                    }
                }
            }
        }

        if(upVerticalLine == false || downVerticalLine == false 
                    || leftHorizontalLine == false || rightHorizontalLine == false)
        {
            check = false;
        }

        if (board->position[row][col]->tile != nullptr)
        {
            check = false;
        }

        return check;
    }
}

//check any common field between the current tile on left
bool Rules::rightHorCheck(int row, int col, Board *board, 
                                Colour colour, Shape shape)
{
    std::string common = "";
    bool check = true;
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
    // only have one tile on the right
    else if(board->position[row + 1][col]->tile != nullptr
            && ( board->position[row + 1][col]->tile == nullptr 
                || row == BOARD_SIZE - 1 ))
    {
        // same colour
        if(board->position[row + 1][col]->tile->colour == colour)
        {
            common = "colour";
        }
        // same shape
        else if(board->position[row + 1][col]->tile->shape == shape)
        {
            common = "shape";
        }
    }
    
    if(common.compare("") != 1)
    {
        if(common.compare("colour") == 1 
                && (colour != board->position[row + 1][col]->tile->colour))
        {
            check = false;
        }
        else if(common.compare("shape") == 1 
                && (shape != board->position[row + 1][col]->tile->shape))
        {
            check = false;
        }
    }
    // check is false if there's no common shape or colour
    else if(common.compare("") == 1)
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
    bool check = true;
    std::string common = "";
   
    if(board->position[row][col + 1]->tile != nullptr
        && (board->position[row][col + 2]->tile != nullptr
            || col == BOARD_SIZE - 1))
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
    else if(board->position[row][col + 1]->tile != nullptr)
    {
        // same colour
        if(board->position[row][col + 1]->tile->colour == colour)
        {
            common = "colour";
        }
        // same shape
        if(board->position[row][col + 1]->tile->shape == shape)
        {
            common = "shape";
        }
    }
    if(common.compare("") != 1)
    {
        if(common.compare("colour") == 1 
                && (colour != board->position[row][col + 1]->tile->colour))
        {
            check = false;
        }
        else if(common.compare("shape") == 1 
                && (shape != board->position[row][col + 1]->tile->shape))
        {
            check = false;
        }
    }
    else if(common.compare("") == 1)
    {
        check = false;
    }
    if(check == true)
    {
        check = downDuplicat(row, col, board, colour, shape);
    }
    return check;
}

//Helper method - check any common field between the current tile and the one upper if not empty
bool Rules::upVerCheck(int row, int col, Board *board, 
                            Colour colour, Shape shape)
{
    bool check = true;
    std::string common = "";
   
    if(board->position[row][col - 1]->tile != nullptr
        && (board->position[row][col - 2]->tile != nullptr
            || col == 0))
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
    else if(board->position[row][col - 1]->tile != nullptr)
    {
        // same colour
        if(board->position[row][col - 1]->tile->colour == colour)
        {
            common = "colour";
        }
        // same shape
        if(board->position[row][col - 1]->tile->shape == shape)
        {
            common = "shape";
        }
    }
    if(common.compare("") != 1)
    {
        if(common.compare("colour") == 1 
                && (colour != board->position[row][col - 1]->tile->colour))
        {
            check = false;
        }
        else if(common.compare("shape") == 1 
                && (shape != board->position[row][col - 1]->tile->shape))
        {
            check = false;
        }
    }
    else if(common.compare("") == 1)
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
    std::string common = "";
    bool check = true;
    // Determine the adjacent tiles on the right, 
    // two tiles cannot be empty and should have same colour or shape
    if(board->position[row - 1][col]->tile != nullptr
        && (board->position[row - 2][col]->tile != nullptr
         || row == 0))
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
    else if(board->position[row - 1][col]->tile != nullptr)
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
    
    if(common.compare("") != 1)
    {
        if(common.compare("colour") == 1 
                && (colour != board->position[row - 1][col]->tile->colour))
        {
            check = false;
        }
        else if(common.compare("shape") == 1 
                && (shape != board->position[row - 1][col]->tile->shape))
        {
            check = false;
        }
    }
    // check is false if there's no common shape or colour
    else if(common.compare("") == 1)
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
    int exist = 1;
    // check list number
    for(unsigned int verticalCounter = row + 1; 
                        verticalCounter < BOARD_SIZE - 1; verticalCounter++)
    {
        if(board->position[verticalCounter][col]->tile != nullptr)
        {
            exist++;
        }
    }

    // check the same tile
    for(unsigned int verticalCounter = row + 1; 
                        verticalCounter < BOARD_SIZE - 1; verticalCounter++)
    {
        if(board->position[verticalCounter][col]->tile->colour == colour
            && board->position[verticalCounter][col]->tile->shape == shape)
        {
            check = false;
        }
    }
    return check;
}

// check for duplication - for loop through the down hand of the board
bool Rules::downDuplicat(int row, int col, Board *board, 
                            Colour colour, Shape shape)
{
    bool check = true;
    int exist = 1;
   // check list number
    for(unsigned int horizontalCounter = col + 1; 
            horizontalCounter < BOARD_SIZE - 1; horizontalCounter++)
    {
        if(board->position[row][horizontalCounter]->tile != nullptr)
        {
            exist++;
        }
    }

    // check the same tile
    for (unsigned int horizontalCounter = col + 1; 
            horizontalCounter < BOARD_SIZE - 1; horizontalCounter++)
    {
       if(exist > 5)
        {
            check = false;
        }
        else if(exist < 6)
        {
            if(board->position[row][horizontalCounter]->tile->colour == colour
            && board->position[row][horizontalCounter]->tile->shape == shape)
            {
                check = false;
            }
        }
    }
    
    return check;
}

//check for duplication - for loop throught the left hand of board
bool Rules::leftDuplicat(int row, int col, Board *board,
                                    Colour colour, Shape shape)
{
    bool check = true;
    int exist = 1;
    // check list number
    for(unsigned int verticalCounter = row - 1; 
                        verticalCounter > 0; verticalCounter--)
    {
        if(board->position[verticalCounter][col]->tile != nullptr)
        {
            exist++;
        }
    }

    // check the same tile
    for(unsigned int verticalCounter = row - 1; 
                        verticalCounter > 0; verticalCounter--)
    {
        if(board->position[verticalCounter][col]->tile->colour == colour
            && board->position[verticalCounter][col]->tile->shape == shape)
        {
            check = false;
        }
    }
    return check;
}

// check for duplication - for loop throught the upper hand of board
bool Rules::upDuplicat(int row, int col, Board *board, 
                            Colour colour, Shape shape){
    bool check = true;
    int exist = 1;

    // check list number
    for(unsigned int horizontalCounter = col - 1; 
            horizontalCounter >= 0; horizontalCounter--)
    {
        if(board->position[row][horizontalCounter]->tile != nullptr)
        {
            exist++;
        }
    }

    // check the same tile
    for (unsigned int horizontalCounter = col - 1; 
            horizontalCounter >= 0; horizontalCounter--)
    {
       if(exist > 5)
        {
            check = false;
        }
        else if(exist < 6)
        {
            if(board->position[row][horizontalCounter]->tile->colour == colour
            && board->position[row][horizontalCounter]->tile->shape == shape)
            {
                check = false;
            }
        }
    }
    
    return check;
}

// Calculate the player's score based on the tile they placed
// look for QWIRKLE!
int Rules::scoreRules(unsigned int row, unsigned int col, Board *board, int turn){
    int score = 0;
    int upScore = 1; 
    int downScore = 1; 
    int leftScore = 1;
    int rightScore = 1;
    // if current tile is on the first col
    if(col == 0)
    {
        // if it's on the first row, check right and down
        if(row == 0)
        {
            downScore += downTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
        }
        // if it's on the last row, check left and down
        else if(row == BOARD_SIZE - 1)
        {
            downScore += downTileScore(row, col, board);
            leftScore += leftTileScore(row, col, board);
        }
        // if it's in the middle, check horizontal and down
        else
        {
            downScore += downTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
            leftScore += leftTileScore(row, col, board);
        } 
    }
    // if current tile is on the last col
    else if(col == BOARD_SIZE - 1)
    {
        // if it's on the first row, check right and up
        if(row == 1)
        {
            upScore += upTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
        }
        // if it's on the last row, check left and up
        else if(row == BOARD_SIZE - 1)
        {
            upScore += upTileScore(row, col, board);
            leftScore += leftTileScore(row, col, board);
        }
        // if it's in the middle, check horizontal and up
        else
        {
            upScore += upTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
            leftScore += leftTileScore(row, col, board);
        } 
    }
    else if((col != 0 && col != BOARD_SIZE - 1)
    && (row == 0 || row == BOARD_SIZE - 1))
    {
        // the tile is on the first row, check vertical and right
        if(row == 0)
        {
            upScore += upTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
            downScore += downTileScore(row, col, board);
        }
        // the tile is on the last row, check vertical and left
        else if(row == BOARD_SIZE - 1)
        {
            upScore += upTileScore(row, col, board);
            leftScore += leftTileScore(row, col, board);
            downScore += downTileScore(row, col, board);
        }
    }
    // the tile is in the middle, check 4 direction
    else if((row != 0 && row != BOARD_SIZE - 1)
    && (col != 0 && col != BOARD_SIZE - 1))
    {
        upScore += upTileScore(row, col, board);
        rightScore += rightTileScore(row, col, board);
        leftScore += leftTileScore(row, col, board);
        downScore += downTileScore(row, col, board);
    }
    
    if(turn == 0 && upScore == 1 && downScore == 1 && leftScore == 1 && rightScore == 1)
    {
        score = 1;
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
    for(unsigned int verticalCounter = row + 1; 
            verticalCounter < BOARD_SIZE - 1; verticalCounter++)
    {
        if(board->position[verticalCounter][col]->tile != nullptr 
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

// check tile number below the current tile
int Rules::downTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty = false;
    for(unsigned int horizontalCounter = col + 1; 
        horizontalCounter < board->position.size(); horizontalCounter++)
    {
       if( board->position[row][horizontalCounter]->tile != nullptr
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

// check tile number on the left hand side of the current tile
int Rules::leftTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty = false;
    for(int verticalCounter = row - 1; verticalCounter >= 0; verticalCounter--)
    {
        if(board->position[verticalCounter][col]->tile != nullptr 
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

// check any tile upper the current tile
int Rules::upTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty = false;
    for(unsigned int horizontalCounter = col - 1; 
                            horizontalCounter >= 0; horizontalCounter--)
    {
        if(board->position[row][horizontalCounter]->tile != nullptr
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