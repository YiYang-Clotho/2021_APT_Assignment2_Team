#include "game_flow.h"
using std::cout;
using std::endl;
#define EXIT_SUCCESS 0

int main(void)
{
	qwirkle();
	bool checkMenu = false;
	do
	{
	int selection = getSelectionFromMenu();
	if (!std::cin.eof())
	{
		if (selection == 1)
		{
			newGame();
			checkMenu = true;
		}
		else if (selection == 2)
		{
			std::string fileName;
			cout << "Enter the filename from which load a game" << endl;
			std::cin >> fileName;
			loadGame(fileName);
			checkMenu = true;
		}
		else if (selection == 3)
		{
			credits();
			checkMenu = true;
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
	} while (checkMenu == true);
	
	

	return EXIT_SUCCESS;
}
