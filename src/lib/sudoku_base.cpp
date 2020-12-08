#include "sudoku_base.h"

#include <stdexcept>

template<class value_type>
sudoku_base<value_type>::sudoku_base(const std::vector<value_type>& value_possibilities)
 : value_possibilities(value_possibilities) {
}

template<class value_type>
sudoku_base<value_type>::~sudoku_base() {
}

//protected

template<class value_type>
std::vector<value_type> sudoku_base<value_type>::get_possibilities(position cell) {
    std::vector<value_type> possibilites;
    for(const value_type& possibility : this->value_possibilities) {
        if(this->is_valid(possibility, cell)) {
            possibilites.push_back(possibility);
        }
    }
    return possibilites;
}

template<class value_type>
bool sudoku_base<value_type>::add_cell(const position pos) {
    if(this->has_cell(pos)) return false;
    this->grid[pos.x][pos.y] = cell_base<value_type>{ value_type{}, pos };

    return true;
}

template<class value_type>
bool sudoku_base<value_type>::add_block(const std::vector<position>& cells) {
    for(const position& pos : cells) {
        if(!this->has_cell(pos)) return false;
    }

    this->blocks.push_back(block_base<value_type>{ cells });

    for(const position& pos : cells) {
        this->grid[pos.x][pos.y].blocks.push_back(this->blocks.size() - 1);
    }

    return true;
}

template<class value_type>
bool sudoku_base<value_type>::has_cell(const position pos) {
    try {
        this->grid.at(pos.x).at(pos.y);
        return true;
    } catch(std::out_of_range& e) {
        return false;
    }
}