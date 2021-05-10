#ifndef __SAVE_LOAD_GAME__
#define __SAVE_LOAD_GAME__

#include "Player.h"
#include "Board.h"
#include "TileBag.h"
#include <iostream>
#include <sstream>
#include <fstream>

const static int CMD_ILLEGAL=0;
const static int CMD_PLACE_TILE=1;
const static int CMD_REPLACE =2;
const static int CMD_SAVE=3;
const static int CMD_QUIT=4;



// Save Game data to file 
bool saveGame(std::string savePath, Player* player1, Player* player2, TileBag* tileBag, Board* board);

// Load history Game data from file 
bool loadGame(std::string loadPath, Player* player1, Player* player2, TileBag* tileBag, Board* board);

// Verify the input command instruction
int isValidInstruction(std::string inputInstruction,Player* player);



#endif