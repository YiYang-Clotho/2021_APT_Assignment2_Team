#ifndef ASSIGN2_GAME_FILE_H
#define ASSIGN2_GAME_FILE_H

#include "Player.h"
#include "Board.h"
#include "check_input.h"
#include <iostream>
#include <sstream>
#include <fstream>

class GameFile {
public:
	GameFile();
	~GameFile();
	std::string checkEOF();
	void getSelectionFromMenu();
	// Save Game data to file 
	void saveGame(std::string savePath, Player *currentPlayer, 
		Player *player1, Player *player2, LinkedList *tileBag, Board *board);

	// Load history Game data from file 
	bool loadGame(std::string loadPath);
	void loadGameInfo(std::string loadPath, Player **currentPlayer, 
		Player *player1, Player *player2, LinkedList *tileBag, Board *board);

private:
	
	vector<std::string> split(std::string s, char delim);
	vector<std::string> split(std::string string, 
									char delim1, char delim2);
	std::string& trim(std::string &s);;
};

#endif //ASSIGN2_GAME_FILE_H