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

   std::cout << "TODO: Implement Qwirkle!" << std::endl;

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

/*
* =================== Menu Method ==================
*/
void newGame() {
	std::string player1_name, player2_name;
	std::cout << "Starting a New Game\n" << std::endl;

	std::cout << "Enter a name for player 1(uppercase characters only)\n> ";
	std::cin >> player1_name;

	if (!checkUpper(player1_name)) {
		std::cerr << "Invalid Input" << std::endl;
		return;
	}
	std::cout << "Enter a name for player 2(uppercase characters only)\n> ";
	std::cin >> player2_name;
	if (!checkUpper(player2_name)) {
		std::cout << "Invalid Input" << std::endl;
		return;
	}
	std::cout <<"Let's Play!"<<std::endl;
	//start_game(player1_name, player2_name);
}

void loadGame() {
	std::cout << "Enter the filename from which load a game\n< ";
	std::string fileName = "";
	std::cin >> fileName;
	if (!isFileExist(fileName)) {
		std::cerr << "Invalid File" << std::endl;
		return;
	}
	//if (!isFileFormatCorrect(fileName)) {
	//	std::cerr << "Invalid File Format" << std::endl;
	//	return;
	//}
	std::cout << "Qwirkle game successfully loaded" << std::endl;
	//continue_game(fileName);
}

void credit(std::string full_name, std::string student_number, std::string email) {
	std::cout << "Name:  "<< full_name << std::endl;
	std::cout << "Student ID:  " << student_number << std::endl;
	std::cout << "Email:  " << email << std::endl;
}
void credits() {
	
	std::cout << "---------------------------------- " << std::endl;
	credit("Test1", "123", "test1@qq.com");
	credit("Test2", "321", "test2@qq.com");
	std::cout << "<Student 2,etc.> " << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	mainMenu();
}


void mainMenu() {
	// Display the menu user prompt
	std::cout << "Menu" << std::endl;
	std::cout << "--------" << std::endl;
	std::cout << "1. New Game" << std::endl;
	std::cout << "2. Load Game" << std::endl;
	std::cout << "3. Credits (Show student information)" << std::endl;
	std::cout << "4. Quit" << std::endl;
	std::cout << "> " ;
	// Get user option and dispatch
	int option = -1;
	std::cin >> option;
	if (option < 1 || option>4) {
		std::cout << "Invalid Input" << std::endl;
	} else {
		switch (option) {
		case 1:
			newGame();
			break;
		case 2:
			loadGame();
			break;
		case 3:
			credits();
			break;
		case 4:
			std::cout << "Goodbye" << std::endl;
		}
	}
}

void main() {
	mainMenu();
}


