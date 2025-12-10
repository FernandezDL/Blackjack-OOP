#pragma once
#include "Hand.h"
#include "Card.h"

class Participant
{
public:
	void giveCard(const Card& c) {}
	Hand& getHand() {}

private:
	Hand hand;
};

