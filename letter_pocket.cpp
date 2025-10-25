#include "letter_pocket.hpp"

Pocket* create_letter_pocket() {
    Pocket* pocket = new Pocket();
    pocket->total_letters = 0;

    // Initialize letter values and quantities
    const int letter_values[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
        5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
        1, 4, 4, 8, 4, 10
    };

    const int letter_quantities[26] = {
        9, 2, 2, 4, 12, 2, 3, 2, 9, 1,
        4, 4, 2, 6, 8, 2, 1, 6, 4, 6,
        4, 2, 2, 1, 2, 1
    };

    for (int i = 0; i < 26; ++i) {
        pocket->letters[i].character = 'A' + i;
        pocket->letters[i].value = letter_values[i];
        pocket->letters[i].quantity = letter_quantities[i];
        pocket->total_letters += letter_quantities[i];
    }

    return pocket;
}

Hand* create_hand() {
    Hand* hand = new Hand();
    hand->letters = new Letter[HAND_SIZE];
    hand->total_letters = 0;
    return hand;
}

Hand* withdraw_letters(Hand* hand, Pocket* pocket) {
    int missing_letters = HAND_SIZE - hand->total_letters;

    for (int i = 0; i < missing_letters; ++i) {
        bool letter_found = false;
        while (!letter_found) {
            int random_index = rand() % 26;
            if (pocket->letters[random_index].quantity > 0) {
                hand->letters[hand->total_letters] = pocket->letters[random_index];
                pocket->letters[random_index].quantity--;
                pocket->total_letters--;
                hand->total_letters++;
                letter_found = true;
            }
        }
    }
    return hand;
}

void display_hand(Hand* hand) {
    for (int i = 0; i < hand->total_letters; ++i) {
        cout << hand->letters[i].character << " ";
    }
    cout << endl;
}

void display_pocket(Pocket* pocket) {
    for (int i = 0; i < 26; ++i) {
        cout << pocket->letters[i].character << ": " << pocket->letters[i].quantity << " ";
    }
    cout << endl;
}