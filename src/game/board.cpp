#include "board.hpp"

Board::Board() {
    for (auto &row : cells_) {
        for (auto &cell : row) {
            cell.letter = ' ';
            cell.letter_multiplier = 1;
            cell.word_multiplier = 1;
            cell.occupied = false;
        }
    }
}

void Board::display(std::ostream &os) const noexcept 
{
    for (auto &row : cells_) {
        for (auto &cell : row) {
            os << "|" << cell.letter << "|";
        }
    }
    os << std::endl;
}

bool canPlaceWord(const std::string &word, int row, int col, bool horizontal) {
    // Implementation omitted for brevity
    return true;
}

int calculateScore(const std::string &word, int row, int col, bool horizontal) {
    // Implementation omitted for brevity
    return 0;
}

bool placeWord(const std::string &word, int row, int col, bool horizontal) {
    // Implementation omitted for brevity
    return true;
}
