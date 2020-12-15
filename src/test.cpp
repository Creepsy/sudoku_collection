#include <iostream>
#include <string>

#include "standard_sudoku.h"
#include "donut_sudoku.h"
#include "overlapping_sudoku.h"
#include "star_sudoku.h"
#include "color_sudoku.h"

const int px_start = 0;
const int px_end = 9;

const int py_start = 0;
const int py_end = 9;

template<class typ>
std::string as_python_dictionary(const std::unordered_map<size_t, std::unordered_map<size_t, cell_base<typ>>>& grid);
std::string as_python_list(const std::vector<block_base>& blocks);

int main() {
    srand(time(nullptr));
    /*overlapping_sudoku sudoku{ 3, 250, 10, std::vector<position>{
        position{ 0, 0 },
        position{ 6, 6 },
        position{ 12, 0 },
        position{ 0, 12 },
        position{ 12, 12 }
    } };*/
    color_sudoku sudoku{ 9, 65, 5 };
    std::unordered_map<size_t, std::unordered_map<size_t, cell_base<unsigned short>>> grid = sudoku.get_grid();

    std::cout << as_python_list(sudoku.get_blocks()) << std::endl;
    std::cout << std::endl;

    std::cout << as_python_dictionary(grid) << std::endl;
    std::cout << std::endl;

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

    std::cout << as_python_dictionary(grid) << std::endl;
    std::cout << std::endl;

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

template<class typ>
std::string as_python_dictionary(const std::unordered_map<size_t, std::unordered_map<size_t, cell_base<typ>>>& grid) {
    std::string dictionary_str = "sudoku = {\n";
    for(const std::pair<const size_t, std::unordered_map<size_t, cell_base<typ>>>& column : grid) {
        for(const std::pair<const size_t, cell_base<typ>>& cell : column.second) {
            dictionary_str += "(" + std::to_string(column.first) + ", " + std::to_string(cell.first) + ") : " + std::to_string(cell.second.value) + ", ";
        }
        dictionary_str += "\n";
    }

    return dictionary_str + "}";
}

std::string as_python_list(const std::vector<block_base>& blocks) {
    std::string list_str = "blocks = [\n";

    for(const block_base& block : blocks) {
        list_str += "[";

        for(const position& member : block.members) {
            list_str += "(" + std::to_string(member.x) + ", " + std::to_string(member.y) + "),";
        }

        list_str += "],\n";
    }

    return list_str + "]";
}