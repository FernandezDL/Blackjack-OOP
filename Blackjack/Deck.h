#pragma once
#include "Card.h"

class Deck
{
public:

	static Deck& GetInstance();
	Card GetCard(int value);
	void Reset();

	bool CanCreate(int value) const;

private:

	Deck();

	int valueCount[11];
	static Deck* instance;
};