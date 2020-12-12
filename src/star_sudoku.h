#pragma once

#include "lib/sudoku_base.cpp"

class star_sudoku : public sudoku_base<unsigned short> {
    private:
        void initialize_grid() override;
    public:
        star_sudoku(const size_t difficulty, const size_t remove_tries);
        ~star_sudoku();
};
