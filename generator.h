// generator.h
// Makes a new random puzzle.

#pragma once
#include "board.h"

// Fills the board with a new random puzzle that has "clues" numbers filled in.
void generatePuzzle(int board[SIZE][SIZE], int clues);
