#include "standard_sudoku.h"

#include <iostream>

standard_sudoku::standard_sudoku(const size_t size, const size_t difficulty, const size_t remove_tries)
 : sudoku_base<unsigned short>{standard_sudoku::generate_possibilities(size)}, size(size) {
    this->initialize_grid();
    this->solve();

    std::cout << "Success: " << this->generate_unsolved(difficulty, remove_tries) << std::endl;

    for(const std::pair<const size_t, std::unordered_map<size_t, cell_base<unsigned short>>>& column : this->grid) {
        for(const std::pair<const size_t, cell_base<unsigned short>>& cell : column.second) {
            std::cout << cell.second.value << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    this->solve();
    std::cout << std::endl;

    for(const std::pair<const size_t, std::unordered_map<size_t, cell_base<unsigned short>>>& column : this->grid) {
        for(const std::pair<const size_t, cell_base<unsigned short>>& cell : column.second) {
            std::cout << cell.second.value << " ";
        }
        std::cout << std::endl;
    }
}

standard_sudoku::~standard_sudoku() {
}

//private

void standard_sudoku::initialize_grid() {
    for(int x = 0; x < this->size; x++) {
        for(int y = 0; y < this->size; y++) {
            this->register_block(x * this->size, y * this->size);
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

void standard_sudoku::register_block(const int x, const int y) {
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
std::vector<unsigned short> standard_sudoku::generate_possibilities(const size_t size) {
    std::vector<unsigned short> possibilities;
    possibilities.resize(size * size);

    for(int p = 1; p <= size * size; p++) {
        possibilities.push_back(p);
    }

    return possibilities;
}