#include "TileCodes.h"
#include "Node.h"
#include "TileBag.h"

#include <random>
#include <cstdlib>
#include <sstream>

TileBag::TileBag(){
	int setTile = 2;
	int numberColour = 6;
	int numberShape = 6;

	//creates array for colour
	Colour tcolour[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

	//creates array for shape
	Shape tshape[] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};

}

TileBag::~TileBag(){
	delete shuffledtile_bag;
}


//gets TileBag
LinkedList* TileBag::getTileBag(){
	return shuffledtile_bag;
}

//gets the 1st tile at the front of linked list
Tile* TileBag::getTiles(){
	return shuffledtile_bag->getFront();
}