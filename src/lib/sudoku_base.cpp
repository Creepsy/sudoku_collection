#include "sudoku_base.h"

template<class value_type>
sudoku_base<value_type>::sudoku_base() {
}

template<class value_type>
sudoku_base<value_type>::~sudoku_base() {
    for(std::pair<const size_t, std::map<size_t, cell_base<value_type>*>>& column : this->grid) {
        for(std::pair<const size_t, cell_base<value_type>*>& cell : column.second) {
            if(cell.second) {
                delete cell.second;
                cell.second = nullptr;
            }
        }
    }
}