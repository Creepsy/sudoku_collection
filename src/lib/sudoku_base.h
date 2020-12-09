#pragma once

#include <vector>
#include <unordered_map>

#include "block_base.h"

template<class value_type>
struct path_node {
    position pos;
    std::vector<value_type> tested_values;
};

template<class value_type>
class sudoku_base {
    private:
        typedef bool (*cell_criteria)(const cell_base<value_type>& cell);
        std::vector<position> get_all_cells_matching_criteria(cell_criteria cirteria);

        size_t cell_with_lowest_possibilities(const std::vector<position>& cells);

        int get_solution_type();
    protected:
        const std::vector<value_type> value_possibilities;
        std::vector<block_base> blocks;
        std::unordered_map<size_t, std::unordered_map<size_t, cell_base<value_type>>> grid;

        bool has_cell(const position pos);
        bool add_cell(const position pos);
        bool add_block(const std::vector<position>& cells);

        bool does_block_contain_value(const block_base& block, value_type value);
        bool does_block_contain_cell(const block_base& block, position cell);

        virtual bool is_valid(value_type value, const position cell);
        virtual void initialize_grid() = 0;
        virtual std::vector<value_type> get_possibilities(const position cell);
        virtual void fill_grid();
    public:
        sudoku_base(const std::vector<value_type>& value_possibilities);
        bool generate_unsolved(const size_t to_remove, const size_t max_tries);
        bool solve();
        virtual ~sudoku_base();
};