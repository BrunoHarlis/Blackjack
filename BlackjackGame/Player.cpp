#include "Player.h"
#include <iostream>

void Player::drawCard(Deck& deck)
{
	m_playerScore += deck.dealCard().getCardValue();
}

int Player::score()const
{
	return m_playerScore;
}

bool Player::isBust()const
{
	return (m_playerScore > m_maxScore);
}

bool Player::playerWantsHit()const
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
