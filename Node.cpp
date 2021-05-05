
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   this->tile = tile;
   this->next = next;
}

Tile* Node::getTile(){
   return tile;
}
Node::Node(Node& other)
{
   // TODO
}
