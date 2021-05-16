#include <random>
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
   this->head = nullptr;
}

LinkedList::~LinkedList()
{
   this->head = nullptr;
   delete head;
}

LinkedList::LinkedList(LinkedList &other)
{
   //clean out our own house first, get rid of junk
   delete this->head;

   //copy
   this->head = other.head;
}

// get the length of the list
int LinkedList::getSize()
{
   int size = 0;
   Node *currentNode = new Node();
   currentNode = this->head;
   while (currentNode != nullptr)
   {
      size++;
      currentNode = currentNode->next;
   }
   return size;
}

// add node to the front of the list
void LinkedList::addNodeFrom1st(Node *node)
{
   node->setNext(this->head);
   this->head = node;
}

// add node to the middle of the list
// nodes after the adding position should add 1
void LinkedList::addNode(Node *node, int position)
{
}

// add node to the end of the list, only add the size of the list
void LinkedList::addNodeToEnd(Node *node)
{
   // previouse the last node->next = node
   this->getNode(this->getSize())->setNext(node);
}

// remove the node from the list
// remove node from the front of the list
void LinkedList::remove1stNode()
{
   Node *currentNode = this->head->next;
   this->head = currentNode->next;
   this->head->setPrev(nullptr);
}

void LinkedList::removeNode(Node *node)
{
   // remove node from the front of the list
   if (this->head == node)
   {
      this->head = node->next;
   }
   else
   {
      Node *current = new Node();
      current = this->head;
      while (current->next != node)
      {
         current = current->next;
      }
      current->setNext(node->next);
   }
}

// remove node from known position
void LinkedList::remove(int position)
{
   if (position > 0 && position <= this->getSize())
   {
      // remove head
      if (this->getSize() == 1)
      {
         this->head = nullptr;
      }
      else if (position == 1)
      {

         this->head = this->head->next;
         this->head->prev = nullptr;
      }
      // others
      else if (position == this->getSize())
      {
         this->getNode(position - 1)->next = nullptr;
      }
      else
      {
         this->getNode(position - 1)->setNext(this->getNode(position + 1));
         this->getNode(position)->setPrev(this->getNode(position - 1));
      }
   }
   else
   {
      std::cout << std::endl;
      std::cerr << "Invalid Input!" << std::endl;
   }
}

//add a node at the front
void LinkedList::addTileTo1st(Tile *tile)
{
   Node *add = new Node();
   add->setTile(tile->getColour(), tile->getShape());
   add->setNext(this->head);
   this->head->setNext(add);
}

//add a node at the back
void LinkedList::addTileToEnd(Tile *tile)
{
   Node *add = new Node();
   add->setTile(tile->getColour(), tile->getShape());
   Node *currentNode = this->head;
   if (currentNode == nullptr)
   {
      this->head = add;
   }
   else
   {
      while (currentNode->next != nullptr)
      {
         currentNode = currentNode->next;
      }
      currentNode->setNext(add);
   }
}

//get a tile with a position
Tile *LinkedList::getTile(int position)
{
   if (position > 0 && position <= this->getSize())
   {
      int count = 1;
      Node *currentNode = this->head;
      while (count < position)
      {
         currentNode = currentNode->next;
         count++;
      }
      return currentNode->getTile();
   }
   else
      std::cerr << "Invalid Tile!" << std::endl;
   return nullptr;
}

//get the node with a position
Node *LinkedList::getNode(int position)
{
   if (position <= 0 || position > this->getSize())
   {
      return nullptr;
   }
   else
   {
      int count = 1;
      Node *currentNode = this->head;
      while (count != position)
      {
         currentNode = currentNode->next;
         count++;
      }
      return currentNode;
   }
}

//return a tile on top of a list
Tile *LinkedList::getFirstTile()
{
   if (this->head != nullptr)
   {
      return this->head->getTile();
   }
   else
   {
      return nullptr;
   }
}

// set first node
void LinkedList::setHead(Node *node)
{
   this->head = node;
}

// initialise tile bag list
void LinkedList::iniTileBag()
{
   //creates array for colour
   Colour colours[] = {'R', 'O', 'Y', 'G', 'B', 'P'};

   //creates array for shape
   Shape shapes[] = {1, 2, 3, 4, 5, 6};

   LinkedList *tempTile_bag = new LinkedList();

   //double loop to stock tile bag - once
   for (unsigned int colourIndex = 0; colourIndex < 6; colourIndex++)
   {
      for (unsigned int shapeIndex = 0; shapeIndex < 6; shapeIndex++)
      {

         Tile *tempTile = new Tile(colours[colourIndex], shapes[shapeIndex]);
         Node *tempNode = new Node();
         tempNode->setTile(tempTile);

         if (colourIndex == 0 && shapeIndex == 0)
         {
            tempTile_bag->head = tempNode;
         }
         else
         {
            tempTile_bag->addNodeToEnd(tempNode);
         }
      }
   }

   // add each kind of tile twice
   for (unsigned int i = 0; i < 6; i++)
   {
      for (unsigned int j = 0; j < 6; j++)
      {
         Tile *tempTile = new Tile(colours[i], shapes[j]);
         Node *tempNode = new Node();
         tempNode->setTile(tempTile);

         tempTile_bag->addNodeToEnd(tempNode);
      }
   }

   // shuffled the tiles
   std::random_device engine;
   int random = 0;

   //random number generator
   for (unsigned int counter = 0; counter < TOTAL_TILES_NUM; counter++)
   {
      std::uniform_int_distribution<int> udist(1, tempTile_bag->getSize());
      random = udist(engine);

      // use random number to pull from index of linked list
      // put element at the front of new linklist
      if (counter == 0)
      {
         this->setHead(tempTile_bag->getNode(random));
         tempTile_bag->remove(random);
         this->head->next = nullptr;
         this->head->prev = nullptr;
      }
      else
      {
         Node *temp = tempTile_bag->getNode(random);
         tempTile_bag->remove(random);
         temp->next = nullptr;
         temp->prev = nullptr;
         this->addNodeToEnd(temp);
      }
      //this->addTileTo1st(tempTile_bag->getTile(random));
      //removes element from original linked list
   }
   // clear and delete tempTile_bag tile_bag
   //tempTile_bag->remove1stNode();
   delete tempTile_bag;
}

// initialise tile bag list
void LinkedList::orderlyTileBag()
{
   //creates array for colour
   Colour colours[] = {'R', 'O', 'Y', 'G', 'B', 'P'};

   //creates array for shape
   Shape shapes[] = {1, 2, 3, 4, 5, 6};

   //double loop to stock tile bag - once
   for (unsigned int colourIndex = 0; colourIndex < 6; colourIndex++)
   {
      for (unsigned int shapeIndex = 0; shapeIndex < 6; shapeIndex++)
      {
         Tile *tempTile = new Tile(colours[colourIndex], shapes[shapeIndex]);
         Node *tempNode = new Node();
         tempNode->setTile(tempTile);

         if (colourIndex == 0 && shapeIndex == 0)
         {
            this->head = tempNode;
         }
         else
         {
            this->addNodeToEnd(tempNode);
         }
      }
   }

   // add each kind of tile twice
   for (unsigned int i = 0; i < 6; i++)
   {
      for (unsigned int j = 0; j < 6; j++)
      {
         Tile *tempTile = new Tile(colours[i], shapes[j]);
         Node *tempNode = new Node();
         tempNode->setTile(tempTile);

         this->addNodeToEnd(tempNode);
      }
   }
}