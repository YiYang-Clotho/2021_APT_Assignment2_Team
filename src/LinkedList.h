
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   LinkedList(LinkedList& other);

   // get the length of the list
   int getSize();

   // link with nodes
   // add node to the front of the list
   void addNodeFrom1st(Node* node);

   // add node to the middle of the list
<<<<<<< HEAD:src/LinkedList.h
   void addNode(Node *node, int position);
=======
   void addNode(Node* node);
>>>>>>> 4ca592634ea308da6e6f7af8c7a7d68796ec1e16:starter_code/LinkedList.h

   // add node to the end of the list
   void addNodeToEnd(Node* node);


   // // remove the first node of the list
   void remove1stNode();

   //remove known node
   void removeNode(Node* node);

   void remove(int index);

   void clear();

   // link with tiles
   // add node with known tile to the front of the list
   void addTileTo1st(Tile* tile);

   // add node with known tile to the last of the list
   void addTileToEnd(Tile* tile);


   Tile* getFront();

   //get a tile with a position
   Tile* getTile(int position);

<<<<<<< HEAD:src/LinkedList.h
   //get the node with a position
   Node *getNode(int position);

   // set first node
   void setHead(Node *node);

   Node *head;

   // initialise tile bag list
   void iniTileBag();

private:
   
=======
   // delete tile at given position
   void deleteTile(int position);

private:
   Node* head;
>>>>>>> 4ca592634ea308da6e6f7af8c7a7d68796ec1e16:starter_code/LinkedList.h
};

#endif // ASSIGN2_LINKEDLIST_H
