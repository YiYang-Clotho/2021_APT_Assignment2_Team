#ifndef __SAVE_LOAD_GAME__
#define __SAVE_LOAD_GAME__

#include "Player.h"
#include "Board.h"
#include "TileBag.h"
#include <iostream>
#include <sstream>
#include <fstream>

bool saveGame(std::string savePath, Player* player1, Player* player2, TileBag* tileBag, Board* board);

bool loadGame(std::string loadPath, Player* player1, Player* player2, TileBag* tileBag, Board* board);

#endif