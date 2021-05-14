#include "GameFile.h"

// Save Game data to file 
bool GameFile::saveGame(std::string savePath, Player * currentPlayer, Player * player1, Player * player2, LinkedList * tileBag, Board * board)
{
	bool flag = false;
	std::ofstream file(savePath, std::ios_base::out);

	// Save Player 1
	file << player1->getName() << std::endl;
	file << player1->getScore() << std::endl;
	std::string tiles = player1->getTilesString();
	for (unsigned int count = 0; count < tiles.size(); count++)
	{
		if (count % 2 == 1 && count < 11)
		{
			file << tiles[count];
			file << ",";
		}
		else
		{
			file << tiles[count];
		}
	}
	file << std::endl;

	// Save Player 2
	file << player2->getName() << std::endl;
	file << player2->getScore() << std::endl;
	tiles = player2->getTilesString();
	for (unsigned int count = 0; count < tiles.size(); count++)
	{
		if (count % 2 == 1 && count < 11)
		{
			file << tiles[count];
			file << ",";
		}
		else
		{
			file << tiles[count];
		}
	}
	file << std::endl;

	// Save Board
	// board size
	int rowSize = board->position.size();
	int colSize = board->position[0].size();
	file << rowSize << "," << colSize << std::endl;

	//search the board and print the filled tiles
	int counter = 0;
	int tilesA = player1->getTilesInHand()->getSize();
	int tilesB = player2->getTilesInHand()->getSize();
	int tilesInBag = tileBag->getSize();
	int tilesOnBoardNum = TOTAL_TILES_NUM - tilesInBag - tilesA - tilesB;
	for (unsigned int row = 0; row < board->position.size(); row++)
	{
		for (unsigned int col = 0;
		col < board->position[row].size(); col++)
		{
			if (board->position[row][col]->tile != nullptr)
			{
				/*Colour colour = board->position[row][col]->tile->colour;
				Shape shape = board->position[row][col]->tile->shape + '0';*/
				file << board->position[row][col]->tile->colour << board->position[row][col]->tile->shape << '@';
				char outCol = col + ASCII_A;
				file << outCol << row;
				//if (row >= 10)
				//{
				//	char tens = (row / 10) + '0';
				//	char digits = (row % 10) + '0';
				//	file << tens << digits;
				//}
				//else
				//{
				//	char outRow = row + '0';
				//	file << tens << digits;

				//}
				counter++;

				if (counter != tilesOnBoardNum)
				{
					file << ", ";
				}
			}
		}
	}
	file << std::endl;

	// Save TileBag
	for (int count = 1; count < tileBag->getSize(); count++)
	{
		Tile *tmpTile = tileBag->getTile(count);
		Colour colour = tmpTile->colour;
		Shape shape = tmpTile->shape;
		file << colour << shape;
		if (count < tileBag->getSize() - 1)
		{
			file << ',';
		}
		else {
			file << std::endl;
		}
	}

	// current player
	file << currentPlayer->getName() << std::endl;
	file.close();
	flag = true;

	if (flag == true)
	{
		return true;
		std::cout << "Game successfully saved" << std::endl;
	}
	else
	{
		return false;
		std::cout << "Save game failed" << std::endl;
	}

}

