// rules.h
// The rules of Sudoku: a number can only appear once in each row,
// each column, and each 3x3 box.

#pragma once
#include "board.h"

// Can we put "num" into the square at (row, col) without breaking a rule?
bool isSafe(int board[SIZE][SIZE], int row, int col, int num);
