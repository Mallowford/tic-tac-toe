#include "../header/Game.hpp"

Piece Game::whoWon() const {
    // Check win patterns
    // Return piece that is in the pattern
};

bool Game::hasFinished() const {
    // Check Win Conditions

    // Check if board is full

};

Game::Game(int size) {
    for (int i = 0; i < size; i++) {
        std::vector<Piece> blankBoard;
        for (int j = 0; j < size; j++) {
            blankBoard.push_back(None);
        };
        board.push_back(blankBoard);
    };
};

void Game::clean() {
    int size = board.size() - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board.at(i).at(j) = None;
        };
    };
};

void Game::printBoard() const {
    int size = board.size() - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Piece currPiece = board.at(i).at(j);
            char sym = '/';
            if (currPiece == Cross) {
                sym = 'X';
            }
            else if (currPiece == Circle) {
                sym = 'O';
            };

            std::cout << sym << " ";
        };
        std::cout << "\n";
    };
};

bool Game::place(int row, int col) {
    // Check if there's already a piece at location
    if (board.at(row).at(col) != None) {
        return false;
    };

    // Place piece at location
    board.at(row).at(col) = this->currTurn;
    
    if (this->currTurn == Cross) {
        this->currTurn = Circle;
    }
    else {
        this->currTurn = Cross;
    };
};