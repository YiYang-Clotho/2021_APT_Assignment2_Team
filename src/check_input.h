#ifndef ASSIGN2_CHECK_INPUT_H
#define ASSIGN2_CHECK_INPUT_H

#include <iostream>
#include "Player.h"

#define CMD_VALID 1
#define CMD_PLACE_TILE 1
#define CMD_REPLACE 2
#define CMD_SAVE 3
#define CMD_QUIT 4

// if the input is place the tile, return true
bool isValidPlaceTile(std::string input, Player *player);

// if the input is replace the tile, return true
bool isValidReplace(std::string input, Player *player);

// if the input is save the game, return true
bool isValidSave(std::string input);

// if the input is Quit
bool isQuit(std::string input);

// check player's Name, should be capital
bool isValidPlayerName(std::string playerName);

// check load game
bool isFileExist(std::string fileName);

bool allNum(std::string string);
bool validTile(std::string string);
bool validPosition(std::string string);
bool samePosCheck(vector<std::string> string);

// check the input is which instruction
// invalid, return 0
// place the tile, return 1
// replace the tile, return 2
// save the game, return 3
// quit return 4
int checkInstruction(std::string input, Player *player);

#endif // ASSIGN2_CHECK_INPUT_H