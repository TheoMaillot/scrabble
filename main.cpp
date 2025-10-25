#include "main.hpp"

int main()
{
    Pocket* main_pocket = new Pocket();
    Hand* player_hand = new Hand();
    main_pocket = create_letter_pocket();
    cout << "\nPocket :" << endl;
    display_pocket(main_pocket);
    player_hand = create_hand();

    cout << "Initial hand: " << endl;
    player_hand = withdraw_letters(player_hand, main_pocket);
    display_hand(player_hand);
    return 0;
}