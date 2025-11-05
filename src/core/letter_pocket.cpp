#include "../inc/letter_pocket.hpp"
#include <random>

Pocket::Pocket()
{
    // mettre les bonnes valeurs
    const int letter_values[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
        5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
        1, 4, 10, 10, 10, 10
    };
    //mettre bonnes quatités
    const int letter_quantities[26] = {
        9, 2, 2, 4, 12, 2, 3, 2, 9, 1,
        4, 4, 2, 6, 8, 2, 1, 6, 4, 6,
        4, 2, 2, 1, 2, 1
    };

    total_letters_ = 0;
    for (int i = 0; i < 26; ++i) {
        letters_[i].character = static_cast<char>('A' + i);
        letters_[i].value = letter_values[i];
        letters_[i].quantity = letter_quantities[i];
        total_letters_ += letter_quantities[i];
    }
}

int Pocket::totalLetters() const noexcept
{
    return total_letters_;
}

bool Pocket::draw(Letter &out)
{
    if (total_letters_ == 0) return false;

    static thread_local std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 25);

    // pick a random index with available quantity
    for (;;) {
        int idx = dist(rng);
        if (letters_[idx].quantity > 0) {
            out.character = letters_[idx].character;
            out.value = letters_[idx].value;
            out.quantity = 1;
            letters_[idx].quantity -= 1;
            --total_letters_;
            return true;
        }
        // loop until found (expected to finish because total_letters_ > 0)
    }
}

void Pocket::display(std::ostream &os) const noexcept
{
    for (int i = 0; i < 26; ++i) {
        os << letters_[i].character << ": " << letters_[i].quantity << " ";
    }
    os << std::endl;
}