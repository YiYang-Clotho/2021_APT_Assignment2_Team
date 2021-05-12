#include "Rules.h"

#include <iostream>

#define UP      board[horizontalCounter-1][verticalCounter]
#define RIGHT   board[horizontalCounter][verticalCounter+1]
#define DOWN    board[horizontalCounter+1][verticalCounter]
#define LEFT    board[horizontalCounter][verticalCounter-1]
#define QWIRKLE 6

using std::cout;
using std::endl;
using std::vector;

Rules::Rules(){
    
}

//名字参数啥的你看着改，需要define就define
//vector<vector<Node*>> position;我需要用到的就是tile的颜色和形状，你node好像从tile获取了这俩，相当于中间转了一次，我不知道有没有影响，就没用，你可以看着改
//board 应该可以改成你用的position吧，turn用来看第几轮
//Calculate the player's score based on the tile they placed as well as look for QWIRKLE!
int Rules::scoreRules(unsigned int rowsInt, unsigned int columns, vector<vector<Tile*>> board, int turn){
    int score = 0;
    int upScore = 1; 
    int downScore = 1; 
    int leftScore = 1;
    int rightScore = 1;
//基本上就是判断各个方向
    if(rowsInt == 0)
    {
        if(columns == 0)
        {
            downScore += downTileScore(rowsInt, columns, board);
            rightScore += rightTileScore(rowsInt, columns, board);
        }
        else if(columns == board[rowsInt].size() - 1)
        {
            downScore += downTileScore(rowsInt, columns, board);
            leftScore += leftTileScore(rowsInt, columns, board);
        }
        else
        {
            downScore += downTileScore(rowsInt, columns, board);
            rightScore += rightTileScore(rowsInt, columns, board);
            leftScore += leftTileScore(rowsInt, columns, board);
        } 
    }
    else if(rowsInt == board.size() - 1)
    {
        if(columns == 0)
        {
            upScore += upTileScore(rowsInt, columns, board);
            rightScore += rightTileScore(rowsInt, columns, board);
        }
        else if(columns == board[rowsInt].size() - 1)
        {
            upScore += upTileScore(rowsInt, columns, board);
            leftScore += leftTileScore(rowsInt, columns, board);
        }
        else
        {
            upScore += upTileScore(rowsInt, columns, board);
            rightScore += rightTileScore(rowsInt, columns, board);
            leftScore += leftTileScore(rowsInt, columns, board);
        } 
    }
    else if((rowsInt != 0 && rowsInt != board.size() - 1)
    && (columns == 0 || columns == board[rowsInt].size() - 1))
    {
        if(columns == 0)
        {
            upScore += upTileScore(rowsInt, columns, board);
            rightScore += rightTileScore(rowsInt, columns, board);
            downScore += downTileScore(rowsInt, columns, board);
        }
        else if(columns == board[rowsInt].size() - 1)
        {
            upScore += upTileScore(rowsInt, columns, board);
            leftScore += leftTileScore(rowsInt, columns, board);
            downScore += downTileScore(rowsInt, columns, board);
        }
    }
    else if((rowsInt != 0 && rowsInt != board.size() - 1)
    && (columns != 0 && columns != board[rowsInt].size() - 1))
    {
        upScore += upTileScore(rowsInt, columns, board);
        rightScore += rightTileScore(rowsInt, columns, board);
        leftScore += leftTileScore(rowsInt, columns, board);
        downScore += downTileScore(rowsInt, columns, board);
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

//check any tile on the right hand size of the current tile
int Rules::rightTileScore(int rowsInt, int columns, vector<vector<Tile*>> board){
    int score = 0;
    bool empty =  false;
    //遍历一下，每放一个tile，vertilcalCounter就会加一，因为在同一行，所以判断vertical，同时小于row长度也就是26
    for(unsigned int verticalCounter = columns+1; verticalCounter < board[rowsInt].size(); verticalCounter++)
    {
        //board上每个位子都是node，每个node有colour和shape，要加分就判定colour，shape不能是0或空
        if(board[rowsInt][verticalCounter]->getColour() != '\0' && board[rowsInt][verticalCounter]->getShape() != 0 && empty == false)
        {
            score++;
        }
        else
        {
            empty = true;
        }    
    }
    //当你score能加5分意味着达成了两种qwirkle的前置条件，再放一个就qwirkle
    if(score == 5)
    {
        qwirkle = true;
    }
    return score;
}

//check any tile below the current tile
int Rules::downTileScore(int rowsInt, int columns, vector<vector<Tile*>> board){
    int score = 0;
    bool empty = false;
    for(unsigned int horizontalCounter = rowsInt+1; horizontalCounter < board.size(); horizontalCounter++)
    {
       if(board[horizontalCounter][columns]->getColour() != '\0' && board[horizontalCounter][columns]->getShape() != 0 && empty == false)
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

//check any tile on the left hand size of the current tile
int Rules::leftTileScore(int rowsInt, int columns, vector<vector<Tile*>> board){
    int score = 0;
    bool empty = false;
    for(int verticalCounter = columns-1; verticalCounter >= 0; verticalCounter--)
    {
        if(board[rowsInt][verticalCounter]->getColour() != '\0' && board[rowsInt][verticalCounter]->getShape() != 0 && empty == false)
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

//check any tile upper the current tile
int Rules::upTileScore(int rowsInt, int columns, vector<vector<Tile*>> board){
    int score = 0;
    bool empty = false;
    for(int horizontalCounter = rowsInt-1; horizontalCounter >= 0; horizontalCounter--)
    {
        if(board[horizontalCounter][columns]->getColour() != '\0' && board[horizontalCounter][columns]->getShape() != 0 && empty == false)
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