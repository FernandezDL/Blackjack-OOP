#pragma once

#include "Participant.h"

class Participant;

class Player : public Participant
{

public: 

	Player() {};
	Player(DisplayCardsSignature displaySignature);

	void GiveCard(Card* card);
};