#include "Card.h"

// Constructor
Card::Card(int Value) : value(Value) {}

// Returns card value { 1 - 10 }
int Card::GetValue()
{
	return value;
}