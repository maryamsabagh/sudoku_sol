sudoku: main.cpp board.cpp rules.cpp solver.cpp generator.cpp board.h rules.h solver.h generator.h
	g++ -o sudoku main.cpp board.cpp rules.cpp solver.cpp generator.cpp

clean:
	rm -f sudoku
