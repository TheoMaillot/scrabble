// board.cpp
#include "board.hpp"
#include <iomanip>

Board::Board()
{
    initializeMultipliers();
}

void Board::initializeMultipliers()
{
    // Mots compte triple (MT) - coins et milieux des bords
    const int MT_positions[][2] = {
        {0, 0}, {0, 7}, {0, 14},
        {7, 0}, {7, 14},
        {14, 0}, {14, 7}, {14, 14}
    };
    
    // Mots compte double (MD)
    const int MD_positions[][2] = {
        {1, 1}, {2, 2}, {3, 3}, {4, 4},
        {1, 13}, {2, 12}, {3, 11}, {4, 10},
        {13, 1}, {12, 2}, {11, 3}, {10, 4},
        {13, 13}, {12, 12}, {11, 11}, {10, 10},
        {7, 7}  // centre
    };
    
    // Lettres compte triple (LT)
    const int LT_positions[][2] = {
        {1, 5}, {1, 9},
        {5, 1}, {5, 5}, {5, 9}, {5, 13},
        {9, 1}, {9, 5}, {9, 9}, {9, 13},
        {13, 5}, {13, 9}
    };
    
    // Lettres compte double (LD)
    const int LD_positions[][2] = {
        {0, 3}, {0, 11},
        {2, 6}, {2, 8},
        {3, 0}, {3, 7}, {3, 14},
        {6, 2}, {6, 6}, {6, 8}, {6, 12},
        {7, 3}, {7, 11},
        {8, 2}, {8, 6}, {8, 8}, {8, 12},
        {11, 0}, {11, 7}, {11, 14},
        {12, 6}, {12, 8},
        {14, 3}, {14, 11}
    };

    // Initialisation des cellules du tableau à vide
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            grid_[i][j].multiplier = Multiplier::NONE;
        }
    }

    // Placement des multiplicateurs
}
