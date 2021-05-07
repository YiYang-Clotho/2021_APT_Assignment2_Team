#include "LinkedList.h"

#include <iostream>
#include <string>
using namespace std;

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();

   qwirkle();
   int selection = getSelectionFromMenu();
   if(selection == 1){
      newGame();
   }else if(selection == 2){
      string fileName;
      std::cout << "Enter the filename from which load a game" << std::endl;
      std::cin >> fileName;

      loadGame(fileName);
   }else if(selection == 3){
      credits();
   }else if(selection == 4){
      std::cout << "Goodbye" << std::endl;
   }
   
   delete list;


   return EXIT_SUCCESS;
}

void qwirkle(){
   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;
}

int getSelectionFromMenu(){
   std::cout << "Menu" << std::endl;
   std::cout << "----" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Credits (Show student information)" << std::endl;
   std::cout << "4. Quit" << std::endl;
   
   int input;
   std::cin >> input;
   return input;
}

void newGame(){
   std::cout << "Starting a New Game" << std::endl;
   string playerName1;
   string playerName2;
   std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
   std::cin >> playerName1;
   std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
   std::cin >> playerName2;

   std::cout << "Let's Play" << std::endl;

   // Need finalise
}

void loadGame(string fileName){
   
}

void credits(){
   // print players informations
}


