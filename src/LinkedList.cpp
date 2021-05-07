#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
   this->head = nullptr;
}

LinkedList::~LinkedList(){
   delete head;
}

LinkedList::LinkedList(LinkedList &other){
   //clean out our own house first, get rid of junk
   delete this->head;

   //copy
   this->head = other.head;
}

// get the length of the list
int LinkedList::getSize(){
   int size = 0;
   if (this->head == nullptr){
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
void LinkedList::addNodeFrom1st(Node *node){
   node->setNext(this->head);
   this->head = node;
}

// add node to the middle of the list
// nodes after the adding position should add 1
void LinkedList::addNode(Node *node){

}

// add node to the end of the list, only add the size of the list
void LinkedList::addNodeToEnd(Node *node){
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
 // remove node from the front of the list
void LinkedList::remove1stNode(){
   Node *currentNode = this->head->next;
   this->head = currentNode->next;
   this->head->setPrev(nullptr);
}

void LinkedList::removeNode(Node *node){
   // remove node from the front of the list
   if (this->head == node){
      this->head = node->next;

   // remove node from the middle of the list or remove last node of the list
   }else{
      Node *current = new Node(nullptr, nullptr, nullptr);
      current = this->head;
      while (current->next != node){
         current = current->next;
      }
      current->setNext(node->next);
   }
}

// remove node from known position
void LinkedList::remove(int position){
    Node *currentNode = this->head;
    Node *temp = this->head;
    int count = 0;
    if(position >= 0 && position < this->getSize()){
      while(count < position){
         temp = currentNode;
         currentNode = currentNode->next;
         count++;
      }
      temp->next = currentNode->next;
      delete currentNode;
    }
}

//add a node at the front
void LinkedList::addTileTo1st(Tile* tile) {
	Node *add = new Node(tile, nullptr, nullptr);
	add->next = head;
	this->head->setNext(add);
}

//add a node at the back - fixed
void LinkedList::addTileToEnd(Tile* tile) {
	Node *add = new Node(tile, nullptr, nullptr);
	Node *currentNode = this->head;
	if (currentNode == nullptr){
		this->head = add;
	}
	else{
		while (currentNode->next != nullptr) {
		   currentNode = currentNode->next;
	   }
	   currentNode->setNext(add);
	}
}

//get a tile with a position
Tile* LinkedList::getTile(int position){
	if(position >= 0 && position < this->getSize()){
		int count = 0;
		Node* currentNode = this->head;
		while (count < position){
			currentNode = currentNode->next;
			count++;
		}
		return currentNode->getTile();
	}
	else return nullptr;
}

//return a tile on top of a list
Tile* LinkedList::getFirstTile(){
	if(this->head != nullptr){
      return this->head->getTile();
   }
	else {
      return nullptr;
   }
}

// get first node
Node* LinkedList::getHeadNode(){
   return this->head;
}