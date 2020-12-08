#include "standard_sudoku.h"

#include <iostream>

standard_sudoku::standard_sudoku()
 : sudoku_base<unsigned short>{{1, 2, 3, 4, 5, 6, 7, 8, 9}} {
}

standard_sudoku::~standard_sudoku() {
}

//private

bool standard_sudoku::is_valid(unsigned short value, position cell) {
    return true;
}