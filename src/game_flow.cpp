#include "game_flow.h"
#include "check_input.h"

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

void newGame()
{
	std::string player1_name, player2_name;
	std::cout << "Starting a New Game\n"
			  << std::endl;

	std::cout << "Enter a name for player 1(uppercase characters only)\n> ";
	std::cin >> player1_name;

	if (!isValidPlayerName(player1_name))
	{
		std::cerr << "Invalid Input" << std::endl;
		return;
	}
	std::cout << "Enter a name for player 2(uppercase characters only)\n> ";
	std::cin >> player2_name;
	if (!isValidPlayerName(player2_name))
	{
		std::cout << "Invalid Input" << std::endl;
		return;
	}
	std::cout << "Let's Play!" << std::endl;

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
    Player *currentPlayer = new Player();
	while (tileBag->getSize() > 0 
		&& ( player1->getTilesInHand()->getSize() > 0 
		|| player2->getTilesInHand()->getSize() > 0 ))
	{
        int inputCount = 0;
		if (tileBag->getSize() > 0)
		{
			for (unsigned int turn = 0; turn < ROUND_NUM; turn++)
			{
				if (playerFlag == 1)
				{
                    currentPlayer = player1;
                    game(currentPlayer, player1, player2, board, tileBag,
                                            instructure, tilesBagCounter, 
                                        p1Counter, p2Counter, inputCount);
                    
                    inputCount = 1;
                    playerFlag = 2;     
				}
				if (playerFlag == 2)
				{
                    currentPlayer = player2;
                    game(currentPlayer, player1, player2, board, tileBag,
                                            instructure, tilesBagCounter, 
                                        p1Counter, p2Counter, inputCount);
                    playerFlag = 1;    
				}
			}
		}
		else
		{
			for (unsigned emptyBagCounter = 0;
				 emptyBagCounter < EMPTY_TILE_BAG_ROUND_NUM; 
                                            emptyBagCounter++)
			{
				for (unsigned int turn = 0; turn < TILES_IN_HAND_NUM; turn++)
				{
					if (playerFlag == 1)
					{
                        currentPlayer = player1;
                        
                        game(currentPlayer, player1, player2, board, tileBag,
                                            instructure, tilesBagCounter, 
                                        p1Counter, p2Counter, inputCount);
                        playerFlag = 2;
						
					}
					if (playerFlag == 2)
					{
                        currentPlayer = player2;
                        
                        game(currentPlayer, player1, player2, board, tileBag,
                                            instructure, tilesBagCounter, 
                                        p1Counter, p2Counter, inputCount);
                        playerFlag = 1;
					}
                
				}
			}
		}
	}
    
    
    checkEnd(tileBag, player1, player2);
}

void continueGame(Player *currentPlayer, 
		Player *player1, Player *player2, LinkedList *tileBag, Board *board)
{
    
}

void credits()
{
	std::cout << "---------------------------------- " << std::endl;
	// print group members' information
    std::cout << "Name: Yi Yang" << std::endl;
    std::cout << "Student ID: s3798354" << std::endl;
    std::cout << "Email: s3798354@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;

    std::cout << "Name: Jinghua Gu" << std::endl;
    std::cout << "Student ID: s3653714" << std::endl;
    std::cout << "Email: s3653714@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;

    std::cout << "Name: Yixin Chen" << std::endl;
    std::cout << "Student ID: s3855866" << std::endl;
    std::cout << "Email: s3855866@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;

    std::cout << "Name: Sifan Gao" << std::endl;
    std::cout << "Student ID: s3753605" << std::endl;
    std::cout << "Email: s3753605@student.rmit.edu.au" << std::endl;

	std::cout << "---------------------------------- " << std::endl;
}


void checkEnd(LinkedList *tileBag, Player *player1, Player *player2) {
    int tilesInBag = tileBag->getSize();
    int p1Tiles = player1->getTilesInHand()->getSize();
    int p2Tiles = player2->getTilesInHand()->getSize();
    if (tilesInBag == 0 && p1Tiles == 0 && p2Tiles == 0) {
        std::cout << "Game over" << std::endl;
        std::cout << "Score for " << player1->getName() << ": ";
        std::cout << player1->getScore() << std::endl;
        std::cout << "Score for " << player2->getName() << ": ";
        std::cout << player2->getScore() << std::endl;
        if (player1->getScore() > player2->getScore()) {
            std::cout << "Player " << player1->getName() << "won!";
            std::cout << std::endl;
        } else {
            std::cout << "Player " << player2->getName() << "won!";
            std::cout << std::endl;
        }
        std::cout << "\nGoodbye" << std::endl;
        exit(0);
    }
}


void scores(Player *player1, Player *player2)
{
    std::cout << "Score for " << player1->getName() << ": ";
    std::cout << player1->getScore() << std::endl;

    std::cout << "Score for " << player2->getName() << ": ";
    std::cout << player2->getScore() << std::endl;
}

void placeTile(Player *currentPlayer, Board *board, 
            LinkedList *tileBag, std::string instructure)
{   
    int turn = 0;
    if (tileBag->getSize() < 60 )
    {
        turn = 1;
    }
    
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

    Rules *rule = new Rules();
    bool check = rule->boardRules(row, col, board, 
                colour, shape, turn);
    int earnedScore = 0; 
    if (check == true)
    {
        board->putTile2Board(colour, shape, row, col);
        earnedScore = rule->scoreRules(row, col, board, turn);
    }
    else
    {
        std::cout << "Cannot place the tile in this place!" << std::endl;
    }

    currentPlayer->playOneTile(colour, shape);
    currentPlayer->getNewTile(tileBag);

    // increase the score
    currentPlayer->increaseScore(earnedScore);
}

void game(Player *currentPlayer, Player *player1, Player *player2, 
            Board *board, LinkedList *tileBag, std::string instructure, 
            int tilesBagCounter, int p1Counter, int p2Counter, int inputCount)
{
    // turn
    std::cout << std::endl;
    std::cout << currentPlayer->getName();
    std::cout << " it's your turn" << std::endl;

    // print
    scores(player1, player2);
    board->printBoard();
    std::cout << "Your hand is" << std::endl;
    currentPlayer->printTilesInHand();

    // input
    if (inputCount == 0)
    {
        std::cin.ignore();  
        inputCount = 1;
        
    }
    instructure.clear();
              
    std::getline(std::cin, instructure);

    // check instruction and do
    int toDo = checkInstruction(instructure, currentPlayer);
    if (toDo == 1)
    {
        placeTile(currentPlayer, board, tileBag, instructure);
        if (tilesBagCounter != 0)
        {
            tilesBagCounter--;
        }
        else
        {
            if (currentPlayer->getName().compare(player1->getName()) == 1)
            {
                p1Counter--;
            }
            else
            {
                p2Counter--;
            }
        }
    }
    else if (toDo == 2)
    {
        Colour colour = instructure[8];
        Shape shape = instructure[9] - '0';
        currentPlayer->replaceOneTile(colour, shape, tileBag);
    }
    else if (toDo == 3)
    {
        std::string fileName = instructure.substr(5, 
                                    instructure.size() - 5);
        GameFile *file = new GameFile();
        file->saveGame(fileName, currentPlayer, 
                            player1, player2, tileBag, board);
        // quit
    }

}

//=============Helper Method======================

/*
*  split string to vector based on sep
*/
std::vector<std::string> split(std::string input, std::string delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        tokens.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    tokens.push_back(input);
    return tokens;
}

Tile tokenToTile(std::string token) {
    Tile tile;
    tile.colour = token[0];
    tile.shape = token[1] - '0';
    return tile;
}