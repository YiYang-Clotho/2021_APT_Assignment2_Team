#include <iostream>

#include "Board.h"
#include "Types.h"

Board::Board()
{
    position.resize(BOARD_SIZE);

    for (unsigned int row = 0; row < position.size(); row++)
    {
        this->position[row].resize(BOARD_SIZE);
    }
}

// deep copy the board
Board::Board(Board &other) : position(other.position)
{
    // initilise the size of the board, get rid of junk
    for (unsigned int row = 0; row < BOARD_ROW; row++)
    {
        this->position[row].resize(BOARD_COL);
    }
    // copy
    for (unsigned int row = 0; row < this->position.size(); row++)
    {
        for (unsigned int col = 0; col < this->position[row].size(); col++)
        {
            //this->position[row][col](other.position[row][col]);
        }
    }
}

Board::~Board()
{
}

//save the position of the tile
void Board::putTile2Board(Colour colour, Shape shape, int row, int col)
{
    this->position[row][col]->setTile(colour, shape);
}

// print current board
void Board::printBoard()
{
    // first line
    std::cout << "   ";
    for (int row = 0; row < 26; row++){
        if (row >= 10){
            if (row == 25){
                std::cout << row;
            }else{
                std::cout << row;
                std::cout << " ";
            }
        }
        else{
            std::cout << row;
            std::cout << "  ";
        }
    }
    std::cout << std::endl;

    // second line
    std::cout << "  -------------------------------------------------------------------------------";
    std::cout << std::endl;

    for (unsigned int row = 0; row < position.size(); row++)
    {
        char c;
        c = row + 'A';
        std::cout << c << " |";
        for (unsigned int col = 0; col < position[row].size(); col++)
        {
            //Node *node = this->position[row][col];
            
            if (this->position[row][col] == nullptr){
                std::cout << "  |";
            }
            else{
                // std::cout << tile->getColour();
                // std::cout << *tile->getShape() + '0';
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}