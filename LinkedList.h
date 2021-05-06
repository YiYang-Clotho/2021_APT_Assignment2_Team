
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

   void clear();

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
