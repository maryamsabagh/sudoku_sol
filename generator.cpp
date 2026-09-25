// generator.cpp
// Makes a new random puzzle. The idea:
//   1. Start with an empty board.
//   2. Put the numbers 1 to 9 in the top row in a random order.
//   3. Use solve() to fill in the rest. Now we have a complete, valid board.
//   4. Remove numbers from random squares, but put a number back if taking it
//      out would let the puzzle be solved in more than one way.
//      What is left is the puzzle.

#include <cstdlib>  // for rand() and srand() (random numbers)
#include <ctime>    // for time() (so the random numbers are different every run)
#include "generator.h"
#include "solver.h"

void generatePuzzle(int board[SIZE][SIZE], int clues) {
    int blanks = SIZE * SIZE - clues;  // how many squares to empty

    srand(time(0));  // start the random number generator from the current time

    // Step 1: empty the board.
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = 0;
        }
    }

    // Step 2: put 1 to 9 in the top row, then shuffle them.
    for (int col = 0; col < SIZE; col++) {
        board[0][col] = col + 1;
    }
    for (int col = 0; col < SIZE; col++) {
        int other = rand() % SIZE;         // a random column from 0 to 8
        int temp = board[0][col];          // swap the two numbers
        board[0][col] = board[0][other];
        board[0][other] = temp;
    }

    // Step 3: fill in the rest of the board.
    solve(board);

    // Step 4: remove numbers from random squares.
    int removed = 0;
    int tries = 0;
    while (removed < blanks && tries < 500) {  // give up after 500 tries
        tries++;
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (board[row][col] != 0) {            // skip squares that are already empty
            int number = board[row][col];      // remember it, in case we need to put it back
            board[row][col] = 0;
            if (countSolutions(board) == 1) {
                removed++;                     // still exactly one solution: keep it removed
            } else {
                board[row][col] = number;      // more than one solution: put it back
            }
        }
    }
}
