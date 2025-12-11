#pragma once

#include "Deck.h"

class Deck;

class Card
{
public:

	friend Deck;

	Card() = delete;
	int GetValue();

private:

	Card(int Value);
	int value;
};