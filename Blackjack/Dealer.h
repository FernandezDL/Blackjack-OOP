#pragma once

#include "Deck.h"
#include "Participant.h"

class Dealer : public Participant
{
public:

	void Play(Deck& deck);
};