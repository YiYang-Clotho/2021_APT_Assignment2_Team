#include "Rules.h"

#include <iostream>

// #define UP      board[horizontalCounter - 1][verticalCounter]
#define UP      board->position[row][col - 1]
#define RIGHT   board->position[row + 1][col]
#define DOWN    board->position[row][col + 1]
#define LEFT    board->position[row - 1][col]
// #define RIGHT   board[horizontalCounter][verticalCounter+1]
// #define DOWN    board[horizontalCounter+1][verticalCounter]
// #define LEFT    board[horizontalCounter][verticalCounter-1]
#define QWIRKLE 6

using std::cout;
using std::endl;
using std::vector;

Rules::Rules(){
    
}

// Check the legal move of a tile placed
bool Rules::boardRules(unsigned int rowsInt, unsigned int columns, Board *board, Tile* tile, int turn){
    bool check = true;
    bool upVerticalLine = true;
    bool downVerticalLine = true;
    bool leftHorizontalLine = true;
    bool rightHorizontalLine = true;

// Circulate horizontally, less than 26
    for(unsigned int horizontalCounter = 0; 
        horizontalCounter < board->position.size(); horizontalCounter++)
    {
        if(rowsInt == horizontalCounter)
        {
            // Start to circulate longitudinally, less than the length of 26
            for(unsigned int verticalCounter = 0; verticalCounter < board[horizontalCounter].size(); verticalCounter++)
            {
                if(columns == verticalCounter)
                {   
                    //如果这个tile，或者说这个点颜色形状都是0或者空，起始点
                    if(board[horizontalCounter][verticalCounter]->getColour() == '\0' && board[horizontalCounter][verticalCounter]->getShape() == 0)
                    {
                        // Corner (Edges)
                        // 如果游戏不是最开始的一轮，同时是第一次横向循环
                        if((turn > 0) && (horizontalCounter == 0))
                        {
                            //whole upper
                            //left upper corner
                            //也是第一次纵向循环，棋盘左上角
                            if(verticalCounter == 0)
                            {
                                //判断左上角右边和下面是不是初始值，意味着边上没别的tile，如果是得到false
                                if((RIGHT->getColour() == '\0' && RIGHT->getShape() == 0)
                                && (DOWN->getColour() == '\0' && DOWN->getShape() == 0))
                                {
                                    check = false;
                                }
                                //如果右边和下面都不是初始值，那么意味着要用下面的函数检查，存在的tile是否满足放的条件
                                if(RIGHT->getColour() != '\0' && RIGHT->getShape() != 0)
                                {
                                    //如果检查的条件不满足，会得到false
                                    rightHorizontalLine = rightVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(DOWN->getColour() != '\0' && DOWN->getShape() != 0)
                                {
                                    downVerticalLine = downVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                            }
                            //目前假设check = false，
                            //right upper corner
                            //同样检查右上角，棋盘最大宽度减一就是右上角
                            else if(verticalCounter == board[horizontalCounter].size() - 1)
                            {

                                if((LEFT->getColour() == '\0' && LEFT->getShape() == 0)
                                && (DOWN->getColour() == '\0' && DOWN->getShape() == 0))
                                {
                                    check = false;
                                }

                                if(LEFT->getColour() != '\0' && LEFT->getShape() != 0)
                                {
                                    leftHorizontalLine = leftVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(DOWN->getColour() != '\0' && DOWN->getShape() != 0)
                                {
                                    downVerticalLine = downVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                            }
                            //如果vertical不是0，意味着在第一横排，但不是第一列
                            else
                            {
                                //上方是地图边缘，所以要判定其他三个方向
                                if((LEFT->getColour() == '\0' && LEFT->getShape() == 0)
                                && (RIGHT->getColour() == '\0' && RIGHT->getShape() == 0)
                                && (DOWN->getColour() == '\0' && DOWN->getShape() == 0))
                                {
                                    check = false;
                                }

                                if(LEFT->getColour() != '\0' && LEFT->getShape() != 0)
                                {
                                    leftHorizontalLine = leftVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(RIGHT->getColour() != '\0' && RIGHT->getShape() != 0)
                                {
                                    rightHorizontalLine = rightVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(DOWN->getColour() != '\0' && DOWN->getShape() != 0)
                                {
                                    downVerticalLine = downVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                            }
                            //假设目前check=false
                            //如果前面判定得到的三个方向中任意一个失败，那么意味着这个位子不能放tile，会和边上其中一个tile冲突
                            if(downVerticalLine == false 
                            || leftHorizontalLine == false || rightHorizontalLine == false)
                            {
                                check = false;
                            }
                            
                        }
                        //从棋盘最底下一行开始判定
                        //whole lower
                        else if((turn > 0) && (horizontalCounter == board.size() - 1))
                        {
                            //left lower corner
                            //左下角，判定上和右边
                            if(verticalCounter == 0)
                            {
                                if((RIGHT->getColour() == '\0' && RIGHT->getShape() == 0)
                                && (UP->getColour() == '\0' && UP->getShape() == 0))
                                {
                                    check = false;
                                }

                                if(RIGHT->getColour() != '\0' && RIGHT->getShape() != 0)
                                {
                                    rightHorizontalLine = rightVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(UP->getColour() != '\0' && UP->getShape() != 0)
                                {
                                    upVerticalLine = upVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                            }
                            //right lower corner
                            //判定左下角
                            else if(verticalCounter == board[horizontalCounter].size() - 1)
                            {
                                if((LEFT->getColour() == '\0' && LEFT->getShape() == 0)
                                && (UP->getColour() == '\0' && UP->getShape() == 0))
                                {
                                    check = false;
                                }

                                if(LEFT->getColour() != '\0' && LEFT->getShape() != 0)
                                {
                                    leftHorizontalLine = leftVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(UP->getColour() != '\0' && UP->getShape() != 0)
                                {
                                    upVerticalLine = upVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                            }
                            //如果不是第一列，但是是最后一行
                            else
                            {
                                //下边是地图边缘，判定其他三个方向
                                if((LEFT->getColour() == '\0' && LEFT->getShape() == 0)
                                && (UP->getColour() == '\0' && UP->getShape() == 0)
                                && (RIGHT->getColour() == '\0' && RIGHT->getShape() == 0))
                                {
                                    check = false;
                                }

                                if(LEFT->getColour() != '\0' && LEFT->getShape() != 0)
                                {
                                    leftHorizontalLine = leftVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(UP->getColour() != '\0' && UP->getShape() != 0)
                                {
                                    upVerticalLine = upVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(RIGHT->getColour() != '\0' && RIGHT->getShape() != 0)
                                {
                                    rightHorizontalLine = rightVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                            }
                            //如果前面判定得到的三个方向中任意一个失败，那么意味着这个位子不能放tile，会和边上其中一个tile冲突
                            if(upVerticalLine == false
                            || leftHorizontalLine == false || rightHorizontalLine == false)
                            {
                                check = false;
                            }
                        }
                        //棋盘的第一行和最后一行前面已经判定过了，所以排除，判断纵向第一列或最后一列
                        else if((turn > 0)
                        && (horizontalCounter != 0 && horizontalCounter != board.size() - 1)
                        && (verticalCounter == 0 || verticalCounter == board[horizontalCounter].size() - 1))
                        {
                            //left columns with rows
                            //第一列，左边是地图边缘，判断其他三个方向，排除第一行和最后一行
                            if(verticalCounter == 0)
                            {
                                if((RIGHT->getColour() == '\0' && RIGHT->getShape() == 0)
                                && (DOWN->getColour() == '\0' && DOWN->getShape() == 0)
                                && (UP->getColour() == '\0' && UP->getShape() == 0))
                                {
                                    check = false;
                                }

                                if(RIGHT->getColour() != '\0' && RIGHT->getShape() != 0)
                                {
                                    rightHorizontalLine = rightVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(DOWN->getColour() != '\0' && DOWN->getShape() != 0)
                                {
                                    downVerticalLine = downVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(UP->getColour() != '\0' && UP->getShape() != 0)
                                {
                                    upVerticalLine = upVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                            }
                            //假设目前是空check=false
                            //最后一列，右边是地图边缘，判断其他三个方向，排除第一行和最后一行
                            else if(verticalCounter == board[horizontalCounter].size() - 1)
                            {
                                if((LEFT->getColour() == '\0' && LEFT->getShape() == 0)
                                && (DOWN->getColour() == '\0' && DOWN->getShape() == 0)
                                && (UP->getColour() == '\0' && UP->getShape() == 0))
                                {
                                    check = false;
                                }

                                if(LEFT->getColour() != '\0' && LEFT->getShape() != 0)
                                {
                                    leftHorizontalLine = leftVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(DOWN->getColour() != '\0' && DOWN->getShape() != 0)
                                {
                                    downVerticalLine = downVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                                if(UP->getColour() != '\0' && UP->getShape() != 0)
                                {
                                    upVerticalLine = upVerticalLineCheck(rowsInt, columns, board, tile);
                                }
                            }
                            //只要四个方向任意一个放置判定失败就false
                            if(upVerticalLine == false || downVerticalLine == false 
                            || leftHorizontalLine == false || rightHorizontalLine == false)
                            {
                                check = false;
                            }
                        }
                        //No corner 
                        //四条边界都判定过了，判定棋盘中间位置，每个位置四个方向
                        else if((turn > 0)
                        && (horizontalCounter != 0 && horizontalCounter != board.size() - 1)
                        && (verticalCounter != 0 && verticalCounter != board[horizontalCounter].size() - 1))
                        {
                            //check 4 directions
                            //四个方向都是空
                            if((UP->getColour() == '\0' && UP->getShape() == 0)
                            && (RIGHT->getColour() == '\0' && RIGHT->getShape() == 0)
                            && (DOWN->getColour() == '\0' && DOWN->getShape() == 0)
                            && (LEFT->getColour() == '\0' && LEFT->getShape() == 0))
                            {
                                check = false;
                            }
                            //四个方向如果有其他tile进行判定
                            if(UP->getColour() != '\0' && UP->getShape() != 0)
                            {
                                upVerticalLine = upVerticalLineCheck(rowsInt, columns, board, tile);
                            }
                            if(DOWN->getColour() != '\0' && DOWN->getShape() != 0)
                            {
                                downVerticalLine = downVerticalLineCheck(rowsInt, columns, board, tile);
                            }
                            if(LEFT->getColour() != '\0' && LEFT->getShape() != 0)
                            {
                                leftHorizontalLine = leftVerticalLineCheck(rowsInt, columns, board, tile);
                            }
                            if(RIGHT->getColour() != '\0' && RIGHT->getShape() != 0)
                            {
                                rightHorizontalLine = rightVerticalLineCheck(rowsInt, columns, board, tile);
                            }
                            //四个方向任意一个错了就不能放false
                            if(upVerticalLine == false || downVerticalLine == false 
                            || leftHorizontalLine == false || rightHorizontalLine == false)
                            {
                                check = false;
                            }
                        }
                        //前面是turn>0,如果是新游戏最开始，随便放true
                        else if(turn == 0)
                        {
                            check = true;
                        }
                        //turn不能是负数
                        else
                        {
                            check = false;
                        }  
                    }
                    //如果起始点不是“0”，0，那就false
                    else
                    {
                        check = false;
                    }
                }
            }
        }
    }
    //除了新游戏开始，后面不管任何时候放tile，边上必然有其它tile，leftHorizontalLine必然要进行这四个方向判定，独立存在的tile是不可以放的，返回ture说明可以放
    return check;
}

//Helper method - check any common field between the current tile and the right hand size if not empty
bool Rules::rightCheck(int rows, int columns, Board *board, Tile* tile){
    std::string common = "";
    bool check = true;
    //判断右边相邻tile，右边两个都不能为空，右边两个col都有tile
    if((board[rows][columns+1]->getColour() != '\0' && board[rows][columns+1]->getShape() != 0)
    && (board[rows][columns+2]->getColour() != '\0' && board[rows][columns+2]->getShape() != 0))
    {
        //如果相邻的两个tile颜色相同，返回common值colour
        if(board[rows][columns+1]->getColour() == board[rows][columns+2]->getColour())
        {
            common = "colour";
        }
        //如果相邻的俩形状相同，返回common值shape
        if(board[rows][columns+1]->getShape() == board[rows][columns+2]->getShape())
        {
            common = "shape";
        }
    }
    //右边只有一个tile，可以没有第二个
    else if(board[rows][columns+1]->getColour() != '\0' && board[rows][columns+1]->getShape() != 0)
    {
        //如果右边的一个tile颜色和第一个tile或者说正在判定的tile相同，返回有值的common
        if(board[rows][columns+1]->getColour() == tile->getColour())
        {
            common = "colour";
        }
        else if(board[rows][columns+1]->getShape() == tile->getShape())
        {
            common = "shape";
        }
    }
    //经过上面的判定common有值，不为空
    //因为一模一样的两个tile不能在无间隔的同一行或者一列，所以相邻的要么颜色一样要么形状一样
    if(common != "")
    {
        //如果是右边有两个tile+1+2，上面没有和判定的tile进行判定，所以判定的tile就还需要和相邻的右边的一个判定一次，如果颜色不一样判定失败
        //如果颜色不一样，不能放，如果形状不一样不能放false，想要放牌只能满足其中一个条件
        if(common == "colour" && tile->getColour() != board[rows][columns+1]->getColour())
        {
            check = false;
        }
        else if(common == "shape" && tile->getShape() != board[rows][columns+1]->getShape())
        {
            check = false;
        }
    }
    //如果是空判定失败
    else if(common == "")
    {
        check = false;
    }

    if(check == true)
    {
        check = rightDuplicationTiles(rows, columns, board, tile);
    }
    //要想返回true，得经过上面重复函数的检查，没有重复，同时满足右边相邻的tile颜色一样或者形状一样，其中一个才能行
    return check;
}

//Helper method - check any common field between the current tile and the one below if not empty
bool Rules::downCheck(int rows, int columns, Board *board, Tile* tile){
    bool check = true;
    std::string common = "";
   
    if((board[rows+1][columns]->getColour() != '\0' && board[rows+1][columns]->getShape() != 0)
    && (board[rows+2][columns]->getColour() != '\0' && board[rows+2][columns]->getShape() != 0))
    {
        if(board[rows+1][columns]->getColour() == board[rows+2][columns]->getColour())
        {
            common = "colour";
        }
        if(board[rows+1][columns]->getShape() == board[rows+2][columns]->getShape())
        {
            common = "shape";
        }
    }
    else if(board[rows+1][columns]->getColour() != '\0' && board[rows+1][columns]->getShape() != 0)
    {
        if(board[rows+1][columns]->getColour() == tile->getColour())
        {
            common = "colour";
        }
        else if(board[rows+1][columns]->getShape() == tile->getShape())
        {
            common = "shape";
        }
    }
    if(common != "")
    {
        if(common == "colour" && tile->getColour() != board[rows+1][columns]->getColour())
        {
            check = false;
        }
        else if(common == "shape" && tile->getShape() != board[rows+1][columns]->getShape())
        {
            check = false;
        }
    }
    else if(common == "")
    {
        check = false;
    }
    if(check == true)
    {
        check = downDuplicationTiles(rows, columns, board, tile);
    }
    return check;
}

//Helper method - check any common field between the current tile and the one upper if not empty
bool Rules::upCheck(int rows, int columns, Board *board, Tile* tile){
    std::string common = "";
    bool check = true;

    if((board[rows-1][columns]->getColour() != '\0' && board[rows-1][columns]->getShape() != 0)
    && (board[rows-2][columns]->getColour() != '\0' && board[rows-2][columns]->getShape() != 0))
    {
        if(board[rows-1][columns]->getColour() == board[rows-2][columns]->getColour())
        {
            common = "colour";
        }
        if(board[rows-1][columns]->getShape() == board[rows-2][columns]->getShape())
        {
            common = "shape";
        }
    }
    else if(board[rows-1][columns]->getColour() != '\0' && board[rows-1][columns]->getShape() != 0)
    {
        if(board[rows-1][columns]->getColour() == tile->getColour())
        {
            common = "colour";
        }
        else if(board[rows-1][columns]->getShape() == tile->getShape())
        {
            common = "shape";
        }
    }
    if(common != "")
    {
        if(common == "colour" && tile->getColour() != board[rows-1][columns]->getColour())
        {
            check = false;
        }
        else if(common == "shape" && tile->getShape() != board[rows-1][columns]->getShape())
        {
            check = false;
        }
    }
    else if(common == "")
    {
        check = false;
    }
    if(check == true)
    {
        check = upDuplicationTiles(rows, columns, board, tile);
    }
    return check;
}

// check any common field between the current tile and the left hand side
// if not empty
bool Rules::leftCheck(int rows, int columns, Board *board, Tile* tile){
    std::string common = "";
    bool check = true;

    if((board[rows][columns-1]->getColour() != '\0' && board[rows][columns-1]->getShape() != 0)
    && (board[rows][columns-2]->getColour() != '\0' && board[rows][columns-2]->getShape() != 0))
    {
        if(board[rows][columns-1]->getColour() == board[rows][columns-2]->getColour())
        {
            common = "colour";
        }
        if(board[rows][columns-1]->getShape() == board[rows][columns-2]->getShape())
        {
            common = "shape";
        }
    }
    else if(board[rows][columns-1]->getColour() != '\0' && board[rows][columns-1]->getShape() != 0)
    {
        if(board[rows][columns-1]->getColour() == tile->getColour())
        {
            common = "colour";
        }
        else if(board[rows][columns-1]->getShape() == tile->getShape())
        {
            common = "shape";
        }
    }
    if(common != "")
    {
        if(common == "colour" && tile->getColour() != board[rows][columns-1]->getColour())
        {
            check = false;
        }
        else if(common == "shape" && tile->getShape() != board[rows][columns-1]->getShape())
        {
            check = false;
        }
    }
    else if(common == "")
    {
        check = false;
    }
    if(check == true)
    {
        check = leftDuplicationTiles(rows, columns, board, tile);
    }
    return check;
}

//Helper method - check for duplication - for loop through the right hand of the board (columns)
bool Rules::rightDuplicationTiles(int rows, int columns, vector<vector<Tile*>> board, Tile* tile){
    bool check = true;
    int exist = 1;
    //循环右边的棋盘，小于row
    for(unsigned int verticalCounter = columns+1; verticalCounter < board[rows].size(); verticalCounter++)
    {
        //如果这个位置不为空，那么证明有tile存在
        if(board[rows][verticalCounter]->getColour() != '\0' && board[rows][verticalCounter]->getShape() != 0)
        {
            //如果已经有六个tile了，那么也不能继续放了
            if(exist > 5)
            {
                check = false;
            }
            //依次判定右边的每一个tile
            else if(exist < 6)
            {
                //如果右边的tile颜色和形状同时和判定tile相同，那么判定失败，不能放
                if(board[rows][verticalCounter]->getColour() == tile->getColour() && board[rows][verticalCounter]->getShape() == tile->getShape())
                {
                    check = false;
                }
            }
            exist++;
        }
    }
    //如果判定的tile右边五个tile都没有重复，同时个数小于6，那么意味着可以放返回true
    return check;
}

// check for duplication - for loop through the down hand of the board (rows)
bool Rules::downDuplicat(int rows, int columns, Board *board, Tile* tile){
    bool check = true;
    int exist = 1;
    for(unsigned int horizontalCounter = rows+1; horizontalCounter < board.size(); horizontalCounter++)
    {
        if(board[horizontalCounter][columns]->getColour() != '\0' && board[horizontalCounter][columns]->getShape() != 0)
        {
            if(exist > 5)
            {
                check = false;
            }
            else if(exist < 6)
            {
                if(board[horizontalCounter][columns]->getColour() == tile->getColour() && board[horizontalCounter][columns]->getShape() == tile->getShape())
                {
                    check = false;
                }
            }
            exist++;
        }
    }
    return check;
}

//Helper method - check for duplication - for loop throught the left hand of board (columns)
bool Rules::leftDuplicat(int rows, int columns, Board *board, Tile* tile){
    bool check = true;
    int exist = 1;
    for(int verticalCounter = columns-1; verticalCounter >= 0; verticalCounter--)
    {
        if(board[rows][verticalCounter]->getColour() != '\0' && board[rows][verticalCounter]->getShape() != 0)
        {
            if(exist > 5)
            {
                check = false;
            }
            else if(exist < 6)
            {
                if(board[rows][verticalCounter]->getColour() == tile->getColour() && board[rows][verticalCounter]->getShape() == tile->getShape())
                {
                    check = false;
                }
            }
            exist++;
        }
    }
    return check;
}

//Helper method - check for duplication - for loop throught the upper hand of board (rows)
bool Rules::upDuplicat(int rows, int columns, Board *board, Tile* tile){
    bool check = true;
    int exist = 1;
    for(int horizontalCounter = rows-1; horizontalCounter >= 0; horizontalCounter--)
    {
        if(board[horizontalCounter][columns]->getColour() != '\0' && board[horizontalCounter][columns]->getShape() != 0)
        {
            if(exist > 5)
            {
                check = false;
            }
            else if(exist < 6)
            {
                if(board[horizontalCounter][columns]->getColour() == tile->getColour() && board[horizontalCounter][columns]->getShape() == tile->getShape())
                {
                    check = false;
                }
            }
            exist++;
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
    if(col == 1)
    {
        // if it's on the first row, check right and down
        if(row == 1)
        {
            downScore += downTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
        }
        // if it's on the last row, check left and down
        else if(row == BOARD_SIZE)
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
    else if(col == BOARD_SIZE)
    {
        // if it's on the first row, check right and up
        if(row == 1)
        {
            upScore += upTileScore(row, col, board);
            rightScore += rightTileScore(row, col, board);
        }
        // if it's on the last row, check left and up
        else if(row == BOARD_SIZE)
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

// check tile number on the right hand side of the current tile
int Rules::rightTileScore(int row, int col, Board *board){
    int score = 0;
    bool empty =  false;
    for(unsigned int verticalCounter = row + 1; 
            verticalCounter < BOARD_SIZE; verticalCounter++)
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