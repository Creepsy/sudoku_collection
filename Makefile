bDir = build/
sDir = src/
lDir = src/lib/
args = -O3 -g

test: $(sDir)test.cpp $(bDir)standard_sudoku.o
	g++ $(sDir)test.cpp -o test $(bDir)standard_sudoku.o $(args)

$(bDir)standard_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)standard_sudoku.cpp $(sDir)standard_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)standard_sudoku.cpp -o $(bDir)standard_sudoku.o $(args)