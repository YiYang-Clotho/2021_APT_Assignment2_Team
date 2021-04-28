#include <iostream>
#include "Node.h"

Node::Node(Tile *tile, Node *front, Node *next)
{
   this->tile = tile;
   this->front = front;
   this->next = next;
}

Node::~Node()
{
   delete tile;
   delete front;
   delete next;
}

Node::Node(Node &other)
{
   Node *node = new Node(nullptr, nullptr, nullptr);
   node->setTile(other.getTile()->colour, other.getTile()->shape);
   node->setFront(other.getFront());
   node->setNext(other.getNext());
}

Tile *Node::getTile()
{
   return tile;
}

// get front-coodinate of the node
Node *Node::getFront()
{
   return front;
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

void Node::setFront(Node *node)
{
   this->front = node;
   node->next = this->front;
}

void Node::setNext(Node *node)
{
   this->next = node;
   node->front = this->next;
}

Node *Node::getIndex(int index)
{
}
