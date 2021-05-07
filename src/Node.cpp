#include <iostream>
#include "Node.h"

Node::Node(Tile *tile, Node *prev, Node *next)
{
   this->tile = tile;
   this->prev = prev;
   this->next = next;
}

Node::~Node()
{
   delete tile;
   delete prev;
   delete next;
}

Node::Node(Node &other)
{
   Node *node = new Node(nullptr, nullptr, nullptr);
   node->setTile(other.getTile()->colour, other.getTile()->shape);
   node->setPrev(other.getPrev());
   node->setNext(other.getNext());
}

Tile *Node::getTile()
{
   return tile;
}

// get front-coodinate of the node
Node *Node::getPrev()
{
   return prev;
}

// get next-coodinate of the node
Node *Node::getNext()
{
   return next;
}

void Node::setTile(Colour colour, Shape shape)
{
   this->tile->colour = colour;
   this->tile->shape = shape;
}

void Node::setPrev(Node *node)
{
   this->prev = node;
   node->next = this->prev;
}

// Node *Node::getIndex(int index)
// {
// }

void Node::setNext(Node *node)
{
   this->next = node;
   node->prev = this->next;
}

