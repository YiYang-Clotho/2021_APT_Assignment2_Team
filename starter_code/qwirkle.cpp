#include "LinkedList.h"
#include "Player.h"

#include <iostream>
#include <string>

#define EXIT_SUCCESS 0

void qwirkle();
int getSelectionFromMenu();
void newGame();
void loadGame(std::string fileName);
void credits();
bool checkValidPlayerName(std::string playerName);
bool isFileExist(std::string fileName);
bool checkValidInstruction(std::string inputInstruction);

int main(void)
{
	LinkedList *list = new LinkedList();

	qwirkle();
	int selection = getSelectionFromMenu();
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

	delete list;

	std::cout << "TODO: Implement Qwirkle!" << std::endl;

	return EXIT_SUCCESS;
}

void qwirkle()
{
	std::cout << "Welcome to Qwirkle!" << std::endl;
	std::cout << "-------------------" << std::endl;
}

int getSelectionFromMenu()
{
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

/*
* =================== Menu Method ==================
*/
void newGame()
{
	std::string player1_name, player2_name;
	std::cout << "Starting a New Game\n"
			  << std::endl;

	std::cout << "Enter a name for player 1(uppercase characters only)\n> ";
	std::cin >> player1_name;

	if (!checkValidPlayerName(player1_name))
	{
		std::cerr << "Invalid Input" << std::endl;
		return;
	}
	std::cout << "Enter a name for player 2(uppercase characters only)\n> ";
	std::cin >> player2_name;
	if (!checkValidPlayerName(player2_name))
	{
		std::cout << "Invalid Input" << std::endl;
		return;
	}
	std::cout << "Let's Play!" << std::endl;
	//start_game(player1_name, player2_name);
}

void loadGame(std::string fileName)
{
	std::cout << "Enter the filename from which load a game\n< ";
	std::cin >> fileName;
	if (!isFileExist(fileName))
	{
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

void credits()
{

	std::cout << "---------------------------------- " << std::endl;
	// print group members' information
	std::cout << "---------------------------------- " << std::endl;
}

bool checkValidPlayerName(std::string playerName)
{
	return true;
}

bool isFileExist(std::string fileName)
{
	return true;
}

bool checkValidInstruction(std::string inputInstruction)
{
	bool validFlag = false;
	std::string name1;
	Player *currentPlayer = new Player(name1);

	// check the length of the input string
	if (inputInstruction.size() == 5 || inputInstruction.size() == 6)
	{
		validFlag = true;
	}
	else
	{
		validFlag = false;
	}

	// check first 2 elements of the input string
	// check if the player has the tile
	Colour tempColour;
	Shape tempShape;
	std::string tilesString = currentPlayer->displayTilesInHand();
	for (int pos = 0; pos < tilesString.size(); pos += 2)
	{
		if (inputInstruction.compare(1, 2, tilesString.substr(pos, 2)))
		{
			tempColour = inputInstruction[0];
			tempShape = (int)inputInstruction[1];
			validFlag = true;
		}
		else
		{
			validFlag = false;
		}
	}

	// check the @
	if (inputInstruction[2] != '@')
	{
		validFlag = false;
	}
	else
	{
		validFlag = true;
	}

	// check the position that is in the board area
	// check the col
	int tempCol = -1;
	if ((int)inputInstruction[3] - ASCII_DIFFERENCE <= BOARD_COL && (int)inputInstruction[3] - ASCII_DIFFERENCE >= COL_NUMBER_OF_A)
	{
		tempCol = (int)inputInstruction[3] - ASCII_DIFFERENCE;
		validFlag = true;
	}
	else
	{
		validFlag = false;
	}

	// check the row
	int tempRow = -1;
	if (inputInstruction.size() == 5)
	{
		tempRow = (int)inputInstruction[4];
		if (tempRow >= 0 && tempRow < 10)
		{
			validFlag = true;
		}
		else
		{
			validFlag = false;
		}
	}
	else if (inputInstruction.size() == 6)
	{
		tempRow = (int)inputInstruction[4] * 10 + (int)inputInstruction[5];
		if (tempRow >= 10 && tempRow < BOARD_SIZE)
		{
			validFlag = true;
		}
		else
		{
			validFlag = false;
		}
	}

	if (validFlag == false)
	{
		std::cout << "Invalid Input" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}
