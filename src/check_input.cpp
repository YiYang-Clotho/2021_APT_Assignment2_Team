#include "check_input.h"
#include <cctype>

// check player's Name, should be capital
bool checkValidPlayerName(std::string playerName)
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
    bool validFlag = false;

    // check the length of the input string
    if (input.size() == 14 || input.size() == 15)
    {
        validFlag = true;
    }
    else
    {
        validFlag = false;
    }

    // check the structure of the instruction
    if (input.compare(0, 6, "place ") == 0 && input.compare(8, 4, " at ") == 0)
    {
        validFlag = true;
    }
    else
    {
        validFlag = false;
    }

    int counter = 0;
    // check if the player has the tile
    std::string tilesString = player->getTilesString();
    for (unsigned int pos = 0; pos < tilesString.size() - 2; pos += 2)
    {
        if (input.compare(6, 2, tilesString.substr(pos, 2)) == 0)
        {
            
            counter++;
        }
    }

    if (counter == 0)
    {
        validFlag = false;
    }
    else
    {
        validFlag = true;;
    }
    

    // check the position that is in the board area
    // check the col
    int col = input[12] - '0' - ASCII_DIF;
    if (col <= BOARD_SIZE && col >= 0)
    {
        validFlag = true;
    }
    else
    {
        validFlag = false;
    }

    // check the row
    int tempRow = -1;
    if (input.size() == 14)
    {
        tempRow = input[13] - '0';
        if (tempRow >= 0 && tempRow < 10)
        {
            validFlag = true;
        }
        else
        {
            validFlag = false;
        }
    }
    else if (input.size() == 15)
    {
        int tempTen = (input[13] - '0') * 10;
        tempRow = tempTen + (input[14] - '0');
        if (tempRow >= 10 && tempRow < BOARD_SIZE)
        {
            validFlag = true;
        }
        else
        {
            validFlag = false;
        }
    }

    if (validFlag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// if the input is replace the tile, return true
bool isValidReplace(std::string input, Player *player)
{
    bool validFlag = false;

    // check the length of the input string
    if (input.size() == 10 || input.size() == 11)
    {
        validFlag = true;
    }
    else
    {
        validFlag = false;
    }

    // check the structure of the instruction
    if (input.compare(0, 8, "replace ") == 0)
    {
        validFlag = true;
    }
    else
    {
        validFlag = false;
    }

    int counter = 0;
    // check if the player has the tile
    std::string tilesString = player->getTilesString();
    for (unsigned int pos = 0; pos < tilesString.size() - 2; pos += 2)
    {
        if (input.compare(8, 2, tilesString.substr(pos, 2)) == 0)
        {
            counter++;
        }
        
    }
    if (counter == 0)
    {
        validFlag = false;
    }
    else
    {
        validFlag = true;
    }

    if (validFlag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
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
    if (input.compare(0, 4, "Quit") == 0 
        || input.compare(0, 4, "quit") == 0)
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
int checkInstruction(std::string input)
{
    int flag = 0;
    if (checkValidPlayerName(input))
    {
        flag = CMD_VALID;
    }

    if (isValidSave(input))
    {
        // std::string fileName = input.substr(5, input.size() - 5);
        
        flag = CMD_SAVE;
    }
    
    if (isQuit(input))
    {
        flag = CMD_QUIT;
    }

    return flag;
}
int checkInstruction(std::string input, Player *player)
{
    int flag = 0;
    if (isValidPlaceTile(input, player))
    {
        flag = CMD_PLACE_TILE;
    }
    
    if (isValidReplace(input, player))
    {
        flag = CMD_REPLACE;
    }

    return flag;
}
