#include <iostream>
#include "Node.h"

Node::Node()
{
   this->tile = nullptr;
   this->prev = nullptr;
   this->next = nullptr;
}

Node::~Node()
{
   this->tile = nullptr;
   this->prev = nullptr;
   this->next = nullptr;
   delete tile;
   delete prev;
   delete next;
}

Node::Node(Node &other)
{
   Node *node = new Node();
   node->setTile(other.getTile()->colour, other.getTile()->shape);
   node->setPrev(other.getPrev());
   node->setNext(other.getNext());
}

Tile *Node::getTile()
{
   return this->tile;
}

// get front-coodinate of the node
Node *Node::getPrev()
{
   return this->prev;
}

// get next-coodinate of the node
Node *Node::getNext()
{
   return this->next;
}

void Node::setTile(Colour colour, Shape shape)
{
   this->tile->colour = colour;
   this->tile->shape = shape;
}

void Node::setTile(Tile *tile)
{
   this->tile = tile;
}

void Node::setPrev(Node *node)
{
   this->prev = node;
   node->next = this;
}

void Node::setNext(Node *node)
{
   this->next = node;
   node->prev = this;
}

// set node
void Node::setNode(Node *node)
{
   this->tile = node->tile;
   this->prev = node->prev;
   this->next = node->next;
}

// get node
Node *Node::getNode()
{
   return this;
}