#include "Player.h"

// Initial a new start player.
Player::Player(string name) {
	LinkedList *tilesInHand = new LinkedList;
	Player(name, 0, tilesInHand);
}

// Free the pointer.
Player::~Player() {
	delete this->tilesInHand;
}

// Used to reload from file
Player::Player(string name, int score, LinkedList * tilesInHand) {

	this->name = name;
	this->score = score;
	this->tilesInHand = tilesInHand;

}

bool Player::addTile(Tile * tile) {
	if (tile == NULL) return false;
	this->tilesInHand->addTileToEnd(tile);
	return true;
}

// put one tile on the board, Not matched,return NULL
Tile * Player::playOneTile(int color, char shape) {
	int len = this->tilesInHand->getSize();
	for (int i = 0; i < len; i++) {
		Tile* tmp = this->tilesInHand->getTile(i);
		if (tmp->getColour() == color&& tmp->getShape() == shape) {
			// Copy this Tile
			Tile* copyTmp = new Tile(*tmp);
			this->tilesInHand->remove(i);
			this->lastPlayedTile = copyTmp;
			return copyTmp;
		}
	}
	// if NO matched Tiles in hand, Return Null
	return NULL;
}

// Withdraw last played tile
bool Player::withdrawLastPlayedTile() {
	if (lastPlayedTile != NULL) {
		this->tilesInHand->addTileTo1st(lastPlayedTile);
		lastPlayedTile = NULL;
		return true;
	}
	else {
		return false;
	}
}

bool Player::replaceOneTile(Tile * newTile, char oldTileColor, int oldTileShape) {
	int len = this->tilesInHand->getSize();
	for (int i = 0; i < len; i++) {
		Tile* tmp = this->tilesInHand->getTile(i);
		if (tmp->getColour() == oldTileColor&& tmp->getShape() == oldTileShape) {
			this->tilesInHand->remove(i);
			this->tilesInHand->addTileToEnd(newTile);
			return true;
		}
	}
	return false;

}

string Player::getName() {
	return name;
}

void Player::setName(string name) {
	this->name = name;
}

int Player::getScore() {
	return score;
}

// Add the earned score in once play.
void Player::increaseScore(int earnedScore) {
	this->score += earnedScore;
}

void Player::setTilesInHand(LinkedList * tilesInHand) {
	this->tilesInHand = tilesInHand;
}

LinkedList * Player::getTilesInHand()
{
	return this->tilesInHand;
}
