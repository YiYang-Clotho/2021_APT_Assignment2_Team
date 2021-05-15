#include "game_flow.h"
using std::cout;
using std::endl;
#define EXIT_SUCCESS 0
void displayMenu();

int main(void)
{
	qwirkle();
	displayMenu();
	bool checkMenu = false;
	GameFile *game = new GameFile();
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
			if (!file->loadGame(fileName))
			{
				std::cout << "Qwirkle game loaded failed" << std::endl;
			}
			else
			{
				std::cout << "Qwirkle game successfully loaded" << std::endl;
				Player *tempPlayer = new Player(), *player1 = new Player(),
					   *player2 = new Player(), **currentPlayer = &tempPlayer;
				LinkedList *tileBag = new LinkedList();
				Board *board = new Board();
				file->loadGameInfo(fileName, currentPlayer, player1,
								   player2, tileBag, board);

				continueGame(currentPlayer, player1, player2, tileBag, board);
			}
			checkMenu = true;
		}
		else if (selection == "3")
		{
			credits();
			displayMenu();
			checkMenu = true;
		}
		else if (selection == "4")
		{
			std::cout << std::endl;
			std::cout << "Goodbye" << std::endl;
			exit(0);
			checkMenu = true;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
		}

	} while (checkMenu == true);

	return EXIT_SUCCESS;
}

void displayMenu()
{
	std::cout << "Menu" << std::endl;
	std::cout << "----" << std::endl;
	std::cout << "1. New Game" << std::endl;
	std::cout << "2. Load Game" << std::endl;
	std::cout << "3. Credits (Show student information)" << std::endl;
	std::cout << "4. Quit" << std::endl;
}