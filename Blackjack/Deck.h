#pragma once
#include "Card.h"

class Deck
{
public:
	static Deck& getInstance() {}
	bool canCreate(int value) const {}
	Card createCard(int value) {}
	void reset() {}

private:
	int valueCount[11];
	static Deck* instance;

	Deck() {};
};

