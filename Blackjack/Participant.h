#pragma once
#include "Hand.h"
#include "Card.h"

class Participant
{

public:

	Participant();

	void GiveCard(Card* c);
	Hand* GetHand();

private:

	Hand hand;
};