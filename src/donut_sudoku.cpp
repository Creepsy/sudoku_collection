#include "donut_sudoku.h"

#include <iostream>

donut_sudoku::donut_sudoku(const size_t size, const size_t difficulty, const size_t remove_tries)
 : sudoku_base<unsigned short>{donut_sudoku::generate_possibilities(size)}, size(size) {
    this->initialize_grid();
    this->solve();

    this->generate_unsolved(difficulty, remove_tries);
}

donut_sudoku::~donut_sudoku() {
}

//private

void donut_sudoku::initialize_grid() {
    for(int x = 0; x < this->size; x++) {
        for(int y = 0; y < this->size; y++) {
            if(x == 0 || x == this->size - 1 || y == 0 || y == this->size - 1) {
                this->register_block(x * this->size, y * this->size);
            }
        }
    }

    for(int x = 0; x < this->size * this->size; x++) {
        std::vector<position> row_indices;
        row_indices.reserve(this->size * this->size);
        for(int y = 0; y < this->size * this->size; y++) {
            row_indices.push_back(position{ x, y });
        }
        this->add_block(row_indices);
    }

    for(int y = 0; y < this->size * this->size; y++) {
        std::vector<position> row_indices;
        row_indices.reserve(this->size * this->size);
        for(int x = 0; x < this->size * this->size; x++) {
            row_indices.push_back(position{ x, y });
        }
        this->add_block(row_indices);
    }
}

void donut_sudoku::register_block(const int x, const int y) {
    std::vector<position> block_indices;
    block_indices.reserve(this->size * this->size);
    for(int x_off = 0; x_off < this->size; x_off++) {
        for(int y_off = 0; y_off < this->size; y_off++) {
            position cell_pos = position{ x + x_off, y + y_off };
            this->add_cell(cell_pos);
            block_indices.push_back(cell_pos);
        }
    }
    this->add_block(block_indices);
}

//static
std::vector<unsigned short> donut_sudoku::generate_possibilities(const size_t size) {
    std::vector<unsigned short> possibilities;
    possibilities.resize(size * size);

    for(int p = 1; p <= size * size; p++) {
        possibilities.push_back(p);
    }

    return possibilities;
}