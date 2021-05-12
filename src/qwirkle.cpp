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
	// int playerFlag = 1;
	// std::string name1 = "A";
	// std::string name2 = "B";
	// Player *p1 = new Player(name1);
	// Player *p2 = new Player(name2);
	// Player *tp = new Player();
	// int size = 10;
	// int Asize = 3;
	// int Bsize = 3;
	// int c = 5;
	// int c1 = 3;
	// while (size > 0 || Asize > 0 || Bsize > 0)
	// {
	// 	if (size > 0)
	// 	{
	// 		for (unsigned int turn = 0; turn < c; turn++)
	// 		{
	// 			if (playerFlag == 1)
	// 			{
	// 				tp = p1;
	// 				std::cout << "size: " << size << std::endl;
	// 				// player 1's turn
	// 				std::cout << tp->getName() << std::endl;
	// 				playerFlag = 2;
	// 				size--;
	// 				std::cout << "size: " << size << std::endl;
	// 			}
	// 			if (playerFlag == 2)
	// 			{
	// 				tp = p2;
	// 				std::cout << "size: " << size << std::endl;
	// 				// player 1's turn
	// 				std::cout << tp->getName() << std::endl;
	// 				playerFlag = 1;
	// 				size--;
	// 				std::cout << "size: " << size << std::endl;
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		for (unsigned int turn = 0; turn < c1; turn++)
	// 		{
	// 			if (playerFlag == 1)
	// 			{
	// 				tp = p1;
	// 				std::cout << "size: " << size << std::endl;
	// 				std::cout << "Asize: " << Asize << std::endl;
	// 				// player 1's turn
	// 				std::cout << tp->getName() << std::endl;
	// 				playerFlag = 2;
	// 				Asize--;
	// 				std::cout << "Asize: " << Asize << std::endl;
	// 			}
	// 			if (playerFlag == 2)
	// 			{
	// 				tp = p2;
	// 				std::cout << "size: " << size << std::endl;
	// 				std::cout << "Bsize: " << Bsize << std::endl;
	// 				// player 1's turn
	// 				std::cout << tp->getName() << std::endl;
	// 				playerFlag = 1;
	// 				Bsize--;
	// 				std::cout << "Bsize: " << Bsize << std::endl;
	// 			}
	// 		}
	// 	}
	// }

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

	// initialise tiles in players' hands
	player1->initialiseTilesInHand(tileBag);
	player2->initialiseTilesInHand(tileBag);

	int tilesBagCounter = ROUND_NUM * 2;
	int p1Counter = TILES_IN_HAND_NUM;
	int p2Counter = TILES_IN_HAND_NUM;
	int playerFlag = 1;
	std::string instructure;
	int inputCount = 0;
	while (tileBag->getSize() > 0 
		|| player1->getTilesInHand()->getSize() > 2 
		|| player2->getTilesInHand()->getSize() > 2)
	{
		if (tileBag->getSize() > 0)
		{
			for (unsigned int turn = 0; turn < ROUND_NUM; turn++)
			{
				if (playerFlag == 1)
				{
					// player 1's turn
					// palyer 1 place one tile
					std::cout << player1->getName();
					std::cout << " it's your turn" << std::endl;
					std::cout << "Score for " << player1_name << ": ";
					std::cout << player1->getScore() << std::endl;

					std::cout << "Score for " << player2_name << ": ";
					std::cout << player2->getScore() << std::endl;

					board->printBoard();

					// display tiles in hand
					std::cout << "Your hand is" << std::endl;
					player1->printTilesInHand();

					if (inputCount == 0)
					{
						std::cin.ignore();
						inputCount++;
					}

					instructure.clear();
					std::getline(std::cin, instructure);

					// if the input is valid, put the tile on the board
					// unvalid, show better valid input, input again
					if (isValidInstruction(instructure, player1) == false)
					{
						std::cout << "Invalid Input" << std::endl;
						std::getline(std::cin, instructure);
					}
					else
					{
						// put the tile on the board, update tiles in hand
						// update tile bag
						Colour colour = instructure[6];
						Shape shape = instructure[7] - '0';

						int row = -1;
						int col = -1;
						int digits = instructure[14] - '0';
						int tens = (instructure[13] - '0') * 10;
						if (instructure.size() == 14)
						{
							col = instructure[13] - '0';
						}
						else if (instructure.size() == 15)
						{
							col = tens + digits;
						}
						row = instructure[12] - '0' - ASCII_DIF;

						board->putTile2Board(colour, shape, row, col);

						player1->playOneTile(colour, shape);
						player1->getNewTile(tileBag);

						// increase the score
						player1->increaseScore(1);
					}

					playerFlag = 2;
					tilesBagCounter--;
				}
				if (playerFlag == 2)
				{
					// player 2's turn
					// palyer 2 place one tile
					std::cout << player2_name;
					std::cout << " it's your turn" << std::endl;
					std::cout << "Score for " << player1_name << ": ";
					std::cout << player1->getScore() << std::endl;

					std::cout << "Score for " << player2_name << ": ";
					std::cout << player2->getScore() << std::endl;

					board->printBoard();

					// display tiles in hand
					std::cout << "Your hand is" << std::endl;
					player2->printTilesInHand();

					instructure.clear();
					std::getline(std::cin, instructure);

					// if the input is valid, put the tile on the board
					// unvalid, show better valid input, input again
					if (isValidInstruction(instructure, player2) == false)
					{
						std::cout << "Invalid Input" << std::endl;
						std::getline(std::cin, instructure);
					}
					else
					{
						// put the tile on the board, update tiles in hand
						// update tile bag
						Colour colour = instructure[6];
						Shape shape = instructure[7] - '0';

						int row = -1;
						int col = -1;
						int digits = instructure[14] - '0';
						int tens = (instructure[13] - '0') * 10;
						if (instructure.size() == 14)
						{
							col = instructure[13] - '0';
						}
						else if (instructure.size() == 15)
						{
							col = tens + digits;
						}
						row = instructure[12] - '0' - ASCII_DIF;

						board->putTile2Board(colour, shape, row, col);

						player2->playOneTile(colour, shape);
						player2->getNewTile(tileBag);

						// increase the score
						player2->increaseScore(2);
					}
					playerFlag = 1;
					tilesBagCounter--;
				}
			}
		}
		else
		{
			for (unsigned emptyBagCounter = 0;
				 emptyBagCounter < EMPTY_TILE_BAG_ROUND_NUM; emptyBagCounter++)
			{
				for (unsigned int turn = 0; turn < TILES_IN_HAND_NUM; turn++)
				{
					if (playerFlag == 1)
					{
						// player 1's turn
						// palyer 1 place one tile
						std::cout << player1->getName();
						std::cout << " it's your turn" << std::endl;
						std::cout << "Score for " << player1_name << ": ";
						std::cout << player1->getScore() << std::endl;

						std::cout << "Score for " << player2_name << ": ";
						std::cout << player2->getScore() << std::endl;

						board->printBoard();

						// display tiles in hand
						std::cout << "Your hand is" << std::endl;
						player1->printTilesInHand();

						instructure.clear();
						std::getline(std::cin, instructure);

						// if the input is valid, put the tile on the board
						// unvalid, show better valid input, input again
						if (isValidInstruction(instructure, player1) == false)
						{
							std::cout << "Invalid Input" << std::endl;
							std::getline(std::cin, instructure);
						}
						else
						{
							// put the tile on the board, update tiles in hand
							// update tile bag
							Colour colour = instructure[6];
							Shape shape = instructure[7] - '0';

							int row = -1;
							int col = -1;
							int digits = instructure[14] - '0';
							int tens = (instructure[13] - '0') * 10;
							if (instructure.size() == 14)
							{
								col = instructure[13] - '0';
							}
							else if (instructure.size() == 15)
							{
								col = tens + digits;
							}
							row = instructure[12] - '0' - ASCII_DIF;

							board->putTile2Board(colour, shape, row, col);

							player1->playOneTile(colour, shape);
							player1->getNewTile(tileBag);

							// increase the score
							player1->increaseScore(1);
						}
						playerFlag = 2;
						p1Counter--;
					}
					if (playerFlag == 2)
					{
						// player 2's turn
						// palyer 2 place one tile
						std::cout << player2_name;
						std::cout << " it's your turn" << std::endl;
						std::cout << "Score for " << player1_name << ": ";
						std::cout << player1->getScore() << std::endl;

						std::cout << "Score for " << player2_name << ": ";
						std::cout << player2->getScore() << std::endl;

						board->printBoard();

						// display tiles in hand
						std::cout << "Your hand is" << std::endl;
						player2->printTilesInHand();

						instructure.clear();
						std::getline(std::cin, instructure);

					// if the input is valid, put the tile on the board
					// unvalid, show better valid input, input again
						if (isValidInstruction(instructure, player2) == false)
						{
							std::cout << "Invalid Input" << std::endl;
							std::getline(std::cin, instructure);
						}
						else
						{
							// put the tile on the board, update tiles in hand
							// update tile bag
							Colour colour = instructure[6];
							Shape shape = instructure[7] - '0';

							int row = -1;
							int col = -1;
							int digits = instructure[14] - '0';
							int tens = (instructure[13] - '0') * 10;
							if (instructure.size() == 14)
							{
								col = instructure[13] - '0';
							}
							else if (instructure.size() == 15)
							{
								col = tens + digits;
							}
							row = instructure[12] - '0' - ASCII_DIF;

							board->putTile2Board(colour, shape, row, col);

							player2->playOneTile(colour, shape);
							player2->getNewTile(tileBag);

							// increase the score
							player2->increaseScore(2);
						}
						playerFlag = 1;
						p2Counter--;
					}
				}
			}
		}
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
	if (inputInstruction.compare(0, 6, "place ") == 0 
		&& inputInstruction.compare(8, 4, " at ") == 0)
	{
		validFlag = true;
	}
	else
	{
		validFlag = false;
	}

	// check if the player has the tile
	std::string tilesString = player->getTilesString();
	for (unsigned int pos = 0; pos < tilesString.size() - 2; pos += 2)
	{
		if (inputInstruction.compare(6, 2, tilesString.substr(pos, 2)) == 0)
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
	int col = inputInstruction[12] - '0' - ASCII_DIF;
	if (col <= BOARD_SIZE && col >= 0)
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
		tempRow = inputInstruction[13] - '0';
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
		int tempTen = (inputInstruction[13] - '0') * 10;
		tempRow = tempTen + (inputInstruction[14] - '0');
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
