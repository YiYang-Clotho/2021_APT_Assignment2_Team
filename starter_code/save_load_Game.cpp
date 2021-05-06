#include "save_load_Game.h"

bool saveGame(std::string savePath, Player * player1, Player * player2, TileBag * tileBag, Board * board) {

	std::ofstream file(savePath,std::ios_base::out);
	
	// Save Player 1
	file << player1->getName() << std::endl;
	file << player1->getScore() << std::endl;
	LinkedList* tiles = player1->getTilesInHand();
	for (int i = 0; i < tiles->getSize(); i++)
	{
		Tile*t = tiles->getTile(i);
		file << t->getColour << t->getShape ;
		if (i < tiles->getSize() - 1) {
			file << ',';
		}
	}
	file << std::endl;


	// Save Player 2
	file << player2->getName() << std::endl;
	file << player2->getScore() << std::endl;
	tiles = player2->getTilesInHand();
	for (int i = 0; i < tiles->getSize(); i++)
	{
		Tile* t = tiles->getTile(i);
		file << t->getColour << t->getShape;
		if (i < tiles->getSize() - 1) {
			file << ',';
		}
	}
	file << std::endl;

	//Save Board 
	{
		// FIXEME
	}

	// Save TileBag
	tiles = tileBag->getTileBag();
	for (int i = 0; i < tiles->getSize(); i++)
	{
		Tile* t = tiles->getTile(i);
		file << t->getColour << t->getShape;
		if (i < tiles->getSize() - 1) {
			file << ',';
		}
	}
	file << std::endl;


	return false;
}

bool loadGame(std::string loadPath, Player * player1, Player * player2, TileBag * tileBag, Board * board) {
	return false;
}
