#include "game_flow.h"
#include "GameFile.h"

#include <iostream>
#include <fstream>
#include <istream>
using std::cout;
using std::endl;
#define EXIT_SUCCESS 0

int main(void)
{
	qwirkle();
	bool checkMenu = false;
	GameFile* game = new GameFile();
	do
	{
	game->getSelectionFromMenu();
	std::string selection = game->checkEOF();
	if (selection == "1")
		{
			newGame();
			checkMenu = true;
		}
	else if (selection == "2")
		{
			std::string fileName;
			cout << "Enter the filename from which load a game" << endl;
			std::cin >> fileName;
			GameFile *file = new GameFile();
			file->loadGame(fileName);
			checkMenu = true;
		}
	else if (selection == "3")
		{
			credits();
			checkMenu = true;
		}
	else if (selection == "4")
		{
			game->quit();
			checkMenu = true;
		}
	else
		{
			std::cout << "Invalid input" << std::endl;
		}
	
	
	} while (checkMenu == true);

	return EXIT_SUCCESS;
}
