#pragma once

#include "lib/sudoku_base.cpp"

class standard_sudoku : public sudoku_base<unsigned short> {
    private:
        bool is_valid(unsigned short value, position cell) override;
    public:
        standard_sudoku();
        ~standard_sudoku();
};
