#include <iostream>

#include "standard_sudoku.h"
#include "donut_sudoku.h"
#include "overlapping_sudoku.h"

const int print_size = 21;

int main() {
    srand(time(nullptr));
    overlapping_sudoku sudoku{3, 200, 50, std::vector<position>{
        position{ 0, 0 },
        position{ 6, 6 },
        position{ 12, 0 },
        position{ 0, 12 },
        position{ 12, 12 }
    }};
    std::unordered_map<size_t, std::unordered_map<size_t, cell_base<unsigned short>>> grid = sudoku.get_grid();

    for(int x = 0; x < print_size; x++) {
        for(int y = 0; y < print_size; y++) {
            try{
                std::cout << grid.at(x).at(y).value << " ";
            } catch(...) {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;
    sudoku.solve();
    grid = sudoku.get_grid();

    for(int x = 0; x < print_size; x++) {
        for(int y = 0; y < print_size; y++) {
            try{
                std::cout << grid.at(x).at(y).value << " ";
            } catch(...) {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}