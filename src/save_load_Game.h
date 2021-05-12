#ifndef ASSIGN2_SAVE_LOAD_GAME_H
#define ASSIGN2_SAVE_LOAD_GAME_H

#include "Player.h"
#include "Board.h"
#include <iostream>
#include <sstream>
#include <fstream>

const static int CMD_ILLEGAL=0;
const static int CMD_PLACE_TILE=1;
const static int CMD_REPLACE =2;
const static int CMD_SAVE=3;
const static int CMD_QUIT=4;



// Save Game data to file 
bool saveGame(std::string savePath, Player *currentPlayer, 
			Player *player1, Player *player2,
			  LinkedList *tileBag, Board *board);

// Load history Game data from file 
bool loadGame(std::string loadPath);

vector<std::string> split(std::string s, char delim);

bool loadPlayerFromStream(Player *player, std::ifstream &inStream);



#endif // ASSIGN2_SAVE_LOAD_GAME_H