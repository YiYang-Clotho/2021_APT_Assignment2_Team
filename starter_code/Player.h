#ifndef __PLAYER__
#define __PLAYER__
#include "LinkedList.h"
#include <string>
// 
// player class：分配的牌的信息，current现在手上的牌的信息，information，名字，学号，分数

class Player{
public:

    Player(std::string name,int id_number) :name(name),id_number(id_number){
        score=0;
    }
private:
    // The Tiles in curent player hand
    LinkedList tiles;
    // Player's name 
    std::string name;
    // Player's student number
    int id_number;
    // Player's score
    int score;
};


#endif