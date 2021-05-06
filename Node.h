
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

class Node {
public:

   Node(Tile* tile, Node* next);

   Tile*    tile;
   Node*    next;

   Tile* getTile();
};

#endif // ASSIGN2_NODE_H
