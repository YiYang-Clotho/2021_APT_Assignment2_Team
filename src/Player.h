#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"


class Player{
public:
<<<<<<< HEAD:src/Player.h
	// Initial a new start player.
	Player();
=======
    Player(std::string name, int score, LinkedList *tilesInHand);
>>>>>>> 4ca592634ea308da6e6f7af8c7a7d68796ec1e16:starter_code/Player.h

	// Initial a new start player.
	Player(std::string name);

	// Used to reload from file
	Player(std::string name, int score, LinkedList *tilesInHand);

	// Add a new Tile to current palyer hand 
	bool addTile(Tile* tile);

<<<<<<< HEAD:src/Player.h
	// remove the tile that has been place on the board
	// reload the tilesInHand
	void playOneTile(Colour colour, Shape shape);

	// get a new tile after place one
	void getNewTile(LinkedList *tileBag);
=======
	// put one tile on the board, Not matched,return NULL
	Tile * playOneTile(int color, char shape);
>>>>>>> 4ca592634ea308da6e6f7af8c7a7d68796ec1e16:starter_code/Player.h

	// Withdraw last played tile
	bool withdrawLastPlayedTile();

<<<<<<< HEAD:src/Player.h
	// replace tile
=======
	// Replace tile，add one to tilesInHand from tile bag, 
>>>>>>> 4ca592634ea308da6e6f7af8c7a7d68796ec1e16:starter_code/Player.h
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

<<<<<<< HEAD:src/Player.h
	// display tiles string
	void printTilesInHand();
=======

>>>>>>> 4ca592634ea308da6e6f7af8c7a7d68796ec1e16:starter_code/Player.h

	// display tiles string
	std::string getTilesString();

	// set initilise tiles in hand before the 1st round
	//LinkedList* initialiseTilesInHand(TileBag *tileBag, Player player);

	void initialiseTilesInHand(LinkedList *tileBag);

	
private:
	// The Tiles in curent player hand
	LinkedList *tilesInHand = new LinkedList();
	// Player's name 
	string name;

	// Player's score
	int score;

	// Used for withdraw last time played Tile, 
	Tile* lastPlayedTile;
};


#endif