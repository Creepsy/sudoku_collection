bDir = build/
sDir = src/
lDir = src/lib/
args = -O3

test: $(sDir)test.cpp $(bDir)standard_sudoku.o $(bDir)donut_sudoku.o
	g++ $(sDir)test.cpp -o test $(bDir)standard_sudoku.o $(args) $(bDir)donut_sudoku.o

$(bDir)standard_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)standard_sudoku.cpp $(sDir)standard_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)standard_sudoku.cpp -o $(bDir)standard_sudoku.o $(args)

$(bDir)donut_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)donut_sudoku.cpp $(sDir)donut_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)donut_sudoku.cpp -o $(bDir)donut_sudoku.o $(args)