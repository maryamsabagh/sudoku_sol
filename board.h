// board.h
// Everything to do with the board itself: its size and saving it as a picture.
//
// The board is a 2D array: int board[SIZE][SIZE]
// board[row][col] holds a number from 1 to 9, or 0 if that square is empty.
// Rows and columns count from 0 to 8.

#pragma once  // stops this file from being included twice by accident
#include <string>

const int SIZE = 9;  // 9 rows by 9 columns

// Saves the board as a picture (an SVG file) that you can open in a browser.
// "puzzle" is the original puzzle. Numbers that were already in the puzzle are
// drawn in black. Numbers that are only in "board" (the ones the solver filled
// in) are drawn in blue.
void saveSvg(int board[SIZE][SIZE], int puzzle[SIZE][SIZE], std::string filename);
