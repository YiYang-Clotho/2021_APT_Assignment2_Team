#include "Player.h"

// Initial a new start player.

inline Player::Player(std::string name) {
	LinkedList *tilesInHand = new LinkedList;
	Player(name, 0, tilesInHand);
}

// Used to reload from file

inline Player::Player(std::string name, int score, LinkedList * tilesInHand) {

	this->name = name;
	this->score = score;
	this->tilesInHand = tilesInHand;

}

inline bool Player::addTile(Tile * tile) {
	if (tile == NULL) return false;
	this->tilesInHand->addTileToEnd(tile);
	return true;
}

// 玩家出牌 put one tile on the board, Not matched,return NULL

inline Tile * Player::playOneTile(int color, char shape) {
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

// Withdraw last played tile,如果出牌错误，请撤回上一次出的牌

inline bool Player::withdrawLastPlayedTile() {
	if (lastPlayedTile != NULL) {
		this->tilesInHand->addTileTo1st(lastPlayedTile);
		lastPlayedTile = NULL;
		return true;
	}
	else {
		return false;
	}
}

// 替换tile，把tilesInHand中的一个，从tile bag里替换, 替换了之后这个回合不出牌

inline bool Player::replaceOneTile(Tile * newTile, char oldTileColor, int oldTileShape) {
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

// Free the pointer.

inline Player::~Player() {
	delete this->tilesInHand;
}

inline std::string Player::getName() {
	return name;
}

inline void Player::setName(std::string name) {
	this->name = name;
}

inline int Player::getScore() {
	return score;
}

// Add the earned score in once play.

inline void Player::increaseScore(int earnedScore) {
	this->score += earnedScore;
}

inline void Player::setTilesInHand(LinkedList * tilesInHand) {
	this->tilesInHand = tilesInHand;
}
