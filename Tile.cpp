#include "TitleCodes.h"
#include "Tile.h"

Tile::Tile(std::string empty){
	this->empty = empty;
}

Tile::Tile(Colour colour, Shape shape){
	this->colour = colour;
	this->shape = shape;
}

Colour Tile::getColour(){
	return this->colour;
}

Shape Tile::getShape(){
	return this->shape;
}

std::string Tile::getEmpty(){
	return this->empty;
}
