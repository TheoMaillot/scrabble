#ifndef LETTER_POCKET_HPP
#define LETTER_POCKET_HPP

#include <array>
#include <vector>
#include <iostream>

struct Letter {
    char character;
    int value;
    int quantity;
};

class Pocket {
public:
    Pocket();                        // initialise le sac (quantités, total)
    int totalLetters() const noexcept;
    bool draw(Letter &out);          // tire une lettre (false si vide)
    void display(std::ostream &os = std::cout) const noexcept;

private:
    std::array<Letter, 26> letters_;
    int total_letters_;
};

#endif