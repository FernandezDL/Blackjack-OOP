#pragma once

#include "Utils.h"
#include "Card.h"

class Hand
{
public:

	void AddCard(Card* c);
	int GetValue() const;
	void Clear();

private:

	VECTOR(Card*) cards;
};