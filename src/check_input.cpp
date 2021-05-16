#include "check_input.h"
#include <cctype>

// check player's Name, should be capital
bool isValidPlayerName(std::string playerName)
{
    int count = 0;
    for (unsigned int index = 0; index < playerName.size(); index++)
    {
        if (isupper(playerName[index]) == 0)
        {
            count++;
        }
    }

    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// if the input is place the tile, return true
bool isValidPlaceTile(std::string input, Player *player)
{
    // check the length of the input string
    if ((input.size() != 14 && input.size() != 15) ||
        input.compare(0, 6, "place ") != 0 ||
        input.compare(8, 4, " at ") != 0)
    {
        if (input.compare(0, 7, "replace") == 0)
        {
            return false;
        }
        else if (input.compare(0, 4, "save") == 0)
        {
            return false;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Invalid input format for placing a tile." << std::endl;
            return false;
        }
        
        
    }

    // check if the player has the tile
    std::string tilesString = player->getTilesString();
    std::size_t found = tilesString.find(input.substr(6, 2));
    if (found == std::string::npos)
    {
        std::cout << "player does not have this tile in hand" << std::endl;
        return false;
    }

    // check if the position is in the board area
    // check the col
    int col = input[12] - '0' - ASCII_DIF;
    if (col >= BOARD_SIZE || col < 0)
    {
        std::cout << "Invalid colonm value." << std::endl;
        return false;
    }

    // check the row
    int row = -1;
    if (input.size() == 14)
    {
        row = input[13] - '0';
    }
    else
    {
        row = input[14] - '0' + (input[13] - '0') * 10;
    }
    if (row < 0 || row >= BOARD_SIZE)
    {
        std::cout << "Invalid row value." << std::endl;
        return false;
    }
    return true;
}

// if the input is replace the tile, return true
bool isValidReplace(std::string input, Player *player)
{

    // check the length of the input string
    if ((input.size() != 10 && input.size() != 11) || (input.compare(0, 8, "replace ") != 0))
    {
        if ((input.compare(0, 5, "place") == 0))
        {
            return false;
        }
        else if (input.compare(0, 4, "save") == 0)
        {
            return false;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Invalid input format for replacing a tile." << std::endl;
            return false;
        }
    }

    // check if the player has the tile
    std::string tilesString = player->getTilesString();
    std::size_t found = tilesString.find(input.substr(8, 2));
    if (found == std::string::npos)
    {
        std::cout << "Player does not have this tile in hand" << std::endl;
        return false;
    }

    return true;
}

// if the input is save the game, return true
bool isValidSave(std::string input)
{
    // check the structure of the instruction
    if (input.compare(0, 5, "save ") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// check file name
bool isFileExist(std::string fileName)
{
    if (std::FILE *fh = fopen(fileName.c_str(), "r"))
    {
        fclose(fh);
        return true;
    }
    else
    {
        return false;
    }
}

// if the input is Quit
bool isQuit(std::string input)
{
    // check the structure of the instruction
    if (input.compare(0, 4, "Quit") == 0 || input.compare(0, 4, "quit") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// check the input is which instruction
// invalid, return 0
// place the tile, return 1
// replace the tile, return 2
// save the game, return 3
// quit return 4

int checkInstruction(std::string input, Player *player)
{   
    if (std::cin.eof())
    {
        std::cout << std::endl;
        std::cout << "Goodbye" << std::endl;
        exit(0);
    }
    else if (isQuit(input))
    {
        std::cout << std::endl;
        std::cout << "Goodbye" << std::endl;
        exit(0);
    }
    else if (isValidReplace(input, player))
    {
        return CMD_REPLACE;
    }
    else if (isValidSave(input))
    {
        return CMD_SAVE;
    }
    else if (isValidPlaceTile(input, player))
    {
        return CMD_PLACE_TILE;
    }
    else
    {
        return 0;
    }
}

bool allNum(std::string string)
{
    for (unsigned int index = 0; index < string.size(); index++)
    {
        int tmp = string[index] - '0';
        if (tmp >= 0 && tmp <= 9)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool validTile(std::string string)
{
    if (string.size() != 2)
    {
        return false;
    }
    else
    {
        //creates array for colour
        Colour colours[] = {'R', 'O', 'Y', 'G', 'B', 'P'};

        //creates array for shape
        Shape shapes[] = {1, 2, 3, 4, 5, 6};
        bool colourFlag = false;
        bool shapeFlag = false;

        char colour = string[0];
        int shape = string[1] - '0';
        for (unsigned int index = 0; index < TOTAL_COLOUR_NUM; index++)
        {
            if (colours[index] == colour)
            {
                colourFlag = true;
            }
        }
        for (unsigned int index = 0; index < TOTAL_SHAPE_NUM; index++)
        {
            if (shapes[index] == shape)
            {
                shapeFlag = true;
            }
        }

        if (colourFlag == false || shapeFlag == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool validPosition(std::string string)
{
    int row = 0;
    int col = 0;

    row = string[0] - '0' - ASCII_DIF;
    if (string.size() == 2)
    {
        col = string[1] - '0';
    }
    else if (string.size() == 3)
    {
        int digits = string[2] - '0';
        int tens = (string[1] - '0') * 10;
        col = tens + digits;
    }
    else
    {
        return false;
    }

    if (row >= 0 && row <= BOARD_SIZE - 1 && col >= 0 && col <= BOARD_SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool samePosCheck(vector<std::string> string)
{
    for (unsigned int index = 0; index < string.size(); ++index)
    {
        for (unsigned int next = index + 1; next < string.size(); ++next)
        {
            if (string[index].compare(string[next]) == 0)
            {
                return false;
            }
        }
    }
    return true;
}