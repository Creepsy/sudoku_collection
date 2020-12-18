#pragma once

#include "lib/sudoku_base.cpp"

class cross_sudoku : public sudoku_base<unsigned short> {
    private:
        const size_t size;
        void initialize_grid() override;
        void register_block(const int x, const int y);

        static std::vector<unsigned short> generate_possibilities(const size_t size);
    public:
        cross_sudoku(const size_t size, const size_t difficulty, const size_t remove_tries);
        ~cross_sudoku();
};
