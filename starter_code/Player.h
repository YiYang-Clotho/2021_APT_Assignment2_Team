#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include "LinkedList.h"
#include <string>


class Player{
public:

	// Initial a new start player.
	Player(std::string name);

	// Used to reload from file
	Player(std::string name, int score, LinkedList *tilesInHand);

	// Add a new Tile to current palyer hand 
	bool addTile(Tile* tile);

	// put one tile on the board, Not matched,return NULL
	Tile * playOneTile(int color, char shape);

	// Withdraw last played tile
	bool withdrawLastPlayedTile();

	// Replace tile，add one to tilesInHand from tile bag, 
	bool replaceOneTile(Tile* newTile, char oldTileColor, int oldTileShape);

	// Free the pointer.
	~Player();

	// Encapsulate the name
	string getName();
	void setName(std::string name);

	// Get current score
	int getScore();

	void setScore(int score) {
		this->score = score;
	}

	// Add the earned score in once play.
	void increaseScore(int earnedScore);

	// Set Tiles in hand
	void setTilesInHand(LinkedList *tilesInHand);

	// Get Tiles in hand
	LinkedList* getTilesInHand();



private:
	// The Tiles in curent player hand
	LinkedList* tilesInHand;

	// Player's name 
	string name;

	// Player's score
	int score;

	// Used for withdraw last time played Tile, 
	Tile* lastPlayedTile;
};


#endif