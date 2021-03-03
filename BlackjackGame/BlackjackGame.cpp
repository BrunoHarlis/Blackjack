#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

/*

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

*/

int main()
{
    Deck deck{};

    deck.shuffleDeck();
    deck.printDeck();

    Player player{};
    Player dealer{};
    
    player.drawCard(deck);
    dealer.drawCard(deck);

    std::cout << "The player drew a card with value: " << player.score() << '\n';
    std::cout << "The dealer drew a card with value: " << dealer.score() << '\n';

    std::cout << "\n********** PLAYER TURN **********\n";
    while (player.playerWantsHit())
    {
        player.drawCard(deck);
        std::cout << "Player score now is: " << player.score() << "\n\n";
    }
    
    std::cout << "\n********** DEALER TURN **********\n";
    while (dealer.playerWantsHit())
    {
        dealer.drawCard(deck);
        std::cout << "Dealer score is: " << dealer.score() << "\n\n";
    }

    return 0;
}