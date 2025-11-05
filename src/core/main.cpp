#include "../inc/main.hpp"

int main()
{
    Pocket main_pocket;
    Hand player_hand;
    Board board;

    std::cout << "\nPocket :" << std::endl;
    main_pocket.display();

    player_hand.fillFrom(main_pocket);

    std::cout << "Initial hand: " << std::endl;
    player_hand.display();

    std::cout << "Board: " << std::endl;
    board.display();

    return 0;
}