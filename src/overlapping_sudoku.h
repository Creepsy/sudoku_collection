#pragma once

#include "lib/sudoku_base.cpp"

class overlapping_sudoku : public sudoku_base<unsigned short> {
    private:
        const size_t size;
        const std::vector<position> sudokus;
        void initialize_grid() override;
        void register_block(const int x, const int y);
        void register_sudoku(const int sudoku_x, const int sudoku_y);

        static std::vector<unsigned short> generate_possibilities(const size_t size);
    public:
        overlapping_sudoku(const size_t size, const size_t difficulty, const size_t remove_tries, const std::vector<position>& sudokus);
        ~overlapping_sudoku();
};
