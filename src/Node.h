#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

class Node
{
public:
   Node();
   Node(Node &other);
   ~Node();

   Tile *tile;
   Node *prev;
   Node *next;

   // get tile colour of the node
   Tile *getTile();

   // set tile colour of the node
   void setTile(Colour colour, Shape shape);
   void setTile(Tile *tile);

   // get previous-coodinate of the node
   Node *getPrev();

   // set previous-coodinate of the node
   void setPrev(Node *node);

   // get next-coodinate of the node
   Node *getNext();

   // set next-coodinate of the node
   void setNext(Node *node);

   // set node
   void setNode(Node *node);

   // get node
   Node *getNode();

private:
};

#endif // ASSIGN2_NODE_H