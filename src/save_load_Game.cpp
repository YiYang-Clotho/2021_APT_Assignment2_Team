#include "save_load_Game.h"

bool saveGame(std::string savePath, Player *currentPlayer, 
			Player *player1, Player *player2,
			  LinkedList *tileBag, Board *board)
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
	int colSize = board->position[rowSize].size();
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
			if (board->position[row][col]->tile == nullptr)
			{
				return;
			}
			else
			{
				Colour colour = board->position[row][col]->tile->colour;
				Shape shape = board->position[row][col]->tile->shape + '0';
				file << colour << shape << '@';
				char outCol = (col + ASCII_A) + '0';
				file << outCol;
				if (row >= 10)
				{
					char tens = (row / 10) + '0';
					char digits = (row % 10) + '0';
					file << tens << digits;
				}
				else
				{
					char outRow = row + '0';
				}
				counter++;

				if (counter != tilesOnBoardNum)
				{
					file << ", ";
				}
				else
				{
					file << std::endl;
				}
			}
		}
	}

	// Save TileBag
	for (int count = 0; count < tileBag->getSize(); count++)
	{
		Tile *tmpTile = tileBag->getTile(count);
		Colour colour = tmpTile->colour;
		Shape shape = tmpTile->shape;
		file << colour << shape;
		if (count < tileBag->getSize() - 1)
		{
			file << ',';
		}else{
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

vector<std::string> split(std::string s, char delim)
{
	vector<std::string> v;
	std::stringstream stringstream1(s);
	std::string tmp;
	while (getline(stringstream1, tmp, delim))
	{
		v.push_back(tmp);
	}
	return v;
}

bool loadPlayerFromStream(Player *player, std::ifstream &inStream)
{
	std::string name1;
	inStream >> name1;
	player = new Player(name1);
	int score;
	inStream >> score;
	player->setScore(score);
	std::string strTiles;
	getline(inStream, strTiles);
	vector<std::string> vecTiles = split(strTiles, ',');
	for (int i = 0; i < vecTiles.size(); i++)
	{
		Tile *tmp = new Tile(vecTiles[i][0], vecTiles[i][1]);
		player->addTile(tmp);
	}
	return true;
}

bool loadGame(std::string loadPath)
{
	bool flag = false;
	std::ifstream inStream(loadPath, std::ios_base::in);
	if (!inStream.is_open())
	{
		std::cout << "Game file open fails!" << std::endl;
	}

	// Read player 1
	Player *player1 = new Player();
	loadPlayerFromStream(player1, inStream);
	// Read player 2
	Player *player2 = new Player();
	loadPlayerFromStream(player2, inStream);

	//Load board
	{
		// FIXME
		Board *board = new Board();
		std::string shapeStr;
		getline(inStream, shapeStr);
		vector<std::string> vecTiles = split(shapeStr, ',');
		for (int i = 0; i < vecTiles.size(); i++)
		{
			Tile *tmp = new Tile(vecTiles[i][0], vecTiles[i][1]);
			player1->addTile(tmp);
		}
	}

	//Load tileBag
	LinkedList *tileBag = new LinkedList();
	std::string strTiles;
	getline(inStream, strTiles);
	vector<std::string> vecTiles = split(strTiles, ',');
	for (unsigned int count = 0; count < vecTiles.size(); count++)
	{
		Node *tmpNode = new Node();
		tmpNode->tile->colour = vecTiles[count][0];
		tmpNode->tile->shape = vecTiles[count][1] - '0';
		tmpNode->prev = nullptr;
		tmpNode->next = nullptr;
		if (count == 0)
		{
			tileBag->setHead(tmpNode);
		}
		else
		{
			tileBag->addNodeToEnd(tmpNode);
			
		}
		
	}

	Player *currentPlayer = new Player();
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
