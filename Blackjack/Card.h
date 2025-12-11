#pragma once
#include <vector>

class Card
{
public:

	int GetValue();

private:

	Card(int Value);
	int value;
};