// Load history Game data from file ,
bool GameFile::loadGame(std::string loadPath, Player **currentPlayer, Player **player1, Player **player2, LinkedList **tileBag, Board **board)
{
	bool flag = false;
	std::ifstream inStream(loadPath, std::ios_base::in);
	if (!inStream.is_open())
	{
		std::cout << "Game file open fails!" << std::endl;
	}

	// Read player 1
	*player1 = new Player();
	loadPlayerFromStream(*player1, inStream);
	// Read player 2
	*player2 = new Player();
	loadPlayerFromStream(*player2, inStream);

	//Load board
	{
		// FIXME
		*board = new Board();
		std::string shapeStr;
		while (shapeStr == "")
		{
			getline(inStream, shapeStr);
		}

		std::string tilesStr;
		while (tilesStr == "")
		{
			getline(inStream, tilesStr);
		}
		vector<std::string> vecTiles = split(tilesStr, ',');
		for (int i = 0; i < vecTiles.size(); i++)
		{
			char colour = vecTiles[i][0];
			int atPos = (vecTiles[i]).find('@');
			int shape =std::stoi( vecTiles[i].substr(1,atPos-1));
			int row = vecTiles[i][atPos+1] - 'A';
			int col = std::stoi(vecTiles[i].substr(atPos+2, vecTiles[i].size()));
			(*board)->putTile2Board(colour,shape,row,col);
			//*player1->addTile(tmp);
		}
	}

	//Load tileBag
	*tileBag = new LinkedList();
	std::string strTiles;
	while (strTiles == "")
	{
		getline(inStream, strTiles);
	}	
	vector<std::string> vecTiles = split(strTiles, ',');
	for (unsigned int count = 0; count < vecTiles.size(); count++)
	{
		Node *tmpNode = new Node();
		tmpNode->setTile(new Tile(vecTiles[count][0], vecTiles[count][1] - '0'));
		tmpNode->prev = nullptr;
		tmpNode->next = nullptr;
		if (count == 0)
		{
			(*tileBag)->setHead(tmpNode);
		}
		else
		{
			(*tileBag)->addNodeToEnd(tmpNode);

		}

	}

	*currentPlayer = new Player();
	// set current player

	flag = true;

	if (flag == false)
	{
		return false;
		std::cout << "Qwirkle game loaded failed" << std::endl;
	}
	else
	{
		return true;
		std::cout << "Qwirkle game successfully loaded" << std::endl;
	}


}

void GameFile::test_save_game_file()
{
	// game round
	// initialise players
	Player *player1 = new Player("PLAYER1");
	Player *player2 = new Player("PLAYER2");

	// initialise board
	Board *board = new Board();
	//board->printBoard();
	board->putTile2Board('G', 4, 1, 1);
	board->putTile2Board('P', 5, 2, 2);
	board->putTile2Board('Y', 6, 3, 3);
	// initialise tile bag which contains shuffled tiles
	LinkedList *tileBag = new LinkedList();
	tileBag->iniTileBag();

	// initialise tiles in players' hands
	player1->initialiseTilesInHand(tileBag);
	player2->initialiseTilesInHand(tileBag);
	saveGame("SaveGame", player1, player1, player2, tileBag, board);


	// TEST LOAD GAME

}

void GameFile::test_load_game_file() {
	std::string loadPath = "SaveGame";
	Player *player1;
	Player *player2;
	Player *currentPlayer;
	LinkedList *tileBag;
	Board *board;
	loadGame(loadPath, &currentPlayer, &player1, &player2, &tileBag, &board);
	{// Verify load game file result:
		std::cout << "Verify load game file result:" << std::endl;
		std::cout << "Player 1 info: name :" << player1->getName() << ", score: " << player1->getScore() << std::endl;
		std::cout << "Player 2 info: name :" << player2->getName() << ", score: " << player2->getScore() << std::endl;
		board->printBoard();
		std::cout << "Tile bag:";
		for (int i = 1; i < tileBag->getSize(); i++)
		{
			std::cout << (tileBag->getTile(i))->getColour() << (tileBag->getTile(i))->getShape() << ',';
		}
	}
}

vector<std::string> GameFile::split(std::string s, char delim)
{
	vector<std::string> v;
	std::stringstream stringstream1(s);
	std::string tmp;
	while (getline(stringstream1, tmp, delim))
	{
		tmp = trim(tmp);
		if (tmp == "") continue;
		v.push_back(tmp);
	}
	return v;
}

bool GameFile::loadPlayerFromStream(Player * player, std::ifstream & inStream) {
	std::string name;
	inStream >> name;
	player->setName(name);
	int score;
	inStream >> score;
	player->setScore(score);

	std::string tilesInHand;
	while (tilesInHand == "")
	{
		getline(inStream, tilesInHand);
	}
	vector<std::string> vecTiles = split(tilesInHand, ',');
	for (int i = 0; i < vecTiles.size(); i++)
	{
		Tile *tmp = new Tile(vecTiles[i][0], vecTiles[i][1]);

		player->addTile(tmp);
	}
	return true;
}

std::string & GameFile::trim(std::string & s) {
	if (s.empty()) {
		return s;
	}

	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}
