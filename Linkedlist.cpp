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

//check size of the linkedlist
int LinkedList::size() {
	int size = 0;
	Node* node = head;
	while (node != nullptr) {
		++size;
		node = node->next;
	}
	return size;
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

//add a node at the front
void LinkedList::addFront(Tile* tile) {
	Node *add = new Node(tile, nullptr);
	add->next = head;
	head = add;
}

//add a node at the back - fixed
void LinkedList::addBack(Tile* tile) {
	Node *add = new Node(tile, nullptr);
	Node *node = head;
	if (node==nullptr){
		head=add;
	}
	else{
		while (node->next != nullptr) {
		node = node->next;
	}
	node->next = add;
	}
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

//return a tile on top of a list
Tile* LinkedList::getFront(){
	if(head!=nullptr){
      return head->tile;
   }
	else {
      return nullptr;
   }
}

//get a tile with a position i
Tile* LinkedList::getTile(int i){
	if(i>=0 && i<this->size()){
		int count = 0;
		Node* node = head;
		while (count<i){
			node = node->next;
			count++;
		}
		return node->tile;
	}
	else return nullptr;
}

//delete at the front of the linkedlist
void LinkedList::deleteFront() {
	Node *temp = head->next;
	delete head;
	head = temp;
}

//delete a tile with position i
void LinkedList::deleteTile(int i){
    Node *node = head;
    Node *temp = head;
    int count =0;
    if(i>=0 && i<this->size()){
        while(count<i){
        temp = node;
        node = node->next;
        count++;
    }
    temp->next = node->next;
    delete node;
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
