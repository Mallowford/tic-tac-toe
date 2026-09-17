#include "../header/Game.hpp"

int main() {
    Game engine;

    bool restart = true;

    do {
        bool validInput = false;
        do {
            // Print board state
            engine.printBoard();

            // Prompt to ask where to place
            std::cout << "Where would you like to place?\nRow: ";
            int row;
            std::cin >> row;
            std::cout << "Col: ";
            int col;
            std::cin >> col;
            std::cout << "\n";

            if (engine.place(row - 1, col - 1)) {
                validInput = true;
            }
            else {
                std::cout << "Invalid, try again\n\n";
            };
        } while(!validInput);

        validInput = false;

        if (engine.hasFinished()) {
            engine.printBoard();

            Piece winner = engine.whoWon();
            if (winner == Cross) {
                std::cout << "Cross wins\n";
            }
            else if (winner == Circle) {
                std::cout << "Circle wins\n";
            }
            else {
                std::cout << "Tied\n";
            };

            // Prompt to ask whether to restart or not
            do {
                std::cout << "Restart? (y/n): ";
                char input;
                std::cin >> input;
                std::cout << "\n";
                if (tolower(input) == 'y') {
                    restart = true;
                    validInput = true;
                    engine.clean();
                }
                else if (tolower(input) == 'n') {
                    restart = false;
                    validInput = true;
                }
                else {
                    std::cout << "invalid input, please try again\n";
                };
            } while(!validInput);
 
        };

    } while (restart && !engine.hasFinished());

    return 0;
};