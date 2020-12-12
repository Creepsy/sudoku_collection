#include <iostream>

#include "standard_sudoku.h"
#include "donut_sudoku.h"
#include "overlapping_sudoku.h"
#include "star_sudoku.h"

const int px_start = 0;
const int px_end = 13;

const int py_start = -5;
const int py_end = 9;

int main() {
    srand(time(nullptr));
    /*overlapping_sudoku sudoku{ 3, 250, 10, std::vector<position>{
        position{ 0, 0 },
        position{ 6, 6 },
        position{ 12, 0 },
        position{ 0, 12 },
        position{ 12, 12 }
    } };*/
    star_sudoku sudoku{ 50, 5 };
    std::unordered_map<size_t, std::unordered_map<size_t, cell_base<unsigned short>>> grid = sudoku.get_grid();

    for(int y = py_start; y < py_end; y++) {
        for(int x = px_start; x < px_end; x++) {
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

    for(int y = py_start; y < py_end; y++) {
        for(int x = px_start; x < px_end; x++) {
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