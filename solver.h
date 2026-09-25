// solver.h
// The part that actually solves the puzzle.

#pragma once
#include "board.h"

// Fills in every empty square. Returns true if the puzzle was solved,
// false if it has no solution. The board is changed directly: when you pass
// an array to a function, the function works on the original, not a copy.
bool solve(int board[SIZE][SIZE]);

// Counts how many different solutions the puzzle has, but stops counting once
// it reaches 2 (we only care whether there is exactly one).
// Unlike solve(), this leaves the board the way it found it.
int countSolutions(int board[SIZE][SIZE]);
