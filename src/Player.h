#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Board.h"

class Player
{
public:
	// Initial a new start player.
	Player();

	// Initial a new start player.
	Player(std::string name);

	// Used to reload from file
	Player(std::string name, int score, LinkedList *tilesInHand);

	// Add a new Tile to current palyer hand
	bool addTile(Tile *tile);

	// remove the tile that has been place on the board
	// reload the tilesInHand
	void playOneTile(Colour colour, Shape shape);

	// get a new tile after place one
	void getNewTile(LinkedList *tileBag);

	// Withdraw last played tile,
	bool withdrawLastPlayedTile();

	// replace tile

	void replaceOneTile(Colour colour, Shape shape, LinkedList *tileBag);

	// Free the pointer.
	~Player();

	// Encapsulate the name
	std::string getName();
	void setName(std::string name);

	// Get current score
	int getScore();

	// set score
	void setScore(int score);

	// Add the earned score in once play.
	void increaseScore(int earnedScore);

	// Set the Tile
	void setTilesInHand(LinkedList *tilesInHand);

	// get the Tile
	LinkedList *getTilesInHand();

	// display tiles string
	void printTilesInHand();

	// display tiles string
	std::string getTilesString();

	// set initilise tiles in hand before the 1st round
	//LinkedList* initialiseTilesInHand(TileBag *tileBag, Player player);

	void initialiseTilesInHand(LinkedList *tileBag);

	void placeLastTile(Board *board);

private:
	// The Tiles in curent player hand
	LinkedList *tilesInHand = new LinkedList();
	// Player's name
	std::string name;

	// Player's score
	int score;

	// Used for withdraw last time played Tile,
	Tile *lastPlayedTile;
};

#endif