#pragma once

#include "lib/sudoku_base.cpp"

class color_blocks_sudoku : public sudoku_base<unsigned short> {
    private:
        const size_t size;
        void initialize_grid() override;
        void register_block(const int x, const int y);
        void add_color_blocks();

        static std::vector<unsigned short> generate_possibilities(const size_t size);
    public:
        color_blocks_sudoku(const size_t size, const size_t difficulty, const size_t remove_tries);
        ~color_blocks_sudoku();
};
