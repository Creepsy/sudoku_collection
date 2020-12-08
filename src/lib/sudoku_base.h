#pragma once

#include <vector>
#include <map>

#include "block_base.h"

template<class value_type>
class sudoku_base {
    private:
        std::vector<block_base<value_type>*> blocks;
        std::map<size_t, std::map<size_t, cell_base<value_type>*>> grid;
    public:
        sudoku_base();
        ~sudoku_base();
};