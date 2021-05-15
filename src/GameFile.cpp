#include "GameFile.h"
using std::stoi;
GameFile::GameFile()
{
}

GameFile::~GameFile()
{
}

void GameFile::quit()
{
  std::cout << '\n';
  std::cout << "Goodbye" << '\n';
  exit(0);
}

std::string GameFile::checkEOF()
{
  std::string output = "";
  std::cout << ">";
  std::getline(std::cin, output);
  if(std::cin.eof())
  {
    quit();
  }
  return output;
}

void GameFile::getSelectionFromMenu()
{
	std::cout << "Menu" << std::endl;
	std::cout << "----" << std::endl;
	std::cout << "1. New Game" << std::endl;
	std::cout << "2. Load Game" << std::endl;
	std::cout << "3. Credits (Show student information)" << std::endl;
	std::cout << "4. Quit" << std::endl;

	// int input;
	// std::cin >> input;
	// return input;
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
	for (int count = 1; count <= tileBag->getSize(); count++)
	{
		Tile *tmpTile = tileBag->getTile(count);
		Colour colour = tmpTile->colour;
		Shape shape = tmpTile->shape;
		file << colour << shape;
		if (count < tileBag->getSize())
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
bool GameFile::loadGame(std::string loadPath)
{

	int tileBagCount = 0;
	int boardTileCount = 0;
	int p1count = 0;
	int p2count = 0;

	int totalTiles = 0;
	std::ifstream inStream(loadPath, std::ios_base::in);
	if (!inStream.is_open())
	{
		std::cout << "Game file open fails!" << std::endl;
	}

	std::string s = "";
	int count = 0;
	
	std::string name1 = "";
	std::string name2 = "";
	// read line by line and set the value
	while (getline(inStream, s) && count < 10)
	{
		if (count == 0)
		{
			if (!isValidPlayerName(s))
			{
				return false;
			}
			else
			{
				name1 += s;
				count++;
			}
		}
		else if (count == 1)
		{
			if (!allNum(s))
			{
				return false;
			}
			else
			{
				count++;
			}
		}
		else if (count == 2)
		{
			vector<std::string> vecTiles = split(s, ',');
			for (unsigned int index = 0; index < vecTiles.size(); index++)
			{	
				if (!validTile(vecTiles[index]))
				{
					return false;
				}
				else
				{
					p1count++;
					totalTiles++;
				}
			}
			count++;
		}
		else if (count == 3)
		{
			if (!isValidPlayerName(s))
			{
				return false;
			}
			else
			{
				name2 += s;
				count++;
			}
		}
		else if (count == 4)
		{
			if (!allNum(s))
			{
				return false;
			}
			else
			{
				count++;
			}
		}
		else if (count == 5)
		{
			vector<std::string> vecTiles = split(s, ',');
			for (unsigned int index = 0; index < vecTiles.size(); index++)
			{	
				if (!validTile(vecTiles[index]))
				{
					return false;
				}				
				else
				{
					p2count++;
					totalTiles++;
				}
			}
			count++;
		}
		else if (count == 6)
		{
			vector<std::string> size = split(s, ',');
			if (size[0].compare("26") == 0 && size[1].compare("26") == 0)
			{
				count++;
			}
			else
			{
				return false;
			}
		}
		else if (count == 7)
		{

			vector<std::string> placeedInstruction = split(s, ',', ' ');
			vector<std::string> samePosChek;
			std::string tmpTileString = "";
			std::string posString = "";
			if (placeedInstruction.size() == 0)
			{
				count++;
			}
			else
			{
				for (unsigned int index = 0; 
							index < placeedInstruction.size(); index++)
				{
					// check tile
					tmpTileString = "";
					tmpTileString += placeedInstruction[index][0];
					tmpTileString += placeedInstruction[index][1];
					if (!validTile(tmpTileString))
					{
						return false;
					}

					// check '@'
					if (placeedInstruction[index][2] != '@')
					{
						return false;
					}

					// check position
					posString = "";
					for (unsigned int pos = 3; 
							pos < placeedInstruction[index].size(); pos++)
					{
						posString += placeedInstruction[index][pos];
					}

					if (!validPosition(posString))
					{
						return false;
					}
					else
					{
						samePosChek.push_back(posString);
						boardTileCount++;
						totalTiles++;
					}
				}
				if (!samePosCheck(samePosChek))
				{
					return false;
				}
				count++;
			}
		}
		else if (count == 8)
		{
			vector<std::string> tileBag = split(s, ',');
			

			for (unsigned int index = 0; index < tileBag.size(); index++)
			{	
				if (!validTile(tileBag[index]))
				{
					return false;
				}				
				else
				{
					tileBagCount++;
					totalTiles++;
				}
			}

			count++;
		}
		else if (count == 9)
		{
			if (s.compare(name1) != 0 && s.compare(name2) != 0)
			{
				return false;
			}
		}
	}

	if (totalTiles == TOTAL_TILES_NUM)
	{
		std::cout << "Qwirkle game is able to load" << std::endl;
		return true;
	}
	else
	{
		return false;
	}


	// if (flag == false)
	// {
	// 	std::cout << "Qwirkle game loaded failed" << std::endl;
	// }
	// else
	// {
	// 	std::cout << "Qwirkle game successfully loaded" << std::endl;
	// }

}


void GameFile::loadGameInfo(std::string loadPath, Player **currentPlayer, 
		Player *player1, Player *player2, LinkedList *tileBag, Board *board)
{
	std::ifstream inStream(loadPath, std::ios_base::in);
	if (!inStream.is_open())
	{
		std::cout << "Game file open fails!" << std::endl;
	}

	std::string s = "";
	int count = 0;
	std::cout << "start loading game info" << std::endl;
	// read line by line and set the value
	while (getline(inStream, s))
	{	
		std::cout << "loading the " << count << "st line." << std::endl;
		if (count == 0)
		{
			player1->setName(s);
			count++;
		}
		else if (count == 1)
		{
			int score;
			std::stringstream ss;  
			ss << s;
			ss >> score;
			player1->setScore(score);
			count++;
		}
		else if (count == 2)
		{
			LinkedList *tiles = new LinkedList();
			vector<std::string> vecTiles = split(s, ',');
			
			for (unsigned int index = 0; index < vecTiles.size(); index++)
			{
				Node *tmpNode = new Node();
				Tile *tmpTile = new Tile();
				Colour colour = vecTiles[index][0];
				Shape shape = vecTiles[index][1] - '0';
				tmpTile->colour = colour;
				tmpTile->shape = shape;
				tmpNode->tile = tmpTile;
				tmpNode->next = nullptr;
				tmpNode->prev = nullptr;
				if (index == 0)
				{
					tiles->setHead(tmpNode);
				}
				else
				{
					tiles->addNodeToEnd(tmpNode);
				}
			}
			player1->setTilesInHand(tiles);
			count++;
		}
		else if (count == 3)
		{
			player2->setName(s);
			count++;
		}
		else if (count == 4)
		{
			int score;
			std::stringstream ss;  
			ss << s;  
			ss >> score;
			player2->setScore(score);
			count++;
		}
		else if (count == 5)
		{
			LinkedList *tiles = new LinkedList();
			vector<std::string> vecTiles = split(s, ',');
			
			for (unsigned int index = 0; index < vecTiles.size(); index++)
			{
				Node *tmpNode = new Node();
				Tile *tmpTile = new Tile();
				Colour colour = vecTiles[index][0];
				Shape shape = vecTiles[index][1] - '0';
				tmpTile->colour = colour;
				tmpTile->shape = shape;
				tmpNode->tile = tmpTile;
				if (index == 0)
				{
					tiles->setHead(tmpNode);
				}
				else
				{
					tiles->addNodeToEnd(tmpNode);
				}
			}
			player2->setTilesInHand(tiles);
			
			count++;
		}
		else if (count == 6)
		{
			count++;
		}
		else if (count == 7)
		{
			vector<std::string> placeedInstruction = split(s, ',', ' ');
			if (placeedInstruction.size() == 0)
			{
				count++;
			}
			else
			{
				for (unsigned int index = 0; 
							index < placeedInstruction.size(); index++)
				{
					// set tile
					std::string tmpTileString = "";
					tmpTileString = placeedInstruction[index][0];
					tmpTileString += placeedInstruction[index][1];
					Colour colour = tmpTileString[0];
					Shape shape = tmpTileString[1] - '0';

					// set position
					std::string posString = "";
					for (unsigned int pos = 3; 
							pos < placeedInstruction[index].size(); pos++)
					{
						posString +=placeedInstruction[index][pos];
					}
					int row = 0;
					int col = 0;
					row = posString[0] - 'A';
					if (posString.size() == 2)
					{
						col = posString[1] - '0';
					}
					else if (posString.size() == 3)
					{
						int digits = posString[2] - '0';
						int tens = (posString[1] - '0') * 10;
						col = tens + digits;
					}
					std::cout << "tile info and position calculated: " << row << " " << col << " " << colour << " " << shape << std::endl;
					board->putTile2Board(colour, shape, row, col);
					board->printBoard();
				}
				count++;
			}
			
		}
		else if (count == 8)
		{
			vector<std::string> tilesInBag = split(s, ',');
			for (unsigned int index = 0; index < tilesInBag.size(); index++)
			{	
				Node *tmpNode = new Node();
				Tile *tmpTile = new Tile();
				Colour colour = tilesInBag[index][0];
				Shape shape = tilesInBag[index][1] - '0';
				tmpTile->colour = colour;
				tmpTile->shape = shape;
				tmpNode->tile = tmpTile;
				if (index == 0)
				{
					tileBag->setHead(tmpNode);
					tileBag->head->next = nullptr;
					tileBag->head->prev = nullptr;
				}
				else
				{
					tileBag->addNodeToEnd(tmpNode);
				}
			}
			count++;
		}
		else if (count == 9)
		{
			std::cout << count << std::endl;
			if (s.compare(player1->getName()) == 0)
			{
				std::cout << count << std::endl;
				*currentPlayer = player1;
				std::cout << count << std::endl;
			}
			else if (s.compare(player2->getName()) == 0)
			{
				std::cout << count << std::endl;
				*currentPlayer = player2;
				std::cout << count << std::endl;
			}
			
		}
	}
}

vector<std::string> GameFile::split(std::string string, char delim)
{
	vector<std::string> value;
	std::string tmp = "";
	for (unsigned int index = 0; index < string.size(); index++)
	{
		if (string[index] != delim)
		{
			tmp += string[index];
		}
		else 
		{
			value.push_back(tmp);
			tmp = "";
		}
	}
	value.push_back(tmp);
	return value;
}

vector<std::string> GameFile::split(std::string string, char delim1, char delim2)
{
	vector<std::string> value;
	std::string tmp = "";
	if (string.compare("") == 0)
	{
		value.resize(0);
		std::cout << "value size: " << value.size() <<std::endl;
	}
	else
	{
		for (unsigned int index = 0; index < string.size(); index++)
		{
			if (string[index] != delim1 && string[index] != delim2)
			{
				tmp += string[index];
			}
			else if (string[index] == delim1)
			{
				value.push_back(tmp);
				tmp = "";
			}
		}
		value.push_back(tmp);
	}
	return value;
}

std::string & GameFile::trim(std::string & s) {
	if (s.empty()) {
		return s;
	}

	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}
