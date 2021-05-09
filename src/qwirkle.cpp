#include "Player.h"
#include "Board.h"

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
bool isValidInstruction(std::string inputInstruction, Player *player);

int main(void)
{
	std::string player1_name = "A";
	Player *player1 = new Player(player1_name);

	// initialise tile bag which contains shuffled tiles
	LinkedList *tileBag = new LinkedList();
	tileBag->iniTileBag();

	std::cout << "!!!" << std::endl;
	// initialise tiles in players' hands
	player1->initialiseTilesInHand(tileBag);
	std::cout << player1->displayTilesInHand() << std::endl;

	//qwirkle();
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

	// game round
	// initialise players
	Player *player1 = new Player(player1_name);
	Player *player2 = new Player(player2_name);

	// initialise board
	Board *board = new Board();
	//board->printBoard();

	// initialise tile bag which contains shuffled tiles
	LinkedList *tileBag = new LinkedList();
	tileBag->iniTileBag();

	std::cout << "!!!" << std::endl;
	// initialise tiles in players' hands
	player1->initialiseTilesInHand(tileBag);
	player2->initialiseTilesInHand(tileBag);

	// palyer one place one tile
	std::cout << player1_name << "it's your turn" << std::endl;
	std::cout << "Score for" << player1_name << ": ";
	std::cout << player1->getScore() << std::endl;

	std::cout << "Score for" << player2_name << ": ";
	std::cout << player2->getScore() << std::endl;

	board->printBoard();

	// display tiles in hand
	std::cout << "Your hand is" << std::endl;
	for (unsigned int counter = 0; counter < player1->displayTilesInHand().size(); counter++)
	{
		if (counter % 2 == 1)
		{
			std::cout << player1->displayTilesInHand()[counter];
			std::cout << " " ;
		}else{
			std::cout << player1->displayTilesInHand()[counter];
		}
	}
	std::cout << std::endl;

	std::string placeInstructure;

	std::cin >> placeInstructure;
	// if the input is valid, put the tile on the board
	// otherwise, show better valid input and ask for input again (not done)
	if (!isValidInstruction(placeInstructure, player1))
	{
		std::cout << "Invalid Input" << std::endl;
		return;
	}
	else
	{
		// put the tile on the board
		Colour colour = placeInstructure[6];
		Shape shape = (int)placeInstructure[7];
		player1->playOneTile(colour, shape);

		int row = -1;
		int col = -1;
		if (placeInstructure.size() == 14)
		{
			row = (int)placeInstructure[13];
		}
		else if (placeInstructure.size() == 15)
		{
			row = (int)placeInstructure[13] * 10 + (int)placeInstructure[14];
		}
		col = (int)placeInstructure[12];

		board->putTile2Board(colour, shape, row, col);

		// increase the score
		player1->increaseScore(1);
	}

	// palyer two place one tile
	std::cout << player2_name << "it's your turn" << std::endl;
	std::cout << "Score for" << player1_name << ": " << player1->getScore() << std::endl;
	std::cout << "Score for" << player2_name << ": " << player2->getScore() << std::endl;

	board->printBoard();

	std::cout << "Your hand is" << std::endl;
	player2->displayTilesInHand();

	std::cin >> placeInstructure;
	// if the input is valid, put the tile on the board
	// otherwise, show better valid input and ask for input again (not done)
	if (!isValidInstruction(placeInstructure, player2))
	{
		std::cout << "Invalid Input" << std::endl;
		return;
	}
	else
	{
		// put the tile on the board
		Colour colour = placeInstructure[6];
		Shape shape = (int)placeInstructure[7];
		player1->playOneTile(colour, shape);

		int row = -1;
		int col = -1;
		if (placeInstructure.size() == 14)
		{
			row = (int)placeInstructure[13];
		}
		else if (placeInstructure.size() == 15)
		{
			row = (int)placeInstructure[13] * 10 + (int)placeInstructure[14];
		}
		col = (int)placeInstructure[12];

		board->putTile2Board(colour, shape, row, col);

		// increase the score
		player2->increaseScore(2);
	}
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

bool isValidInstruction(std::string inputInstruction, Player *player)
{
	bool validFlag = false;

	// check the length of the input string
	if (inputInstruction.size() == 14 || inputInstruction.size() == 15)
	{
		validFlag = true;
	}
	else
	{
		validFlag = false;
	}

	// check the structure of the instruction
	if (inputInstruction.compare(0, 5, "place ") && inputInstruction.compare(8, 4, " at "))
	{
		validFlag = true;
	}
	else
	{
		validFlag = false;
	}

	// check if the player has the tile
	std::string tilesString = player->displayTilesInHand();
	for (int pos = 0; pos < tilesString.size(); pos += 2)
	{
		if (inputInstruction.compare(6, 2, tilesString.substr(pos, 2)))
		{
			validFlag = true;
		}
		else
		{
			validFlag = false;
		}
	}

	// check the position that is in the board area
	// check the col
	if ((int)inputInstruction[12] - ASCII_DIFFERENCE <= BOARD_SIZE && (int)inputInstruction[12] - ASCII_DIFFERENCE >= COL_NUMBER_OF_A)
	{
		validFlag = true;
	}
	else
	{
		validFlag = false;
	}

	// check the row
	int tempRow = -1;
	if (inputInstruction.size() == 14)
	{
		tempRow = (int)inputInstruction[13];
		if (tempRow >= 0 && tempRow < 10)
		{
			validFlag = true;
		}
		else
		{
			validFlag = false;
		}
	}
	else if (inputInstruction.size() == 15)
	{
		tempRow = (int)inputInstruction[13] * 10 + (int)inputInstruction[14];
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
