#pragma once
#include <iostream>
#include "Card.h"
#include <functional>

class Graphics
{
public:
	//subscribeCardDrawn(CardDrawnCallback callback) {}
	//notifyCardDrawn(const Card& card, const std::string& owner) {}
	void PrintCardBack() const;
	void PrintCardFace(int value) const;
};