#include "save_load_Game.h"

bool saveGame(std::string savePath, Player * player1, Player * player2, TileBag * tileBag, Board * board) {

	std::ofstream file(savePath,std::ios_base::out);
	
	// Save Player 1
	file << player1->getName() << std::endl;
	file << player1->getScore() << std::endl;
	LinkedList* tiles = player1->getTilesInHand();
	for (int i = 0; i < tiles->getSize(); i++)
	{
		Tile*t = tiles->getTile(i);
		file << t->getColour << t->getShape ;
		if (i < tiles->getSize() - 1) {
			file << ',';
		}
	}
	file << std::endl;


	// Save Player 2
	file << player2->getName() << std::endl;
	file << player2->getScore() << std::endl;
	tiles = player2->getTilesInHand();
	for (int i = 0; i < tiles->getSize(); i++)
	{
		Tile* t = tiles->getTile(i);
		file << t->getColour << t->getShape;
		if (i < tiles->getSize() - 1) {
			file << ',';
		}
	}
	file << std::endl;

	//Save Board 
	{
		// FIXEME
		//board->printBoard();
	}

	// Save TileBag
	tiles = tileBag->getTileBag();
	for (int i = 0; i < tiles->getSize(); i++)
	{
		Tile* t = tiles->getTile(i);
		file << t->getColour << t->getShape;
		if (i < tiles->getSize() - 1) {
			file << ',';
		}
	}
	file << std::endl;
	file.close();


	return false;
}

vector<string> split(string s, char delim) {
	vector<string> v;
	stringstream stringstream1(s);
	string tmp;
	while (getline(stringstream1, tmp, delim)) {
		v.push_back(tmp);
	}
	return v;
}
bool loadPlayerFromStream(Player* player,ifstream& inStream) {
	std::string name1;
	inStream >> name1;
	player = new Player(name1);
	int score;
	inStream >> score; player->setScore(score);
	std::string strTiles;
	getline(inStream, strTiles);
	vector<string> vecTiles = split(strTiles, ',');
	for (int i = 0; i < vecTiles.size(); i++)
	{
		Tile *tmp = new Tile(vecTiles[i][0], vecTiles[i][1]);
		player->addTile(tmp);
	}
	return true;
}

bool loadGame(std::string loadPath, Player * player1, Player * player2, TileBag * tileBag, Board * board) {
	std::ifstream inStream(loadPath, std::ios_base::in);
	if (!inStream.is_open())
	{
		std::cout << "Game file open fail!" << endl;
		return false;
	}
	// Read player 1
	loadPlayerFromStream(player1, inStream);
	// Read player 2
	loadPlayerFromStream(player2, inStream);

	//Load board
	{
		// FIXME
		board = new Board();
		string shapeStr;
		getline(inStream, shapeStr);
		vector<string> vecTiles = split(shapeStr, ',');
		for (int i = 0; i < vecTiles.size(); i++)
		{
			Tile *tmp = new Tile(vecTiles[i][0], vecTiles[i][1]);
			player->addTile(tmp);
		}

	}

	//Load tileBag
	tileBag = new TileBag();
	std::string strTiles;
	getline(inStream, strTiles);
	vector<string> vecTiles = split(strTiles, ',');
	tileBag->loadTileBag(vecTiles);

	return false;
}
