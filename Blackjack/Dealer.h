#pragma once

#include "Deck.h"
#include "Participant.h"

class Participant;

class Dealer : public Participant
{
public:

	Dealer() {}
	Dealer(DisplayCardsSignature displaySignature);

	void GiveCard(Card* card);
};