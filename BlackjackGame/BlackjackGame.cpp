#include <algorithm>
#include <array>
#include <iostream>
#include "Card.h"
#include "Deck.h"

/*
struct Player
{
    int score{};
};

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

// Maximum score before losing.
constexpr int maximumScore{ 21 };

// Minium score that the dealer has to have.
constexpr int minimumDealerScore{ 17 };


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

// Returns true if the player went bust. False otherwise.
bool playerTurn(const deck_type& deck, index_type& nextCardIndex, Player& player)
{
    while (true)
    {
        std::cout << "You have: " << player.score << '\n';

        if (player.score > maximumScore)
        {
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                player.score += getCardValue(deck[nextCardIndex++]);
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const deck_type& deck, index_type& nextCardIndex, Player& dealer)
{
    while (dealer.score < minimumDealerScore)
    {
        dealer.score += getCardValue(deck[nextCardIndex++]);
    }

    return (dealer.score > maximumScore);
}

bool playBlackjack(const deck_type& deck)
{
    index_type nextCardIndex{ 0 };

    Player dealer{ getCardValue(deck[nextCardIndex++]) };

    std::cout << "The dealer is showing: " << dealer.score << '\n';

    Player player{ getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1]) };
    nextCardIndex += 2;

    if (playerTurn(deck, nextCardIndex, player))
    {
        return false;
    }

    if (dealerTurn(deck, nextCardIndex, dealer))
    {
        return true;
    }

    return (player.score > dealer.score);
}
*/

int main()
{
    /*
    auto deck{ createDeck() };

    shuffleDeck(deck);

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }
    */
    Deck deck{};

    deck.shuffleDeck();
    deck.printDeck();

    std::cout << "The first card has value: " << deck.dealCard().getCardValue() << '\n';
    std::cout << "The second card has value: " << deck.dealCard().getCardValue() << '\n';
    return 0;
}