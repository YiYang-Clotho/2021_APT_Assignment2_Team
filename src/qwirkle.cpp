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
			
			GameFile *file = new GameFile();
			do
			{
				std::getline(std::cin, fileName);
				
				if (std::cin.eof())
				{
					std::cout << std::endl;
					std::cout << "Goodbye" << std::endl;
					exit(0);
				}
				else if (!file->loadGame(fileName))
				{
					std::cout << std::endl;
					std::cout << "Qwirkle game loaded failed." << std::endl;
					std::cout << "Please try again." << std::endl;
				}
				
			} while (!file->loadGame(fileName));
			
			std::cout << std::endl;
			std::cout << "Qwirkle game successfully loaded" << std::endl;
			Player *tempPlayer = new Player(), *player1 = new Player(),
					*player2 = new Player(), **currentPlayer = &tempPlayer;
			LinkedList *tileBag = new LinkedList();
			Board *board = new Board();
			file->loadGameInfo(fileName, currentPlayer, player1,
								player2, tileBag, board);

			continueGame(currentPlayer, player1, player2, tileBag, board);
			
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
			std::cout << std::endl;
			std::cout << "Invalid input, please try again." << std::endl;
			checkMenu = true;
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