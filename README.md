# 9x9 Sudoku Generator and Solver 

A short C++ program that makes a new random Sudoku puzzle, solves it, and saves
both as pictures. It is split into a few small files, each with one job, and is
written to be easy to read, not fast.

## Run it

```bash
make
./sudoku
open puzzle.svg
open solution.svg
```

`make` builds the program (it runs `g++` on all the `.cpp` files). `./sudoku`
makes a new puzzle, solves it, and saves two pictures. Nothing is printed to
the terminal except a message saying the pictures were saved.

In `solution.svg`, the numbers that were in the original puzzle are black and
the numbers the solver filled in are blue.

The number of clues the puzzle starts with is the `CLUES` variable near the top
of `main.cpp`: more clues is an easier puzzle, fewer is harder. Keep it at 25 or
higher; below that the generator gets slow.

Running it twice in the same second gives the same puzzle, because the random
numbers are seeded from the clock.

## The files

Each job has a `.h` file (a header: it lists what the functions are called) and
a `.cpp` file (the code that makes them work).

| Files | Job | Functions |
|---|---|---|
| `board.h` / `.cpp` | The board: its size, saving it as a picture | `SIZE`, `saveSvg` |
| `rules.h` / `.cpp` | The rules of Sudoku | `isSafe` |
| `solver.h` / `.cpp` | Solving the puzzle, and counting how many solutions it has | `solve`, `countSolutions` |
| `generator.h` / `.cpp` | Making a new random puzzle | `generatePuzzle` |
| `main.cpp` | Runs the steps in order | `main` |

Reading order for learning the code: `board.h`, `rules.cpp`, `solver.cpp`,
`generator.cpp`, `board.cpp`, then `main.cpp`.

## Ideas to explain it out loud

- The board is a 2D array: `board[row][col]`, with `0` meaning empty.
- `main` keeps two boards: `puzzle` (never changed) and `board` (a copy that
  the solver fills in). Comparing them tells `saveSvg` which numbers are new.
  Arrays passed to a function are not copied, so functions change the original.
- `solve` is *recursive*: it calls itself. Each call fills in one more square.
- Returning `false` means "this path is a dead end", which makes the previous
  call undo its guess and try something else. This is called *backtracking*.
- `generatePuzzle` starts from a full solved board and removes numbers. After
  each removal it calls `countSolutions`; if the puzzle could now be solved in
  more than one way, the number is put back. That keeps every puzzle to
  exactly one answer.
- `saveSvg` draws every 3rd grid line thicker (`i % 3 == 0`). That is how the
  3x3 boxes appear. A number is blue when it is empty in `puzzle`.
