#include "color_sudoku.h"

#include <iostream>

color_sudoku::color_sudoku(const size_t size, const size_t difficulty, const size_t remove_tries)
 : sudoku_base<unsigned short>{color_sudoku::generate_possibilities(size)}, size(size) {
    this->initialize_grid();
    this->solve();
    
    this->add_color_blocks();

    this->generate_unsolved(difficulty, remove_tries);
}

color_sudoku::~color_sudoku() {
}

//private

void color_sudoku::initialize_grid() {
    for(int x = 0; x < this->size * this->size; x++) {
        for(int y = 0; y < this->size * this->size; y++) {
            this->add_cell(position{ x, y });
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

void color_sudoku::add_color_blocks() {
    std::vector<std::vector<position>> numbers;
    numbers.reserve(this->size * this->size);


    for(int n = 1; n <= this->size * this->size; n++) {
        std::vector<position> nums;
        nums.reserve(this->size * this->size);
        for(const std::pair<const size_t, std::unordered_map<size_t, cell_base<unsigned short>>>& column : this->grid) {
            for(const std::pair<const size_t, cell_base<unsigned short>>& cell : column.second) {
                if(cell.second.value == n) {
                    nums.push_back(cell.second.pos);
                }
            }
        }
        numbers.push_back(nums);
    }

    for(int b = 0; b < this->size * this->size; b++) {
        std::vector<position> block;
        block.reserve(this->size * this->size);
        for(int p = 0; p < this->size * this->size; p++) {
            int i = rand() % numbers[p].size();
            block.push_back(numbers[p][i]);
            numbers[p].erase(numbers[p].begin() + i);
        }

        this->add_block(block);
    }
}

//static
std::vector<unsigned short> color_sudoku::generate_possibilities(const size_t size) {
    std::vector<unsigned short> possibilities;
    possibilities.resize(size * size);

    for(int p = 1; p <= size * size; p++) {
        possibilities.push_back(p);
    }

    return possibilities;
}

