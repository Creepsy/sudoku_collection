bDir = build/
sDir = src/
lDir = src/lib/

test: $(sDir)test.cpp $(bDir)sudoku_base.o
	g++ $(sDir)test.cpp -o test $(bDir)sudoku_base.o

$(bDir)sudoku_base.o: $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(lDir)sudoku_base.cpp -o $(bDir)sudoku_base.o