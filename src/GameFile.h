#ifndef ASSIGN2_SAVE_LOAD_GAME_H
#define ASSIGN2_SAVE_LOAD_GAME_H

#include "Player.h"
#include "Board.h"
#include <iostream>
#include <sstream>
#include <fstream>

//const static int CMD_ILLEGAL=0;
//const static int CMD_PLACE_TILE=1;
//const static int CMD_REPLACE =2;
//const static int CMD_SAVE=3;
//const static int CMD_QUIT=4;
//

class GameFile {
public:
	// Save Game data to file 
	bool saveGame(std::string savePath, Player *currentPlayer, Player *player1, Player *player2, LinkedList *tileBag, Board *board);

	// Load history Game data from file 
	bool loadGame(std::string loadPath, Player **currentPlayer, Player **player1, Player **player2, LinkedList **tileBag, Board **board);
	void test_save_game_file();
	void test_load_game_file();
private:

	bool loadPlayerFromStream(Player *player, std::ifstream &inStream);

	vector<std::string> split(std::string s, char delim);
	std::string& trim(std::string &s);;


};




#endif // ASSIGN2_SAVE_LOAD_GAME_H