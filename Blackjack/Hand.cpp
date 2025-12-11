#include "Hand.h"

// Adds a card to the current hand
void Hand::AddCard(Card* c)
{
	cards.push_back(c);
}

// Returns the value of the hand
int Hand::GetValue() const
{
	int value = 0;

	for (Card* card : cards) 
	{
		value += card->GetValue();
	}

	return value;
}

// Clears the hand
void Hand::Clear()
{
	cards.clear();
}