#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

bool playBlackjack(Deck& deck)
{
    Player dealer;
    dealer.drawCard(deck);
    std::cout << "The dealer drew a card with value: " << dealer.score() << '\n';

    Player player;
    player.drawCard(deck);
    player.drawCard(deck);
    std::cout << "The player drew a card with value: " << player.score() << '\n';


    return false;
}

int main()
{
    Deck deck{};

    deck.shuffleDeck();
    deck.printDeck();

    if (playBlackjack(deck))
    {

    }

    return 0;
}