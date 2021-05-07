#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include "LinkedList.h"
#include <string>
using namespace std;


class Player{
public:
    Player(string name, int score, LinkedList *tilesInHand);

    string getName();
    void setName(string name);

    int getScore();
    void setScore(int score);

    LinkedList getTilesInHand();
    void setTilesInHand(LinkedList *tilesInHand);

    // 玩家出牌 put one tile on the board

    // 替换tile，把tilesInHand中的一个，从tile bag里替换, 替换了之后这个回合不出牌

    

private:
    // The Tiles in curent player hand
    LinkedList tiles;
    // Player's name 
    std::string name;
    // Player's score
    int score;
};


#endif