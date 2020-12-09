#pragma once

#include "lib/sudoku_base.cpp"

class standard_sudoku : public sudoku_base<unsigned short> {
    private:
        void initialize_grid() override;
    public:
        standard_sudoku();
        ~standard_sudoku();
};
