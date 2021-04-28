
#include "Tile.h"
#include "Node.h"

Tile::Tile(Tile &other)
{
    this->colour = other.colour;
    this->shape = other.shape;
}

Tile::~Tile()
{
}
