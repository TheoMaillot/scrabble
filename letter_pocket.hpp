#include <cstdlib>
#include <iostream>

using namespace std;

#define HAND_SIZE 7

typedef struct letter
{
    char character;
    int value;
    int quantity;
}Letter;

typedef struct pocket
{
    Letter letters[26];
    int total_letters;
}Pocket;

typedef struct hand
{
    Letter* letters;
    int total_letters;
}Hand;

Pocket* create_letter_pocket();

Hand* create_hand();

Hand* withdraw_letters(Hand* hand, Pocket* pocket);

void display_hand(Hand* hand);

void display_pocket(Pocket* pocket);