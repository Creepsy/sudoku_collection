bDir = build/
sDir = src/
lDir = src/lib/

test: $(sDir)test.cpp $(lDir)sudoku_base.h
	g++ $(sDir)test.cpp -o test