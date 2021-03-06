bDir = build/
sDir = src/
lDir = src/lib/
args = -O3

test: $(sDir)test.cpp $(bDir)standard_sudoku.o $(bDir)donut_sudoku.o $(bDir)overlapping_sudoku.o $(bDir)star_sudoku.o $(bDir)color_sudoku.o $(bDir)color_blocks_sudoku.o $(bDir)cross_sudoku.o
	g++ $(sDir)test.cpp -o test $(bDir)standard_sudoku.o $(args) $(bDir)donut_sudoku.o $(bDir)overlapping_sudoku.o $(bDir)star_sudoku.o $(bDir)color_sudoku.o $(bDir)color_blocks_sudoku.o $(bDir)cross_sudoku.o

$(bDir)standard_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)standard_sudoku.cpp $(sDir)standard_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)standard_sudoku.cpp -o $(bDir)standard_sudoku.o $(args)

$(bDir)donut_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)donut_sudoku.cpp $(sDir)donut_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)donut_sudoku.cpp -o $(bDir)donut_sudoku.o $(args)

$(bDir)overlapping_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)overlapping_sudoku.cpp $(sDir)overlapping_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)overlapping_sudoku.cpp -o $(bDir)overlapping_sudoku.o $(args)

$(bDir)star_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)star_sudoku.cpp $(sDir)star_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)star_sudoku.cpp -o $(bDir)star_sudoku.o $(args)

$(bDir)color_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)color_sudoku.cpp $(sDir)color_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)color_sudoku.cpp -o $(bDir)color_sudoku.o $(args)

$(bDir)color_blocks_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)color_blocks_sudoku.cpp $(sDir)color_blocks_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)color_blocks_sudoku.cpp -o $(bDir)color_blocks_sudoku.o $(args)

$(bDir)cross_sudoku.o: $(lDir)sudoku_base.h $(lDir)sudoku_base.cpp $(sDir)cross_sudoku.cpp $(sDir)cross_sudoku.h $(lDir)cell_base.h $(lDir)block_base.h
	g++ -c $(sDir)cross_sudoku.cpp -o $(bDir)cross_sudoku.o $(args)
