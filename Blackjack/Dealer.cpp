#include "Dealer.h"
#include "Graphics.h"
#include <iostream>

void Dealer::GiveCard(Card* card)
{
	Graphics graph;
	Participant::GiveCard(card);

	LOG_LN("----- Card has been deal to the Dealer -----");
	graph.PrintCardBack(std::cout);

}