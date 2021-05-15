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