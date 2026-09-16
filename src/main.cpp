#include "../header/Game.hpp"

int main() {
    Game engine;

    bool restart = false;

    do
    {
        // Print board state
        engine.printBoard();

        // Prompt to ask where to place

        if (engine.hasFinished()) {
            // Print out winner
            

            // Prompt to ask whether to restart or not
 
        };

    } while (restart);

    return 0;
};