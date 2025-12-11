#pragma once
#include "Hand.h"
#include "Card.h"

class Participant
{

public:

	void GiveCard(const Card& c);
	Hand& GetHand();

private:

	Hand hand;
};