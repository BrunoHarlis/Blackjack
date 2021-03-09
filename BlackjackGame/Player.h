#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"

class Player
{
private:
	int m_playerScore{};
	const int m_maxScore{ 21 };

public:
	void drawCard(Deck& deck);
	int score()const;
	bool isBust()const;
	bool playerWantsHit()const;
};

#endif