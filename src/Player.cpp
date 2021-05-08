#include "Player.h"
#include <stdio.h>

// Initial a new start player.
Player::Player(std::string name)
{
	this->tilesInHand = nullptr;
	this->name = name;
}

// Used to reload from file
Player::Player(std::string name, int score, LinkedList *tilesInHand)
{

	this->name = name;
	this->score = score;
	this->tilesInHand = tilesInHand;
}

bool Player::addTile(Tile *tile)
{
	if (tile == NULL)
		return false;
	this->tilesInHand->addTileToEnd(tile);
	return true;
}

// put one tile on the board, Not matched,return NULL
Tile *Player::playOneTile(int color, char shape)
{
	int len = this->tilesInHand->getSize();
	for (int i = 0; i < len; i++)
	{
		Tile *tmp = this->tilesInHand->getTile(i);
		if (tmp->getColour() == color && tmp->getShape() == shape)
		{
			// Copy this Tile
			Tile *copyTmp = new Tile(*tmp);
			this->tilesInHand->remove(i);
			this->lastPlayedTile = copyTmp;
			return copyTmp;
		}
	}
	// if NO matched Tiles in hand, Return Null
	return NULL;
}

// Withdraw last played tile
bool Player::withdrawLastPlayedTile()
{
	if (lastPlayedTile != NULL)
	{
		this->tilesInHand->addTileTo1st(lastPlayedTile);
		lastPlayedTile = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

// replace one tile
bool Player::replaceOneTile(Tile *newTile, char oldTileColor, int oldTileShape)
{
	int len = this->tilesInHand->getSize();
	for (int i = 0; i < len; i++)
	{
		Tile *tmp = this->tilesInHand->getTile(i);
		if (tmp->getColour() == oldTileColor && tmp->getShape() == oldTileShape)
		{
			this->tilesInHand->remove(i);
			this->tilesInHand->addTileToEnd(newTile);
			return true;
		}
	}
	return false;
}

// Free the pointer.
Player::~Player()
{
	delete this->tilesInHand;
}

std::string Player::getName()
{
	return name;
}

void Player::setName(std::string name)
{
	this->name = name;
}

int Player::getScore()
{
	return score;
}

// Add the earned score in once play.
void Player::increaseScore(int earnedScore)
{
	this->score += earnedScore;
}

// set the tiles
void Player::setTilesInHand(LinkedList *tilesInHand)
{
	this->tilesInHand = tilesInHand;
}

// get the Tiles list that the player have
LinkedList *Player::getTilesInHand()
{
	return this->tilesInHand;
}
// display tiles string
std::string Player::displayTilesInHand()
{
	std::string tiles = "";
	Node *currentNode = this->tilesInHand->getHeadNode();
	Tile *currentTile = currentNode->getTile();

	// add tiles detail to string
	while (!(currentNode->getNext() == nullptr))
	{
		Colour tempColour = currentTile->colour;
		Shape tempShape = currentTile->shape;
		tiles += tempColour + std::to_string(tempShape) + " ";
		currentNode = currentNode->next;
		currentTile = currentNode->getTile();
	}
	Colour tempColour = currentTile->colour;
	Shape tempShape = currentTile->shape;
	tiles += tempColour + std::to_string(tempShape);

	return tiles;
}

LinkedList* Player::initialiseTilesInHand(TileBag* tileBag){
	for (size_t tileNum = 0; tileNum < TWO_PLAYER_MODE_TILES_IN_HAND_NUM; tileNum++)
	{
		this->addTile(tileBag->get1stTile());
		tileBag->remove1stTile();
	}
	return this->tilesInHand;
}
