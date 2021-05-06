
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   LinkedList(LinkedList& other);
   
   int size();
   void clear();
   void addFront(Tile* tile);
   void addBack(Tile* tile);
   void deleteFront();
   void deleteTile(int i);
   Tile* getFront();
   Tile* getTile(int i);

   // get the length of the list
   int getSize();
   // add node to the front of the list
   void addFrom1st(Node* node);

   // add node to the middle of the list
   void addNode(Node* node);

   // add node to the end of the list
   void addToEnd(Node* node);


   // // remove the first node of the list
   // void removeFirstNode();

   // remove the node from the middle of the list
   void removeNode(Node* node);

   // // remove the last node of the list
   // void removeLastNode();

   void remove(int index);

   

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
