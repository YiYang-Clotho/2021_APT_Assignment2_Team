#ifndef ASSIGN2_BASEGAME_H
#define ASSIGN2_BASEGAME_H

#include<vector>
#include"Tile.h"
#include"LinkedList.h"

// alias name
using Board = std::vector<std::vector<Tile>>;

class BaseGame {
public:
	BaseGame(std::string player1,std::string player2);
	~BaseGame();
	void play();
	void load(std::string filename);

private:
	Board board;
	std::string a_name;
	std::string b_name;
	int a_score = 0;
	int b_score = 0;
	int flag =1 ;// 1 for A, 0 for B
	LinkedList* a_hand;
	LinkedList* b_hand;
	LinkedList* bag;
	void drawBoard();
	void handleCommand(std::string command);
	void updateScore(int row,int col);
	void updateHand(Tile tile);
	void replaceHand(Tile tile);
	void saveGame(std::string filename);
	void playTurn();
	std::string boardState();
	void playTurnBefore();
	void checkEnd();


};


#endif


