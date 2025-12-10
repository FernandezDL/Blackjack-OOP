#pragma once
#include "Card.h"
#include <vector>

class Hand
{
public:
	void addCard(const Card& c) {}
	int getValue() const {}
	void clear() {}

private:
	std::vector<Card> cards;
};

