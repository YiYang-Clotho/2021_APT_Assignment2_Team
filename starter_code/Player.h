#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include "LinkedList.h"
#include <string>
using namespace std;


class Player{
public:
    Player(string name, int score, LinkedList *tiles);

private:
    // The Tiles in curent player hand
    LinkedList tiles;
    // Player's name 
    std::string name;
    // Player's score
    int score;
};


#endif