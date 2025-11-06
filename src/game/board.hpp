#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <iostream>
#include <optional>
#include "letter_pocket.hpp"

#define BOARD_SIZE 15

enum class Multiplier {
    NONE,
    DOUBLE_LETTER,
    TRIPLE_LETTER,
    DOUBLE_WORD,
    TRIPLE_WORD,
    CENTER
};

struct Cell {
    std::optional<Letter> letter;
    Multiplier multiplier;

    Cell() : letter(std::nullopt), multiplier(Multiplier::NONE) {}
    bool isEmpty() const noexcept { return !letter.has_value(); }
};

class Board {
public:
    Board();    

    // Affichage
    void display(std::ostream &os = std::cout) const noexcept;
    
    // Vérifications
    bool isValidPosition(int row, int col) const noexcept;
    bool isEmpty(int row, int col) const noexcept;
    bool isCenterEmpty() const noexcept;
    
    // Placement
    bool placeLetter(int row, int col, const Letter &l);
    std::optional<Letter> getLetter(int row, int col) const noexcept;
    
    // Getter pour multiplicateur
    Multiplier getMultiplier(int row, int col) const noexcept;
    
private:
    std::array<std::array<Cell, BOARD_SIZE>, BOARD_SIZE> grid_;

    void initializeMultipliers();
    char getMultiplierChar(Multiplier m) const noexcept;
};

#endif