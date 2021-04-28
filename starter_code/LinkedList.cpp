#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;

}

LinkedList::~LinkedList() {
   delete head;
}

LinkedList::LinkedList(LinkedList& other){
   //clean out our own house first, get rid of junk
   delete this->head;

   //copy
   this->head = other.head;
}

// get the length of the list
int LinkedList::getSize(){
   int size = 0;
   if (this->head = nullptr){
      return size;
   }else{
      while (this->head->next != nullptr){
         size++;
      }
      return size;
   }
}

// add node to the front of the list
void LinkedList::addFrom1st(Node* node){
   node->setNext(this->head);
   this->head = node;
}

// add node to the middle of the list, nodes after the adding position should add 1
void LinkedList::addNode(Node* node){

}

// add node to the end of the list, only add the size of the list
void LinkedList::addToEnd(Node* node){
   // previouse the last node->next = node
//node->setFront();
   // node->next = nullptr
   node->setNext(nullptr);
}

// remove the node from the list
void LinkedList::removeNode(){
   // remove node from the front of the list

   // remove node from the middle of the list

   // remove node from the end of the list
}

void LinkedList::clear(){
   
}

