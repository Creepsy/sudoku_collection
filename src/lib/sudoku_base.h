#pragma once

#include <vector>
#include <map>

#include "block_base.h"

template<class value_type>
class sudoku_base {
    private:
        std::vector<value_type> value_possibilities;
        std::vector<block_base<value_type>> blocks;
        std::map<size_t, std::map<size_t, cell_base<value_type>>> grid;

        bool has_cell(const position pos);
        bool add_cell(const position pos);
        bool add_block(const std::vector<position>& cells);

        virtual bool is_valid(value_type value, const position cell) = 0;
        std::vector<value_type> get_possibilities(const position cell);
    public:
        sudoku_base(const std::vector<value_type>& value_possibilities);
        virtual ~sudoku_base();
};