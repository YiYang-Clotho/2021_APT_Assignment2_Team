#ifndef ASSIGN2_BASEGAME_H
#define ASSIGN2_BASEGAME_H

#include <iostream>
#include "Tile.h"
#include "LinkedList.h"
#include "Rules.h"
#include "GameFile.h"

void qwirkle();
void newGame();

// continue game from loaded game
void continueGame(Player **currentPlayer, Player *player1, 
    Player *player2, LinkedList *tileBag, Board *board);

// display score
void scores(Player *player1, Player *player2);

// after checking the instruction, check if it's able to place the tile
bool checkRule(Player *currentPlayer, Board *board,
               LinkedList *tileBag, std::string instructure);

// place the tile and increase the score
void placeTile(Player *currentPlayer, Board *board,
    LinkedList *tileBag, std::string instructure);

// show students' info
void credits();

// check winner
void checkEnd(LinkedList *tileBag, Player *player1, Player *player2);

// game round
void game(Player *currentPlayer, Player *player1, Player *player2,
          Board *board, LinkedList *tileBag, 
          std::string instructure, int inputCount);

#endif
