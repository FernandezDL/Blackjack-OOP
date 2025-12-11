#pragma once

#include "Utils.h"
#include "Card.h"

class Card;

class Hand
{
public:

	void AddCard(Card* c);
	void Clear();

	int GetValue() const;
	VECTOR(Card*) GetCards() const;

private:

	VECTOR(Card*) cards;
};