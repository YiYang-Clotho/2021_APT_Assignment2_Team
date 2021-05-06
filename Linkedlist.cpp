#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
   this->head = nullptr;
}

LinkedList::~LinkedList(){
   clear();
}

LinkedList::LinkedList(LinkedList &other){
   //clean out our own house first, get rid of junk
   delete this->head;

   //copy
   this->head = other.head;
}

void LinkedList::clear() {
	Node* node = head;
	while (node != nullptr) {
		Node* temp = node->next;
		delete node;
		node = temp;
	}
	head = nullptr;
}

// get the length of the list
int LinkedList::getSize(){
   int size = 0;
   if (this->head = nullptr){
      return size;
   }
   else{
      while (this->head->next != nullptr){
         size++;
      }
      return size;
   }
}

// add node to the front of the list
void LinkedList::addFrom1st(Node *node){
   node->setNext(this->head);
   this->head = node;
}

// add node to the middle of the list, nodes after the adding position should add 1
void LinkedList::addNode(Node *node){

}

// add node to the end of the list, only add the size of the list
void LinkedList::addToEnd(Node *node){
   // previouse the last node->next = node
   Node *current = new Node(nullptr, nullptr, nullptr);
   current = this->head;
   while (current->next != nullptr)
   {
      current = current->next;
   }
   current->setNext(node);

   // node->next = nullptr
   node->setNext(nullptr);
}

// remove the node from the list
void LinkedList::removeNode(Node *node){
   // remove node from the front of the list
   if (this->head == node){
      this->head = node->next;
   }else{
      Node *current = new Node(nullptr, nullptr, nullptr);
      current = this->head;
      while (current->next != node){
         current = current->next;
      }
      current->setNext(node->next);
   }
}
