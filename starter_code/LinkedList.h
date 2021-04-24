
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   LinkedList(LinkedList& other);

   int size();

   void add_front(Node* data);
   void add_back(Node* data);

   //Contract: Elements should exist in the list to be deleted.
   void remove_front();
   void remove_back();

   void remove(int index);

   void clear();

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
