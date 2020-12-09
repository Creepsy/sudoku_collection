#include "sudoku_base.h"

#include <stdexcept>
#include <random>
#include <iostream>
#include <algorithm>

//helper functions
template<class t>
std::vector<t> remove_elements_from_base(const std::vector<t>& base, const std::vector<t>& to_remove);

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

    this->blocks.push_back(block_base{ cells });

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

template<class value_type>
void sudoku_base<value_type>::fill_grid() {
    std::vector<position> cells_to_fill = this->get_all_cells();
    std::vector<path_node<value_type>> path;

    while(cells_to_fill.size() > 0) {
        size_t cell_i = this->cell_with_lowest_possibilities(cells_to_fill);
        std::vector<value_type> possibilities = this->get_possibilities(cells_to_fill[cell_i]);

        if(possibilities.size() == 0) {
            this->grid[path.back().pos.x][path.back().pos.y].value = value_type{};
            while(remove_elements_from_base(this->get_possibilities(path.back().pos), path.back().tested_values).size() == 0) {
                cells_to_fill.push_back(path.back().pos);
                path.pop_back();
                this->grid[path.back().pos.x][path.back().pos.y].value = value_type{};
            }
            if(path.size() == 0) throw std::logic_error("Couldn't fill the grid!");

            possibilities = remove_elements_from_base(this->get_possibilities(path.back().pos), path.back().tested_values);  

            value_type to_insert = possibilities[rand() % possibilities.size()];
            this->grid[path.back().pos.x][path.back().pos.y].value = to_insert;
            
            path.back().tested_values.push_back(to_insert);
        } else {
            value_type to_insert = possibilities[rand() % possibilities.size()];
            this->grid[cells_to_fill[cell_i].x][cells_to_fill[cell_i].y].value = to_insert;

            path.push_back(path_node<value_type>{ cells_to_fill[cell_i], {to_insert} });
            cells_to_fill.erase(cells_to_fill.begin() + cell_i);
        }
    }
}

template<class value_type>
bool sudoku_base<value_type>::does_block_contain_value(const block_base& block, value_type value) {
    for(const position& member : block.members) {
        if(this->grid[member.x][member.y].value == value) return true;
    }
    return false;
}

template<class value_type>
bool sudoku_base<value_type>::does_block_contain_cell(const block_base& block, position cell) {
    for(const position& member : block.members) {
        if(member == cell) return true;
    }
    return false;
}

//private

template<class value_type>
std::vector<position> sudoku_base<value_type>::get_all_cells() {
    std::vector<position> cells;
    for(const std::pair<const size_t, std::unordered_map<size_t, cell_base<value_type>>>& column : this->grid) {
        for(const std::pair<const size_t, cell_base<value_type>>& cell : column.second) {
            cells.push_back(cell.second.pos);
        }
    }

    return cells;
}

template<class value_type>
size_t sudoku_base<value_type>::cell_with_lowest_possibilities(const std::vector<position>& cells) {
    size_t lowest_i = 0;
    size_t lowest_possib = get_possibilities(cells[0]).size();

    for(int i = 1; i < cells.size(); i++) {
        size_t curr_possib = get_possibilities(cells[i]).size();
        if(curr_possib < lowest_possib) {
            lowest_possib = curr_possib;
            lowest_i = i;
        }
        if(lowest_possib == 0) break;
    }

    return lowest_i;
}

//helper functions
template<class t>
std::vector<t> remove_elements_from_base(const std::vector<t>& base, const std::vector<t>& to_remove) {
    std::vector<t> processed;
    for(const t& val : base) {
        if(std::find(to_remove.begin(), to_remove.end(), val) == to_remove.end()) {
            processed.push_back(val);
        }
    }
    return processed;
}