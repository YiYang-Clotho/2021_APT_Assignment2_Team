#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

class Node
{
public:
   Node(Tile *tile, Node *prev, Node *next);
   Node(Node &other);
   ~Node();

   Tile *tile;
   Node *prev;
   Node *next;

   // get rtile-coodinate of the node
   Tile *getTile();

   // get front-coodinate of the node
   Node *getPrev();

   // get next-coodinate of the node
   Node *getNext();

   // setter for tile and next
   void setTile(Colour colour, Shape shape);
   void setPrev(Node *node);
   void setNext(Node *node);

   Node *getIndex(int index);

private:
};

#endif // ASSIGN2_NODE_H
