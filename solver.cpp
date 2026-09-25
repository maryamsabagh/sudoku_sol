
// The part that actually solves the puzzle, using "backtracking".
//
// The idea:
//   1. Find an empty square.
//   2. Try the numbers 1 to 9 in it, one at a time.
//   3. If a number is safe, place it and try to solve the rest of the board
//      (this function calls itself to do that).
//   4. If the rest of the board can't be solved, that number was a bad guess:
//      take it out and try the next number.
//   5. If no number works, give up on this square. Returning false sends us
//      back to the previous square, which will try its next number.

#include "solver.h"
#include "rules.h"

bool solve(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {

            if (board[row][col] == 0) {                // found an empty square
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;         // make a guess
                        if (solve(board)) return true; // the guess worked out!
                        board[row][col] = 0;           // the guess failed, undo it
                    }
                }
                return false;                          // no number fits here
            }

        }
    }
    return true;  // there were no empty squares left, so the puzzle is solved
}


// Works like solve(), but instead of stopping at the first answer it keeps
// going and adds up how many answers there are.
int countSolutions(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {

            if (board[row][col] == 0) {                // found an empty square
                int count = 0;
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;         // make a guess
                        count = count + countSolutions(board);
                        board[row][col] = 0;           // always undo the guess
                        if (count >= 2) return count;  // two is enough, stop early
                    }
                }
                return count;
            }

        }
    }
    return 1;  // no empty squares left: this path is one complete solution
}
