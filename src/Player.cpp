#include "Player.h"
#include <stdio.h>
#include <iostream>

// Initial a new start player.
Player::Player()
{
	this->name = "";
	this->score = 0;
	this->tilesInHand = new LinkedList();
	this->lastPlayedTile = nullptr;
}

// Initial a new start player.
Player::Player(std::string name)
{
	this->name = name;
	score = 0;
	this->tilesInHand = new LinkedList();
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

	if (this->tilesInHand->head == nullptr)
	{

		Node *node = new Node();
		node->setTile(tile);
		this->tilesInHand->setHead(node);
		this->tilesInHand->head->next = nullptr;
		this->tilesInHand->head->prev = nullptr;
	}
	else
	{
		Node *node = new Node();
		node->setTile(tile);
		node->next = nullptr;
		node->prev = nullptr;
		this->tilesInHand->addNodeToEnd(node);
	}
	return true;
}

// remove the tile that has been place on the board
// reload the tilesInHand
void Player::playOneTile(Colour colour, Shape shape)
{
	int len = this->tilesInHand->getSize();
	int flag = 0;
	// record the position of the tile
	for (int counter = 1; counter <= len; counter++)
	{
		Tile *tmp = this->tilesInHand->getNode(counter)->getTile();
		if (tmp->colour == colour && tmp->shape == shape)
		{
			flag = counter;
		}
	}
	// Copy this Tile to last played tile, remove in the list
	Tile *copyTmp = new Tile(colour, shape);
	this->tilesInHand->remove(flag);
	this->lastPlayedTile = copyTmp;
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
void Player::replaceOneTile(Colour colour, Shape shape, LinkedList *tileBag)
{
	// delete current tile in hand
	int len = this->tilesInHand->getSize();
	int flag = 0;
	// record the position of the tile
	for (int counter = 1; counter <= len; counter++)
	{
		Tile *tmp = this->tilesInHand->getNode(counter)->getTile();
		if (tmp->colour == colour && tmp->shape == shape)
		{
			flag = counter;
		}
	}
	if (flag == 0)
	{
		std::cout << "You don't have the tile!" << std::endl;
	}
	else
	{
		this->tilesInHand->remove(flag);
	}

	// add current tile to the last of bag
	Node *node = new Node();
	Tile *copyTmp = new Tile(colour, shape);
	node->tile = copyTmp;
	tileBag->addNodeToEnd(node);

	// add a new tile in hand
	this->getNewTile(tileBag);
}

// Free the pointer.
Player::~Player()
{
	delete this->tilesInHand;
}

std::string Player::getName()
{
	return this->name;
}

void Player::setName(std::string name)
{
	this->name = name;
}

int Player::getScore()
{
	return this->score;
}

// set score
void Player::setScore(int score)
{
	this->score = score;
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
void Player::printTilesInHand()
{
	std::string tiles;
	for (int counter = 1; counter <= this->tilesInHand->getSize(); counter++)
	{
		Node *currentNode = this->tilesInHand->getNode(counter);
		Tile *currentTile = currentNode->getTile();
		Colour tempColour = currentTile->colour;
		Shape tempShape = currentTile->shape;
		tiles += tempColour + std::to_string(tempShape);
	}
	// print
	for (unsigned int counter = 0; counter < tiles.size(); counter++)
	{
		if (counter % 2 == 1 && counter < tiles.size() - 1)
		{
			std::cout << tiles[counter];
			
			std::cout << ",";
		}
		else
		{
			std::cout << tiles[counter];
		}
	}
	std::cout << std::endl;
}

// display tiles string
std::string Player::getTilesString()
{
	std::string tiles;
	for (int counter = 1; counter <= this->tilesInHand->getSize(); counter++)
	{
		Node *currentNode = this->tilesInHand->getNode(counter);
		Tile *currentTile = currentNode->getTile();
		Colour tempColour = currentTile->colour;
		Shape tempShape = currentTile->shape;
		tiles += tempColour + std::to_string(tempShape);
	}
	return tiles;
}

void Player::initialiseTilesInHand(LinkedList *tileBag)
{
	for (unsigned int counter = 0; counter < TILES_IN_HAND_NUM; counter++)
	{
		if (counter == 0)
		{
			this->tilesInHand->setHead(tileBag->head);
			tileBag->remove(1);
			this->tilesInHand->head->next = nullptr;
			this->tilesInHand->head->prev = nullptr;
		}
		else
		{
			Node *temp = tileBag->getNode(1);
			tileBag->remove(1);
			temp->next = nullptr;
			temp->prev = nullptr;
			this->tilesInHand->addNodeToEnd(temp);
		}
	}
}

// get a new tile after place one
void Player::getNewTile(LinkedList *tileBag)
{
	if (this->tilesInHand->getSize() > 0)
	{
		if (tileBag->getSize() != 0)
		{
			Node *temp = tileBag->getNode(1);
			tileBag->remove(1);
			temp->next = nullptr;
			temp->prev = nullptr;
			this->tilesInHand->addNodeToEnd(temp);
		}
	}
}
