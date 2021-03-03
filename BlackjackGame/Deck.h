#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <array>


class Deck
{
public:
	using deck_type = std::array<Card, 52>;
	using index_type = deck_type::size_type;

private:
	deck_type m_deck{};
	index_type m_cardIndex{ 0 };

public:
	Deck();
	
	void printDeck()const;
	void shuffleDeck();
	const Card& dealCard();
};

#endif