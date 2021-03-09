#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

void playerTurn(Deck& deck, Player& player)
{
    do
    {
        player.drawCard(deck);
        std::cout << "\nThe player drew a card\nPlayer score is: " << player.score() << "\n\n";
        
        if (player.isBust())
        {
            std::cout << "### Player Broke ###\n\n";
            break;
        }  
    } while (player.playerWantsHit()); 
}

void dealerTurn(Deck& deck, Player& dealer)
{
    std::cout << "\n\n---------- Dealer Turn ----------\n\n";
    while (dealer.score() < 19)
    {
        dealer.drawCard(deck);
        std::cout << "The dealer drew a card\nDealer score is: " << dealer.score() << "\n\n";
    }
}

bool playBlackjack(Deck& deck)
{
    Player dealer;
    dealer.drawCard(deck);
    std::cout << "\nThe dealer drew a card with value: " << dealer.score() << "\n";

    Player player;
    player.drawCard(deck);
    player.drawCard(deck);
    std::cout << "The player drew two cards with value: " << player.score() << "\n\n";

    std::cout << "\n\n---------- Player Turn ----------\n\n";
    if (player.playerWantsHit())
    {
       playerTurn(deck, player);
    }
    
    //Dealer will not play if player overflows
    if (player.score() > 21)
    {
        return false;
    }
    else
    {
        dealerTurn(deck, dealer);
    }

    if (player.score() > dealer.score() || dealer.score() > 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Deck deck{};

    deck.shuffleDeck();
    deck.printDeck();

    if(playBlackjack(deck))    
    {
        std::cout << "YOU WIN! \n";
    }
    else
    {
        std::cout << "YOU LOUSE!\n";
    }

    return 0;
}