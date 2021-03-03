#include "Deck.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cassert>

Deck::Deck()
{
	index_type card{ 0 };

	auto ranks{ static_cast<index_type>(CardRank::MAX_RANKS) };
	auto suits{ static_cast<index_type>(CardSuit::MAX_SUITS) };

	for (index_type suit{ 0 }; suit < suits; ++suit)
	{
		for (index_type rank{ 0 }; rank < ranks; ++rank)
		{
			m_deck[card] = { static_cast<CardRank>(rank), static_cast<CardSuit>(suit) };
			++card;
		}
	}
}

void Deck::printDeck()const
{
	for (const auto& card : m_deck)
	{
		card.printCard();
		std::cout << ' ';
	}

	std::cout << '\n';
}

void Deck::shuffleDeck()
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr))};
	std::shuffle(m_deck.begin(), m_deck.end(), mt);

	m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
	assert(m_cardIndex < m_deck.size());

	return m_deck[m_cardIndex++];
}

