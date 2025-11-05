#ifndef EASEL_HPP
#define EASEL_HPP

#include <array>
#include <vector>
#include <iostream>

#include "letter_pocket.hpp"

class Easel {
public:
    Easel();                          // chevalet vide
    void fillFrom(Pocket &pocket);   // remplir jusqu'à EASEL_SIZE en tirant du pocket
    void add(const Letter &l);       // ajoute une lettre (si place)
    void display(std::ostream &os = std::cout) const noexcept;
    int size() const noexcept;

private:
    std::vector<Letter> letters_;    // taille <= HAND_SIZE
};

#endif