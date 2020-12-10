#include <iostream>

#include "standard_sudoku.h"
#include "donut_sudoku.h"

const int print_size = 9;

int main() {
    srand(time(nullptr));
    donut_sudoku sudoku{3, 150, 50};
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