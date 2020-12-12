#include "star_sudoku.h"

#include <iostream>

star_sudoku::star_sudoku(const size_t difficulty, const size_t remove_tries)
 : sudoku_base<unsigned short>{std::vector<unsigned short>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 } } {
    this->initialize_grid();
    this->solve();

    this->generate_unsolved(difficulty, remove_tries);
}

star_sudoku::~star_sudoku() {
}

//private

void star_sudoku::initialize_grid() {
    this->add_cell(position{ 0, 0 });
    this->add_cell(position{ 2, 0 });
    this->add_cell(position{ 4, 0 });
    this->add_cell(position{ 1, 1 });
    this->add_cell(position{ 3, 1 });
    this->add_cell(position{ 1, 2 });
    this->add_cell(position{ 3, 2 });
    this->add_cell(position{ 2, 3 });
    this->add_cell(position{ 2, 4 });

    this->add_cell(position{ 4, 3 });
    this->add_cell(position{ 4, 4 });
    this->add_cell(position{ 3, 5 });
    this->add_cell(position{ 5, 5 });
    this->add_cell(position{ 3, 6 });
    this->add_cell(position{ 5, 6 });
    this->add_cell(position{ 2, 7 });
    this->add_cell(position{ 4, 7 });
    this->add_cell(position{ 6, 7 });

    this->add_cell(position{ 6, 4 });
    this->add_cell(position{ 8, 4 });
    this->add_cell(position{ 10, 4 });
    this->add_cell(position{ 7, 5 });
    this->add_cell(position{ 9, 5 });
    this->add_cell(position{ 7, 6 });
    this->add_cell(position{ 9, 6 });
    this->add_cell(position{ 8, 7 });
    this->add_cell(position{ 8, 8 });

    this->add_cell(position{ 10, -1 });
    this->add_cell(position{ 10, 0 });
    this->add_cell(position{ 9, 1 });
    this->add_cell(position{ 11, 1 });
    this->add_cell(position{ 9, 2 });
    this->add_cell(position{ 11, 2 });
    this->add_cell(position{ 8, 3 });
    this->add_cell(position{ 10, 3 });
    this->add_cell(position{ 12, 3 });

    this->add_cell(position{ 8, 0 });
    this->add_cell(position{ 8, -1 });
    this->add_cell(position{ 7, -2 });
    this->add_cell(position{ 9, -2 });
    this->add_cell(position{ 7, -3 });
    this->add_cell(position{ 9, -3 });
    this->add_cell(position{ 6, -4 });
    this->add_cell(position{ 8, -4 });
    this->add_cell(position{ 10, -4 });

    this->add_cell(position{ 4, -5 });
    this->add_cell(position{ 4, -4 });
    this->add_cell(position{ 3, -3 });
    this->add_cell(position{ 5, -3 });
    this->add_cell(position{ 3, -2 });
    this->add_cell(position{ 5, -2 });
    this->add_cell(position{ 2, -1 });
    this->add_cell(position{ 4, -1 });
    this->add_cell(position{ 6, -1 });


    //triangles

    this->add_block(std::vector<position>{
        position{ 0, 0 },
        position{ 2, 0 },
        position{ 4, 0 },
        position{ 1, 1 },
        position{ 3, 1 },
        position{ 1, 2 },
        position{ 3, 2 },
        position{ 2, 3 },
        position{ 2, 4 }
    });

    this->add_block(std::vector<position>{
        position{ 4, 3 },
        position{ 4, 4 },
        position{ 3, 5 },
        position{ 5, 5 },
        position{ 3, 6 },
        position{ 5, 6 },
        position{ 2, 7 },
        position{ 4, 7 },
        position{ 6, 7 },
    });

    this->add_block(std::vector<position>{
        position{ 6, 4 },
        position{ 8, 4 },
        position{ 10, 4},
        position{ 7, 5 },
        position{ 9, 5 },
        position{ 7, 6 },
        position{ 9, 6 },
        position{ 8, 7 },
        position{ 8, 8 },
    });

    this->add_block(std::vector<position>{
        position{ 10, -1 },
        position{ 10, 0 },
        position{ 9, 1 },
        position{ 11, 1 },
        position{ 9, 2 },
        position{ 11, 2 },
        position{ 8, 3 },
        position{ 10, 3 },
        position{ 12, 3 }
    });

    this->add_block(std::vector<position>{
        position{ 8, 0 },
        position{ 8, -1 },
        position{ 7, -2 },
        position{ 9, -2 },
        position{ 7, -3 },
        position{ 9, -3 },
        position{ 6, -4 },
        position{ 8, -4 },
        position{ 10, -4 }
    });

    this->add_block(std::vector<position>{
        position{ 4, -5 },
        position{ 4, -4 },
        position{ 3, -3 },
        position{ 5, -3 },
        position{ 3, -2 },
        position{ 5, -2 },
        position{ 2, -1 },
        position{ 4, -1 },
        position{ 6, -1 }
    });

    //inner rows

    this->add_block(std::vector<position>{
        position{ 2, -1 },
        position{ 2, 0 },
        position{ 3, 1 },
        position{ 3, 2 },
        position{ 4, 3 },
        position{ 4, 4 },
        position{ 5, 5 },
        position{ 5, 6 },
        position{ 6, 7 }
    });

    this->add_block(std::vector<position>{
        position{ 2, 4 },
        position{ 3, 5 },
        position{ 4, 4 },
        position{ 5, 5 },
        position{ 6, 4 },
        position{ 7, 5 },
        position{ 8, 4 },
        position{ 9, 5 },
        position{ 10, 4 }
    });

    this->add_block(std::vector<position>{
        position{ 6, 7 },
        position{ 7, 6 },
        position{ 7, 5 },
        position{ 8, 4 },
        position{ 8, 3 },
        position{ 9, 2 },
        position{ 9, 1 },
        position{ 10, 0 },
        position{ 10, -1 }
    });

    this->add_block(std::vector<position>{
        position{ 10, 4 },
        position{ 10, 3 },
        position{ 9, 2 },
        position{ 9, 1 },
        position{ 8, 0 },
        position{ 8, -1 },
        position{ 7, -2 },
        position{ 7, -3 },
        position{ 6, -4 }
    });

    this->add_block(std::vector<position>{
        position{ 2, -1 },
        position{ 3, -2 },
        position{ 4, -1 },
        position{ 5, -2 },
        position{ 6, -1 },
        position{ 7, -2 },
        position{ 8, -1 },
        position{ 9, -2 },
        position{ 10, -1 }
    });

    this->add_block(std::vector<position>{
        position{ 2, 4 },
        position{ 2, 3 },
        position{ 3, 2 },
        position{ 3, 1 },
        position{ 4, 0 },
        position{ 4, -1 },
        position{ 5, -2 },
        position{ 5, -3 },
        position{ 6, -4 }
    });

    //outer rows

    this->add_block(std::vector<position>{
        position{ 0, 0 },
        position{ 1, 1 },
        position{ 1, 2 },
        position{ 2, 0 },
        position{ 2, -1 },
        position{ 3, -2 },
        position{ 3, -3 },
        position{ 4, -4 },
        position{ 6, -5 }
    });

    this->add_block(std::vector<position>{
        position{ 4, -5 },
        position{ 4, -4 },
        position{ 3, -3 },
        position{ 5, -3 },
        position{ 6, -4 },
        position{ 7, -3 },
        position{ 8, -4 },
        position{ 9, -3 },
        position{ 10, -4 }
    });

    this->add_block(std::vector<position>{
        position{ 10, -4 },
        position{ 9, -3 },
        position{ 8, -4 },
        position{ 9, -2 },
        position{ 10, -1 },
        position{ 10, 0 },
        position{ 11, 1 },
        position{ 11, 2 },
        position{ 12, 3 }
    });

    this->add_block(std::vector<position>{
        position{ 12, 3 },
        position{ 11, 2 },
        position{ 11, 1 },
        position{ 10, 3 },
        position{ 10, 4 },
        position{ 9, 5 },
        position{ 9, 6 },
        position{ 8, 7 },
        position{ 8, 8 }
    });

    this->add_block(std::vector<position>{
        position{ 8, 8 },
        position{ 8, 7 },
        position{ 9, 6 },
        position{ 7, 6 },
        position{ 6, 7 },
        position{ 5, 6 },
        position{ 4, 7 },
        position{ 3, 6 },
        position{ 2, 7 }
    });

    this->add_block(std::vector<position>{
        position{ 2, 7 },
        position{ 4, 7 },
        position{ 3, 6 },
        position{ 3, 5 },
        position{ 2, 4 },
        position{ 2, 3 },
        position{ 1, 2 },
        position{ 1, 1 },
        position{ 0, 0 }
    });
}