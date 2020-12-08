bDir = build/
sDir = src/
lDir = src/lib/

test: $(sDir)test.cpp $(bDir)sudoku_base.o
	g++ $(sDir)test.cpp -o test $(bDir)sudoku_base.o

$(bDir)row_base.o: $(lDir)cell_base.h $(lDir)row_base.cpp $(lDir)row_base.h
	g++ -c $(lDir)row_base.cpp -o $(bDir)row_base.o

$(bDir)block_base.o: $(lDir)cell_base.h $(lDir)block_base.cpp $(lDir)block_base.h
	g++ -c $(lDir)block_base.cpp -o $(bDir)block_base.o

$(bDir)sudoku_base.o: $(lDir)cell_base.h $(bDir)row_base.o $(bDir)block_base.o
	g++ -c $(lDir)sudoku_base.cpp -o $(bDir)sudoku_base.o