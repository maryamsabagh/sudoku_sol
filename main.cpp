// main.cpp
// The starting point of the program. It runs the steps in order:
// make a puzzle, save it as a picture, solve it, save the answer as a picture.


#include <iostream>
#include "board.h"
#include "generator.h"
#include "solver.h"

using namespace std;

// Change this to make puzzles easier (more clues) or harder (fewer clues).
// 25 is the lowest that stays fast (a second or two). Below 25 the generator
// gets slow (up to 30 seconds) and still can't get much lower than 24.
// The true minimum for any Sudoku is 17, but this simple generator can't reach it.
const int CLUES = 26;

int main() {
    int puzzle[SIZE][SIZE];  // the puzzle exactly as it was made. We never change this one.
    generatePuzzle(puzzle, CLUES);

    // Make a copy of the puzzle for the solver to fill in. That way we still have
    // the original, and can tell which numbers the solver added.
    int board[SIZE][SIZE];
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = puzzle[row][col];
        }
    }

    // Nothing was added by the solver yet, so every number is black.
    saveSvg(puzzle, puzzle, "puzzle.svg");

    solve(board);  // fills in every empty square
    saveSvg(board, puzzle, "solution.svg");

    cout << "Saved puzzle.svg and solution.svg" << endl;
    return 0;
}
