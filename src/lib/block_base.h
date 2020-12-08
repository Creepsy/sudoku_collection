#pragma once

#include <vector>

#include "cell_base.h"

template<class value_type>
struct block_base {
    std::vector<cell_base<value_type>*> members;
};
