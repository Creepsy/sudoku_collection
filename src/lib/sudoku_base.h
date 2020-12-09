#pragma once

#include <vector>
#include <map>

#include "block_base.h"

template<class value_type>
struct path_node {
    position pos;
    std::vector<value_type> tested_values;
};

template<class value_type>
class sudoku_base {
    private:
        std::vector<position> get_all_cells();
        size_t cell_with_lowest_possibilities(const std::vector<position>& cells);
    protected:
        const std::vector<value_type> value_possibilities;
        std::vector<block_base> blocks;
        std::map<size_t, std::map<size_t, cell_base<value_type>>> grid;

        bool has_cell(const position pos);
        bool add_cell(const position pos);
        bool add_block(const std::vector<position>& cells);

        bool does_block_contain_value(const block_base& block, value_type value);
        bool does_block_contain_cell(const block_base& block, position cell);

        virtual bool is_valid(value_type value, const position cell) = 0;
        virtual void initialize_grid() = 0;
        std::vector<value_type> get_possibilities(const position cell);
        void fill_grid();
    public:
        sudoku_base(const std::vector<value_type>& value_possibilities);
        virtual ~sudoku_base();
};