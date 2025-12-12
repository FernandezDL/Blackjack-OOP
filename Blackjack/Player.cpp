#include "Player.h"
#include "Participant.h"
#include "Utils.h"
#include <iostream>
#include "Graphics.h"

void Player::GiveCard(Card* card) 
{
	Graphics graph;

	Participant::GiveCard(card);

	LOG_LN("----- Card has been deal to the player -----");
	graph.PrintCardFace(std::cout, 5);
}