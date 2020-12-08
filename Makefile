bDir = build/
sDir = src/
lDir = src/lib/

test: $(sDir)test.cpp $(bDir)standard_sudoku.o
	g++ $(sDir)test.cpp -o test $(bDir)standard_sudoku.o

$(bDir)standard_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)standard_sudoku.cpp $(sDir)standard_sudoku.h
	g++ -c $(sDir)standard_sudoku.cpp -o $(bDir)standard_sudoku.o