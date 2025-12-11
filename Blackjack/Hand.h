#pragma once
#include "Card.h"
#include <vector>

class Hand
{
public:

	void AddCard(const Card& c) {}
	int GetValue() const {}
	void Clear() {}

private:

	std::vector<Card> cards;
};

