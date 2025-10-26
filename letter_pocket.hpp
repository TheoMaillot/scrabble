#ifndef LETTER_POCKET_HPP
#define LETTER_POCKET_HPP

#include <array>
#include <vector>
#include <iostream>

constexpr int HAND_SIZE = 7;

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

class Hand {
public:
    Hand();                          // main vide
    void fillFrom(Pocket &pocket);   // remplir jusqu'à HAND_SIZE en tirant du pocket
    void add(const Letter &l);       // ajoute une lettre (si place)
    void display(std::ostream &os = std::cout) const noexcept;
    int size() const noexcept;

private:
    std::vector<Letter> letters_;    // taille <= HAND_SIZE
};

#endif