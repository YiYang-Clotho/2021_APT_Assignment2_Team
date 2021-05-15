#include <iostream>
#include "BaseGame.h"

std::vector<std::string> split(std::string input, std::string delimiter);
Tile tokenToTile(std::string token);

BaseGame::BaseGame(std::string player1, std::string player2) {
    // Setup game
    a_name = player1;
    b_name = player2;
    // Setup board
    board.resize(26);
    for (int k = 0; k < 26; ++k) {
        board[k].resize(26);
    }
    // Setup tiles
    a_hand = new LinkedList();
    b_hand = new LinkedList();
    bag = new LinkedList();
    // Random add tiles to the bag and hands,total 6*6*2 = 72
    std::vector<char> colors = { 'R','O','Y','G','B','P' };
    std::vector<Tile> tiles;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 6; j++) {
            Tile tile;
            tile.shape = i;
            tile.colour = colors[j];
            tiles.push_back(tile);
            tiles.push_back(tile);
        }
    }
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(tiles), std::end(tiles), rng);
    for (int k = 0; k < 6; k++) {
        Tile tile = tiles[k];
        a_hand->insertLast(tiles[k]);
    }
    for (int m = 6; m < 12; m++) {
        b_hand->insertLast(tiles[m]);
    }
    for (int n = 12; n < 72; n++) {
        bag->insertLast(tiles[n]);
    }
}

std::string BaseGame::boardState() {
    std::string currentState = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (board[i][j].toString() != "  ") {
                char rowIndex = (char)(i + 65);
                currentState = currentState + rowIndex + std::to_string(j) + "@" + board[i][j].toString()+", ";
            }
        }
    }
    return currentState.substr(0, currentState.size() - 1);
}

void BaseGame::drawBoard() {
    std::cout << " ";
    for (int i = 0; i < 26; i++) {
        if (i <= 10) {
            std::cout << " " << i << " ";
        } else {
            std::cout << i << " ";
        }
       
    }
    std::cout << "\n ";
    for (int i = 0; i < 26; i++) {
        std::cout << "---";
    }
    std::cout << "\n";
    for (char i = 0; i < 26; i++) {
        std::cout << (char)(i+65) << "|";
        for (int j = 0; j < 26; j++){
            std::cout << board[i][j].toString() << "|";
        }
        std::cout << "\n";
    }
   
}
void BaseGame::updateScore(int row, int col) {
    // check row.
    int left_color=0, left_shape = 0;
    int left_row_index = row - 1;
    while (true) {
        if (board[left_row_index][col].shape == board[row][col].shape) {
            left_shape++;
        }
        if (board[left_row_index][col].colour == board[row][col].colour) {
            left_color++;
        }
        if (board[left_row_index][col].shape != board[row][col].shape &&
            board[left_row_index][col].colour != board[row][col].colour) {
            break;
        }
        left_row_index--;
        if (left_row_index == -1) {
            break;
        }
    }
    int right_color=0, right_shape = 0;
    int right_row_index = row + 1;
    while (true) {
        if (board[right_row_index][col].shape == board[row][col].shape) {
            right_shape++;
        }
        if (board[right_row_index][col].colour == board[row][col].colour) {
            right_color++;
        }
        if (board[right_row_index][col].shape != board[row][col].shape &&
            board[right_row_index][col].colour != board[row][col].colour) {
            break;
        }
        right_row_index++;
        if (right_row_index == 26) {
            break;
        }
    }

    // check column
    int up_color=0, up_shape = 0;
    int up_col_index = col - 1;
    while (true) {
        if (board[row][up_col_index].shape == board[row][col].shape) {
            up_shape++;
        }
        if (board[row][up_col_index].colour == board[row][col].colour) {
            up_color++;
        }
        if (board[row][up_col_index].shape != board[row][col].shape &&
            board[row][up_col_index].colour != board[row][col].colour) {
            break;
        }
        up_col_index--;
        if (up_col_index == -1) {
            break;
        }
    }
    int down_color=0, down_shape = 0;
    int down_col_index = col + 1;
    while (true) {
        if (board[row][down_col_index].shape == board[row][col].shape) {
            down_shape++;
        }
        if (board[row][down_col_index].colour == board[row][col].colour) {
            down_color++;
        }
        if (board[row][down_col_index].shape != board[row][col].shape &&
            board[row][down_col_index].colour != board[row][col].colour) {
            break;
        }
        down_col_index++;
        if (down_col_index == 26) {
            break;
        }
    }
    int bonus = 0;
    if (left_color + right_color == 5 ||
        left_shape + right_shape == 5 ||
        up_shape + down_shape == 5    ||
        up_color + down_color == 5) {
        bonus = 6;
        std::cout << "QUIRKLE��" << std::endl;
    }

    int total_score = left_color + left_shape + right_color + right_shape +
        up_shape + up_color + down_color + down_shape + bonus;

    if (total_score > 0) {
        if (flag) {
            a_score = a_score + total_score + 1;
        } else {
            b_score = b_score + total_score + 1;
        }
    }
}

void BaseGame::updateHand(Tile placed_tile) {
    Tile tile = bag->removeFirst();
    if (tile.toString() == "  ") {
        return;
    }
    if (flag) {
        if (a_hand->remove(placed_tile)) {
            a_hand->insertLast(tile);
        }  
    } else {
        if (b_hand->remove(placed_tile)) {
            b_hand->insertLast(tile);
        }
    }
}

