#include "../header/Game.hpp"

Piece Game::whoWon() const {
    // Check win patterns
    // Return piece that is in the pattern
    return this->winnerPiece;
};

bool Game::hasFinished() {
    // Check Win Conditions

    // Diagonal (Left to Right)
    for (int i = 0; i < board.size() - 1; i++) {
        Piece curr = board.at(i).at(i);
        Piece next = board.at(i + 1).at(i + 1);

        if (curr == None || next == None) {
            break;
        };

        if (curr != next) {
            break;
        };

        if (i == board.size() - 2) {
            this->winnerPiece = curr;
            return true;
        };

    };

    // Diagonal (Right to Left)
    for (int i = 0; i < board.size() - 1; i++) {
        Piece curr = board.at(board.size() - 1 - i).at(i);
        Piece next = board.at(board.size() - i - 2).at(i + 1);

        if (curr == None || next == None) {
            break;
        };

        if (curr != next) {
            break;
        };

        if (i == board.size() - 2) {
            this->winnerPiece = curr;
            return true;
        };

    };

    // Horizontal Check
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size() - 1; j++) {
            Piece curr = board.at(i).at(j);
            Piece next = board.at(i).at(j+1);

            if (curr == None || next == None) {
                break;
            };

            if (curr != next) {
                break;
            };

            if (j == board.size() - 2) {
                this->winnerPiece = curr;
                return true;
            };
        };
    };

    // Vertical Check
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size() - 1; j++) {
            Piece curr = board.at(j).at(i);
            Piece next = board.at(j+1).at(i);

            if (curr == None || next == None) {
                break;
            };

            if (curr != next) {
                break;
            };

            if (j == board.size() - 2) {
                this->winnerPiece = curr;
                return true;
            };
        };
    };


    // Check if board is full
    bool endEarly = false;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (i == board.size() - 1 && j == i) {
                if (board.at(i).at(j) != None) {
                    this->winnerPiece = None;
                    return true;
                };
            };
            if (board.at(i).at(j) == None) {
                endEarly = true;
                break;
            };
        };

        if (endEarly) {
            break;
        };
        
    };

    return false;
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
    int size = board.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board.at(i).at(j) = None;
        };
    };
};

void Game::printBoard() const {
    int size = board.size();

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
    if (row < 0 || row > board.size()) {
        return false;
    };
    if (col < 0 || col > board.size()) {
        return false;
    };

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

    return true;
};