#pragma once

#include <vector>


struct position {
    int x;
    int y;
};

template<class value_type>
struct cell_base {
    value_type value;
    position pos;
    std::vector<size_t> blocks;

    bool in_block() {
        return this->blocks.size() != 0;
    }
};