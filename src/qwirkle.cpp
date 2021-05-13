#include "game_flow.h"

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
			std::cout << "Enter the filename from which load a game" << std::endl;
			std::cin >> fileName;
			loadGame(fileName);
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
