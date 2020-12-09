#pragma once

#include <vector>


struct position {
    int x;
    int y;

    inline bool operator==(const position& other) const {
        return this->x == other.x && this->y == other.y;
    }
};

template<class value_type>
struct cell_base {
    value_type value;
    position pos;
    std::vector<size_t> blocks;
};