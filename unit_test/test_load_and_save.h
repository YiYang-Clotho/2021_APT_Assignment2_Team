#ifndef __TEST_LOAD_AND_SAVE_H__
#define __TEST_LOAD_AND_SAVE_H__
#include "../src/save_load_Game.h"
class TestLoadAndSave{

public:
    TestLoadAndSave(){
        testSaveFile();
    }
    void testSaveFile(){
        std::string savePath="";
		Player *player1=new Player();
        Player *player2=new Player();
        Player *currentPlayer=player1;
        LinkedList *tileBag= new LinkedList();
        Board *board = new Board();
    }

};




#endif



