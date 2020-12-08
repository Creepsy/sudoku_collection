#include "standard_sudoku.h"

#include <iostream>

standard_sudoku::standard_sudoku()
 : sudoku_base<unsigned short>{{1, 2, 3, 4, 5, 6, 7, 8, 9}} {
    this->initialize_grid();
    this->fill_grid();

    for(const std::pair<const size_t, std::map<size_t, cell_base<unsigned short>>>& column : this->grid) {
        for(const std::pair<const size_t, cell_base<unsigned short>>& cell : column.second) {
            std::cout << cell.second.value << " ";
        }
        std::cout << std::endl;
    }
}

standard_sudoku::~standard_sudoku() {
}

//private

bool standard_sudoku::is_valid(unsigned short value, position cell) {
    return true;
}

void standard_sudoku::initialize_grid() {
    for(int x = 0; x < 9; x++) {
        for(int y = 0; y < 9; y++) {
            this->add_cell(position{ x, y });
        }
    }
    for(int x = 0; x < 9; x++) {
        this->add_block(std::vector<position>{ 
            position{ x, 0 },
            position{ x, 1 },
            position{ x, 2 },
            position{ x, 3 },
            position{ x, 4 },
            position{ x, 5 },
            position{ x, 6 },
            position{ x, 7 },
            position{ x, 8 },
         });
    }
    for(int y = 0; y < 9; y++) {
        this->add_block(std::vector<position>{ 
            position{ 0, y },
            position{ 1, y },
            position{ 2, y },
            position{ 3, y },
            position{ 4, y },
            position{ 5, y },
            position{ 6, y },
            position{ 7, y },
            position{ 8, y },
         });
    }

    //TODO: add blocks
}