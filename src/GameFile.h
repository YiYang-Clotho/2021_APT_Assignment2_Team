#ifndef ASSIGN2_GAME_FILE_H
#define ASSIGN2_GAME_FILE_H

#include "Player.h"
#include "Board.h"
#include <iostream>
#include <sstream>
#include <fstream>

class GameFile {
public:
	GameFile();
	~GameFile();
    
	void quit();
	std::string checkEOF();
	void getSelectionFromMenu();
	// Save Game data to file 
	void saveGame(std::string savePath, Player *currentPlayer, 
		Player *player1, Player *player2, LinkedList *tileBag, Board *board);

	// Load history Game data from file 
	void loadGame(std::string loadPath);

private:
	
	vector<std::string> split(std::string s, char delim);
	std::string& trim(std::string &s);;
};

#endif //ASSIGN2_GAME_FILE_H