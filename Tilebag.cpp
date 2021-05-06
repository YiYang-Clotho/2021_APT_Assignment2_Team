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

	//double loop to stock tile bag with 2 sets of tiles
	for(int setCounter = 0; setCounter < setTile; setCounter++){
		for(int colourCounter = 0; colourCounter < numberColour; colourCounter++){
			for(int shapeCounter = 0; shapeCounter < numberShape; shapeCounter++){

				Tile* tiles = new Tile (tcolour[colourCounter], tshape[shapeCounter]);
				//populates linklist with 72 ordered tiles
				tile_bag->addFront(tiles);
			}
		}
	}

	std::random_device engine;
	int random = 0;
	Tile* emptyTile = new Tile("");
	tile_bag->addFront(emptyTile);

	int totalTile = 72;
	//random number generator
	for(int tileCounter = 0; tileCounter < totalTile; tileCounter++){
		std::uniform_int_distribution<int> udist(1,((tile_bag->size())-1));
		random = udist(engine);

		//uses random no to pull from index of linklist then puts element at the front of new linklist
		shuffledtile_bag->addFront(tile_bag->getTile(random));
		//removes element from original linked list
		tile_bag->deleteTile(random);
	}
	//deletes original linked list
	tile_bag->deleteFront();
	delete tile_bag;
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