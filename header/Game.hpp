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
    public:
        Game(int size = 3);

        bool hasFinished() const;
        Piece whoWon() const;

        void clean();
        bool place(int row, int col);
        void printBoard() const;
};