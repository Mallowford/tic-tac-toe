#pragma
#include <vector>
#include <iostream>

enum Piece {
    None = 0,
    Cross,
    Circle,
};

class Game {
    private:
        std::vector<std::vector<Piece>> board;
        Piece currTurn = Cross;
        Piece winnerPiece = None;
    public:
        Game(int size = 3);

        bool hasFinished();
        Piece whoWon() const;

        void clean();
        bool place(int row, int col);
        void printBoard() const;
};