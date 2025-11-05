#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <vector>
#include <iostream>

struct Cell{
    char letter;
    int letter_multiplier;
    int word_multiplier;
    bool occupied;
};

class Board {
public:
    Board();
    void display(std::ostream &os = std::cout) const noexcept;
    bool placeWord(const std::string &word, int row, int col, bool horizontal);
    int calculateScore(const std::string &word, int row, int col, bool horizontal) const;
    bool canPlaceWord(const std::string &word, int row, int col, bool horizontal) const;
private:
    std::array<std::array<Cell,15>,15> cells_;
};

#endif