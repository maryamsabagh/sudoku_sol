// board.cpp
// Everything to do with the board itself: saving it as a picture.

#include <fstream>   // for ifstream (reading a file)
#include <string>
#include "board.h"

using namespace std;

// An SVG, picture of the puzzle, a web browser reads it and draws it.
void saveSvg(int board[SIZE][SIZE], int puzzle[SIZE][SIZE], string filename) {
    const int CELL = 50;    
    const int MARGIN = 10;  
    const int TOTAL = MARGIN * 2 + CELL * SIZE;  

    ofstream file(filename);  // opens the file for writing

    // The opening tag of the picture
    file << "<svg xmlns='http://www.w3.org/2000/svg' width='" << TOTAL
         << "' height='" << TOTAL << "'>" << endl;
    file << "<rect width='" << TOTAL << "' height='" << TOTAL << "' fill='white'/>" << endl;

    // Draw the grid lines: 10 going down and 10 going across.
    // Every 3rd line is thick, which makes the 3x3 boxes stand out.
    int start = MARGIN;
    int end = MARGIN + SIZE * CELL;
    for (int i = 0; i <= SIZE; i++) {
        int thickness = 1;
        if (i % 3 == 0) {
            thickness = 3;
        }
        int position = MARGIN + i * CELL;

        // a line going down
        file << "<line x1='" << position << "' y1='" << start
             << "' x2='" << position << "' y2='" << end
             << "' stroke='black' stroke-width='" << thickness << "'/>" << endl;
        // a line going across
        file << "<line x1='" << start << "' y1='" << position
             << "' x2='" << end << "' y2='" << position
             << "' stroke='black' stroke-width='" << thickness << "'/>" << endl;
    }

    // Write each number in the middle of its square. Empty squares get nothing.
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] != 0) {
                // Numbers from the original puzzle are black.
                // Numbers the solver filled in (empty in the puzzle) are blue.
                string color = "black";
                if (puzzle[row][col] == 0) {
                    color = "blue";
                }

                int x = MARGIN + col * CELL + CELL / 2;  // middle of the square, left to right
                int y = MARGIN + row * CELL + 36;        // a bit below the top, so the number looks centered
                file << "<text x='" << x << "' y='" << y
                     << "' fill='" << color
                     << "' text-anchor='middle' font-size='32' font-family='sans-serif'>"
                     << board[row][col] << "</text>" << endl;
            }
        }
    }

    file << "</svg>" << endl;  // the closing tag
}
