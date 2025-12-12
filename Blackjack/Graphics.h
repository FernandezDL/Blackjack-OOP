#pragma once
#include <iostream>
#include "Card.h"

class Graphics
{
public:
	//subscribeCardDrawn(CardDrawnCallback callback) {}
	//notifyCardDrawn(const Card& card, const std::string& owner) {}
	void PrintCardBack(std::ostream& os) const;
	void PrintCardFace(std::ostream& os, int value) const;
};

