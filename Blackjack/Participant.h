#pragma once

#include "Hand.h"
#include "Card.h"
#include <functional>

class Card;
class Hand;

using DisplayCardsSignature = std::function<void(int)>;

class Participant
{

public:

	virtual void GiveCard(Card* c);
	Hand* GetHand();

protected:

	Hand* hand;

	DisplayCardsSignature OnDisplayCard = nullptr;
};