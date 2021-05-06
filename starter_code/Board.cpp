#include <iostream>
#include <vector>

#include "Board.h"
#include "Types.h"
using namespace std;

Board::Board()
{
    // initilise the empty board
    for (int r = 0; r < BOARD_ROW; r++)
    {
        for (int c = 0; c < BOARD_COL; c++)
        {
            vector<char> temp;
            int tempNum = 0;
            int tempDistance = 2;
            char tempChar;

            // set the first row, the values are the row coodinator
            if (r == 0)
            {
                tempChar = ' ';
                if (c % 3 == 0)
                {
                    temp.push_back(tempNum);
                    this->position.push_back(temp);
                    tempNum++;
                    temp.pop_back();
                }
                else
                {
                    temp.push_back(tempChar);
                    this->position.push_back(temp);
                    temp.pop_back();
                }
            }
            // set the second row, a line of -----
            else if (r == 1)
            {
                if (c == 0 || c == 1)
                {
                    tempChar = ' ';
                    temp.push_back(tempChar);
                    this->position.push_back(temp);
                    temp.pop_back();
                }
                else
                {
                    tempChar = '-';
                    temp.push_back(tempChar);
                    this->position.push_back(temp);
                    temp.pop_back();
                }
            }else{
                if (c == 0)
                {
                    tempChar = char(ASCII_DIFFERENCE + c);
                    temp.push_back(tempChar);
                    this->position.push_back(temp);
                    temp.pop_back();
                }else if(c == tempDistance){
                    tempNum = 3;
                    tempDistance+=tempNum;
                    tempChar = '|';

                    temp.push_back(tempChar);
                    this->position.push_back(temp);
                    temp.pop_back();
                }else{
                    tempChar = ' ';
                    temp.push_back(tempChar);
                    this->position.push_back(temp);
                    temp.pop_back();
                }
                
            }
        }
    }

    this->tile = tile;
    this->row = row;
    this->col = col;
}

// deep copy the board
Board::Board(Board &other) : position(other.position)
{
    // initilise the size of the board, get rid of junk
    for (int r = 0; r < BOARD_ROW; r++)
    {
        this->position[r].resize(BOARD_COL);
    }
    // copy
    for (int r = 0; r < this->position.size(); r++)
    {
        for (int c = 0; c < this->position[r].size(); c++)
        {
            //this->position.push_back(other.position);
        }
    }
}

Board::~Board()
{
    delete tile;
}

// save the position of the tile
void Board::putTile2Board(Tile *tile, vector<vector<char> > position)
{
    this->tile = tile;
    this->position[this->row][this->col] = position[row][col];
}

// print current board
vector<vector<char> > Board::printBoard()
{
    for (int ROW = 0; ROW < position.size(); ROW++)
    {
        for (int COL = 0; COL < position[ROW].size(); COL++)
        {
            std::cout << position[ROW][COL];
        }
        std::cout << std::endl;
    }
}
