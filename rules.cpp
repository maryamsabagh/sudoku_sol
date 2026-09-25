
// rules of Sudoku: a number can only appear once in each row,column, and 3x3 box.

#include "rules.h"

bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    // Check the whole row and the whole column.
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) return false;  // already in this row
        if (board[i][col] == num) return false;  // already in this column
    }

    // Find the top-left corner of the 3x3 box that this square belongs to.
    // Integer division throws away the remainder, so 4 / 3 * 3 is 3.
    int boxRow = row / 3 * 3;
    int boxCol = col / 3 * 3;

    // Check the 9 squares inside that box.
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[boxRow + r][boxCol + c] == num) return false;  // already in this box
        }
    }

    return true;  // no conflicts found
}
