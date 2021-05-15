#include "game_flow.h"
using std::cout;
using std::endl;
#define EXIT_SUCCESS 0

int main(void)
{
	qwirkle();
	int selection = getSelectionFromMenu();
	if (!std::cin.eof())
	{
		if (selection == 1)
		{
			newGame();
		}
		else if (selection == 2)
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
				Player *currentPlayer = new Player(); 
				Player *player1 = new Player();
				Player *player2 = new Player();
				LinkedList *tileBag = new LinkedList();
				Board *board = new Board();
				file->loadGameInfo(fileName, currentPlayer, player1, 
											player2, tileBag, board);

				std::cout << "current player: " << currentPlayer->getName() << std::endl;
				std::cout << "player1: " << player1->getName() << std::endl;
				std::cout << "player2: " << player2->getName() << std::endl;
				std::cout << "tile bag size: " << tileBag->getSize() << std::endl;

				continueGame(currentPlayer, player1, player2, tileBag, board);
			}
		}
		else if (selection == 3)
		{
			credits();
		}
		else if (selection == 4)
		{
			std::cout << "Goodbye" << std::endl;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
		}
	}
	else
	{
		std::cout << "Goodbye" << std::endl;
	}

	return EXIT_SUCCESS;
}
