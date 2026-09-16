#include "../header/Game.hpp"

int main() {
    Game engine;

    bool restart = false;

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
            // Print out winner
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
                if (tolower(input) == 'y') {
                    restart = false;
                    validInput = true;
                }
                else if (tolower(input) == 'n') {
                    restart = true;
                    validInput = true;
                }
                else {
                    std::cout << "invalid input";
                };
            } while(!validInput);
 
        };

    } while (!restart && !engine.hasFinished());

    return 0;
};