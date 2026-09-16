#pragma
#include <vector>

enum Piece {
    None = 0,
    Cross,
    Circle,
};

class Game {
    private:
        std::vector<std::vector<Piece>> board;
    public:
        Game(int size = 3);

        void Place(int row, int col);
        bool CheckWin() const;
        Piece checkWinner() const;

};