void BaseGame::replaceHand(Tile placed_tile) {
    Tile tile = bag->removeFirst();
    if (tile.toString() == "  ") {
        return;
    }
    if (flag) {
        if (a_hand->remove(placed_tile)) {
            a_hand->insertLast(tile);
            bag->insertLast(placed_tile);
        }
    } else {
        if (b_hand->remove(placed_tile)) {
            b_hand->insertLast(tile);
            bag->insertLast(placed_tile);
        }
    }
}

void BaseGame::saveGame(std::string filename) {
    std::ofstream outfile;
    try {
        outfile.open(filename, std::ios::out | std::ios::trunc);
        outfile << a_name << "\n";
        outfile << a_score << "\n";
        outfile << a_hand->showList() << "\n";
        outfile << b_name << "\n";
        outfile << b_score << "\n";
        outfile << b_hand->showList() << "\n";
        outfile << board.size() << "," << board[0].size() << "\n";
        outfile << boardState() << "\n";
        outfile << bag->showList() << "\n";
        if (flag) {
            outfile << a_name << "\n";
        } else {
            outfile << b_name << "\n";
        }
        outfile.close();
    } catch (const char* msg) {
        std::cout << "Game can't be saved" << std::endl;
    }
    std::cout << "Game successfully saved" << std::endl;
}

void BaseGame::handleCommand(std::string command) {
    std::vector<std::string> tokens = split(command," ");
    if (tokens[0] == "place") {
        std::string tile = tokens[1];
        std::string place = tokens[3];
        Tile placed_tile;
        placed_tile.colour = tile[0];
        placed_tile.shape = tile[1] - '0';
        int row = place[0] - 'A';
        int col = (place[1]) - '0';
        this->board[row][col] = placed_tile;
        updateHand(placed_tile);
        updateScore(row, col);
    } else if(tokens[0] == "replace") {
        std::string tile = tokens[1];
        Tile replaced_tile;
        replaced_tile.colour = tile[0];
        replaced_tile.shape = tile[1] - '0';
        replaceHand(replaced_tile);
    } else if (tokens[0] == "save") {
        saveGame(tokens[1]);
        playTurn();
    } else if (tokens[0] == "quit") {
        std::cout << "Goodbye" << std::endl;
        exit(0);
    }
}

void BaseGame::play() {
    while (true) {
        playTurnBefore();
        playTurn();
        if (flag) {
            flag = 0;
        } else {
            flag = 1;
        }
    }
}
void BaseGame::playTurnBefore() {
    if (flag) {
        std::cout << a_name << ",it's your turn" << std::endl;
    } else {
        std::cout << b_name << ",it's your turn" << std::endl;
    }
    std::cout << "Score for A: " << a_score << std::endl;
    std::cout << "Score for B: " << b_score << std::endl << std::endl;
    drawBoard();
    std::cout << "\nYour hand is" << std::endl;
    if (flag) {
        std::cout << a_hand->showList() << std::endl;
    } else {
        std::cout << b_hand->showList() << std::endl;
    }
}

void BaseGame::checkEnd() {
    if (bag->isEmpty() && (a_hand->isEmpty() || b_hand->isEmpty())) {
        std::cout << "Game over" << std::endl;
        std::cout << "Score for " << a_name << ": " << a_score << std::endl;
        std::cout << "Score for " << b_name << ": " << b_score << std::endl;
        if (a_score > b_score) {
            std::cout << "Player " << a_name << "won! " << std::endl;
        } else {
            std::cout << "Player " << b_name << "won! " << std::endl;
        }
        std::cout << "\nGoodbye" << std::endl;
        exit(0);
    }
}

void BaseGame::playTurn() {
    std::cout << "\n> ";
    std::string command;
    std::getline(std::cin, command);
    handleCommand(command);
    checkEnd();
}

void BaseGame::load(std::string filename) {
    std::string line;
    std::ifstream infile(filename);
    // a information
    std::getline(infile, a_name);
    std::getline(infile, line);
    a_score = std::stoi(line);
    std::getline(infile, line);
    std::vector<std::string> tiles = split(line, ",");
    a_hand = new LinkedList();
    for (int i = 0; i < tiles.size(); i++) {
        a_hand->insertLast(tokenToTile(tiles[i]));
    }
    // b information
    std::getline(infile, b_name);
    std::getline(infile, line);
    b_score = std::stoi(line);
    std::getline(infile, line);
    tiles = split(line, ",");
    b_hand = new LinkedList();
    for (int i = 0; i < tiles.size(); i++) {
        b_hand->insertLast(tokenToTile(tiles[i]));
    }
    // board size
    std::getline(infile, line);
    // board state
    std::getline(infile, line);
    tiles = split(line, ", ");
    for (int i = 0; i < tiles.size(); i++) {
        int row = tiles[i][0] - 'A';
        int col = tiles[i][1] - '0';
        std::string token = tiles[i].substr(3, 5);
        Tile tile = tokenToTile(token);
        board[row][col] = tile;
    }
    // bag state
    std::getline(infile, line);
    tiles = split(line, ",");
    bag = new LinkedList();
    for (int i = 0; i < tiles.size(); i++) {
        bag->insertLast(tokenToTile(tiles[i]));
    }
    //current player
    std::getline(infile, line);
    if (line == a_name) {
        flag = 1;
    } else {
        flag = 0;
    }
    infile.close();
    play();
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
 
