#pragma once

#include "Deck.h"
#include "Participant.h"

class Dealer : public Participant
{
public:
	void GiveCard(Card* card);
	void Play(Deck& deck);
};