#include <iostream>

#include "lib/cell_base.h"

int main() {
    cell_base<int> c = { 10, {1} };

    std::cout << c.in_block() << ", " << c.in_row() << std::endl;
    return 0;
}