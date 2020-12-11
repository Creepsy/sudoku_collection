#include "overlapping_sudoku.h"

#include <iostream>

overlapping_sudoku::overlapping_sudoku(const size_t size, const size_t difficulty, const size_t remove_tries, const std::vector<position>& sudokus)
 : sudoku_base<unsigned short>{overlapping_sudoku::generate_possibilities(size)}, size(size), sudokus(sudokus) {
    this->initialize_grid();
    this->solve();

    this->generate_unsolved(difficulty, remove_tries);
}

overlapping_sudoku::~overlapping_sudoku() {
}

//private

void overlapping_sudoku::initialize_grid() {
    for(const position& sudoku : this->sudokus) {
        this->register_sudoku(sudoku.x, sudoku.y);
    }
}

void overlapping_sudoku::register_block(const int x, const int y) {
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

void overlapping_sudoku::register_sudoku(const int sudoku_x, const int sudoku_y) {
    for(int x = 0; x < this->size; x++) {
        for(int y = 0; y < this->size; y++) {
            this->register_block(sudoku_x + x * this->size, sudoku_y + y * this->size);
        }
    }

    for(int x = 0; x < this->size * this->size; x++) {
        std::vector<position> row_indices;
        row_indices.reserve(this->size * this->size);
        for(int y = 0; y < this->size * this->size; y++) {
            row_indices.push_back(position{ sudoku_x + x, sudoku_y + y });
        }
        this->add_block(row_indices);
    }

    for(int y = 0; y < this->size * this->size; y++) {
        std::vector<position> row_indices;
        row_indices.reserve(this->size * this->size);
        for(int x = 0; x < this->size * this->size; x++) {
            row_indices.push_back(position{ sudoku_x + x, sudoku_y + y });
        }
        this->add_block(row_indices);
    }
}

//static
std::vector<unsigned short> overlapping_sudoku::generate_possibilities(const size_t size) {
    std::vector<unsigned short> possibilities;
    possibilities.resize(size * size);

    for(int p = 1; p <= size * size; p++) {
        possibilities.push_back(p);
    }

    return possibilities;
}