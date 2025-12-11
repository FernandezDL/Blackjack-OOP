#pragma once

#include "Card.h"
#include "Participant.h"

class Card;
class Participant;

class Deck
{
public:

	static Deck* GetInstance();
	Card* GetCard();
	void Reset();
	void Reset(VECTOR(Participant*) participants);

	bool CanCreate(int value) const;

private:

	const int TOTAL_CARDS = 52;

	Deck();

	int valueCount[11];
	int drawnCards;
	static Deck* instance;
};