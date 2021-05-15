#include "GameFile.h"
using std::stoi;
GameFile::GameFile()
{
}

GameFile::~GameFile()
{
}

// Save Game data to file 
void GameFile::saveGame(std::string savePath, Player *currentPlayer, 
	Player *player1, Player *player2, LinkedList *tileBag, Board *board)
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
				Colour colour = board->position[row][col]->tile->colour;
				Shape shape = board->position[row][col]->tile->shape;
				file << colour << shape << '@';
				int rowOut = row + ASCII_A - ASCII_0;
				char outRow = rowOut + '0'; 
				file << outRow << col;
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
		std::cout << "Game successfully saved" << std::endl;
	}
	else
	{
		std::cout << "Save game failed" << std::endl;
	}

}

// Load history Game data from file ,
void GameFile::loadGame(std::string loadPath)
{
	Player *player1 = new Player();
	Player *player2 = new Player();
	// Board *board = new Board();
	// LinkedList *tileBag = new LinkedList();
	Player *currentPlayer = new Player();

	std::ifstream inStream(loadPath, std::ios_base::in);
	if (!inStream.is_open())
	{
		std::cout << "Game file open fails!" << std::endl;
	}

	std::string s = "";
	int count = 0;

	// read line by line and set the value
	while (getline(inStream, s))
	{
		if (count == 0)
		{
			player1->setName(s);
			count++;
		}
		if (count == 1)
		{
			int score;
			std::stringstream ss;  
			ss << s;  
			ss >> score;
			player1->setScore(score);
			count++;
		}
		if (count == 2)
		{
			LinkedList *tiles = new LinkedList();
			vector<std::string> vecTiles = split(s, ',');
			for (unsigned int index = 0; index < vecTiles.size(); index++)
			{
				Colour colour = vecTiles[index][0];
				Shape shape = vecTiles[index][1] - '0';
				Node *tmpNode = new Node();
				tmpNode->tile->colour = colour;
				tmpNode->tile->shape = shape;
				if (index == 0)
				{
					tiles->setHead(tmpNode);
					tiles->head->next = nullptr;
					tiles->head->prev = nullptr;
				}
				else
				{
					tiles->addNodeToEnd(tmpNode);
				}
			}
			player1->setTilesInHand(tiles);
			count++;
		}
		if (count == 3)
		{
			player2->setName(s);
			count++;
		}
		if (count == 4)
		{
			int score;
			std::stringstream ss;  
			ss << s;  
			ss >> score;
			player2->setScore(score);
			count++;
		}
		if (count == 5)
		{
			LinkedList *tiles = new LinkedList();
			vector<std::string> vecTiles = split(s, ',');
			for (unsigned int index = 0; index < vecTiles.size(); index++)
			{
				Colour colour = vecTiles[index][0];
				Shape shape = vecTiles[index][1] - '0';
				Node *tmpNode = new Node();
				tmpNode->tile->colour = colour;
				tmpNode->tile->shape = shape;
				if (index == 0)
				{
					tiles->setHead(tmpNode);
					tiles->head->next = nullptr;
					tiles->head->prev = nullptr;
				}
				else
				{
					tiles->addNodeToEnd(tmpNode);
				}
			}
			player2->setTilesInHand(tiles);
			count++;
		}
		if (count == 6)
		{
			count++;
		}
		if (count == 7)
		{
			// board
			count++;
		}
		if (count == 8)
		{
			// tile bag
			count++;
		}
		if (count == 9)
		{
			if (s.compare(player1->getName()) == 0)
			{
				currentPlayer = player1;
			}
			else
			{
				currentPlayer = player2;
			}
		}
	}
	

	

	//Load board
	
	// std::string shapeStr;
	// while (shapeStr == "")
	// {
	// 	getline(inStream, shapeStr);
	// }

	// std::string tilesStr;
	// while (tilesStr == "")
	// {
	// 	getline(inStream, tilesStr);
	// }
	// vector<std::string> vecTiles = split(tilesStr, ',');
	// for (int i = 0; i < vecTiles.size(); i++)
	// {
	// 	Colour colour = vecTiles[i][0];
	// 	int atPos = (vecTiles[i]).find('@');
	// 	Shape shape =std::stoi( vecTiles[i].substr(1,atPos-1));
	// 	int row = vecTiles[i][atPos+1] - 'A';
	// 	int col = stoi(vecTiles[i].substr(atPos+2, vecTiles[i].size()));
	// 	board->position[row][col]->tile->colour = colour;
	// 	board->position[row][col]->tile->shape = shape;
	// 	//*player1->addTile(tmp);
	// }

	// //Load tileBag
	// LinkedList *tileBag = new LinkedList();
	// std::string strTiles;
	// while (strTiles == "")
	// {
	// 	getline(inStream, strTiles);
	// }	
	// vector<std::string> vecTiles = split(strTiles, ',');
	// for (unsigned int count = 0; count < vecTiles.size(); count++)
	// {
	// 	Node *tmpNode = new Node();
	// 	tmpNode->tile->colour = vecTiles[count][0];
	// 	tmpNode->tile->shape = vecTiles[count][1] - '0';
	// 	tmpNode->prev = nullptr;
	// 	tmpNode->next = nullptr;
	// 	if (count == 0)
	// 	{
	// 		(tileBag)->setHead(tmpNode);
	// 	}
	// 	else
	// 	{
	// 		(tileBag)->addNodeToEnd(tmpNode);

	// 	}

	// }

	// Player *currentPlayer = new Player();
	// std::string name;
	// if (player1->getName().compare(name) == 0)
	// {
	// 	currentPlayer = player1;
	// }
	// else
	// {
	// 	currentPlayer = player2;
	// }

	// flag = true;

	// if (flag == false)
	// {
	// 	std::cout << "Qwirkle game loaded failed" << std::endl;
	// }
	// else
	// {
	// 	std::cout << "Qwirkle game successfully loaded" << std::endl;
	// }


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

std::string & GameFile::trim(std::string & s) {
	if (s.empty()) {
		return s;
	}

	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}
