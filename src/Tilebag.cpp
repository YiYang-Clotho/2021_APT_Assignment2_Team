#include "TileCodes.h"
#include "Tilebag.h"

#include <random>
#include <cstdlib>
#include <sstream>

TileBag::TileBag()
{	
	this->tile_bag->head = nullptr;
	// //creates array for colour
	// Colour colours[] = {'R', 'O', 'Y', 'G', 'B', 'P'};

	// //creates array for shape
	// Shape shapes[] = {1, 2, 3, 4, 5, 6};

	// //LinkedList *tempTile_bag = new LinkedList();

	// //double loop to stock tile bag with 2 sets of tiles
	// for (unsigned int colourCounter = 0; colourCounter < TOTAL_COLOUR_NUM; colourCounter++)
	// {
	// 	for (unsigned int shapeCounter = 0; shapeCounter < TOTAL_SHAPE_NUM; shapeCounter++)
	// 	{
	// 		Node *tempNode = new Node(nullptr, nullptr, nullptr);
	// 		tempNode->setTile(colours[colourCounter], shapes[shapeCounter]);

	// 		// add each kind of tile twice
	// 		if (colourCounter == 0 && shapeCounter == 0)
	// 		{
	// 			this->tile_bag->setHead(tempNode);
	// 			this->tile_bag->addNodeToEnd(tempNode);
	// 		}
	// 		else
	// 		{
	// 			this->tile_bag->addNodeToEnd(tempNode);
	// 			this->tile_bag->addNodeToEnd(tempNode);
	// 		}
	// 	}
	// }

	// std::random_device engine;
	// int random = 0;
	// Tile* emptyTile = new Tile();
	// tempTile_bag->addTileTo1st(emptyTile);

	// int totalTile = 72;

	// //random number generator
	// for(int tileCounter = 0; tileCounter < totalTile; tileCounter++){
	// 	std::uniform_int_distribution<int> udist(1,((tile_bag->getSize())-1));
	// 	random = udist(engine);

	// 	// uses random number to pull from index of linklist
	// 	// puts element at the front of new linklist
	// 	tile_bag->addTileTo1st(tempTile_bag->getTile(random));
	// 	//removes element from original linked list
	// 	tempTile_bag->remove(random);
	// }
	// // clear and delete tempTile_bag tile_bag
	// tempTile_bag->remove1stNode();
	// delete tempTile_bag;
}

// creating a tile from the player's command and add it to the tile bag
void TileBag::loadTileBag(std::vector<std::string> tileArray)
{
	LinkedList *newShuffledTileBag = new LinkedList();
	for (unsigned int arraySize = 0; arraySize < tileArray.size(); arraySize++)
	{
		std::stringstream splitTile(tileArray[arraySize]);
		Colour tileColour = '\0';
		Shape tileShape = 0;
		splitTile >> tileColour;
		splitTile >> tileShape;
		Tile *tile = new Tile(tileColour, tileShape);
		newShuffledTileBag->addTileToEnd(tile);
	}
	setTileBag(newShuffledTileBag);
}

TileBag::~TileBag()
{
	delete tile_bag;
}

//gets TileBag
LinkedList *TileBag::getTileBag()
{
	return this->tile_bag;
}

void TileBag::setTileBag(LinkedList *tile_bag)
{
	this->tile_bag = tile_bag;
}

//get the 1st tile at the front of linked list
Tile *TileBag::get1stTile()
{
	return this->tile_bag->getFirstTile();
}

// remove the first tile and reload tileBag
LinkedList *TileBag::remove1stTile()
{
	this->tile_bag->remove1stNode();
	return this->tile_bag;
}

// get tiles number in the bag;
int TileBag::getSize()
{
	return this->tile_bag->getSize();
}