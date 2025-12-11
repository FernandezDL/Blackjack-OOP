#pragma once

#include "Utils.h"
#include "Player.h"
#include "Dealer.h"
#include "Graphics.h"
#include "Deck.h"

class Game
{
public:

	Game();
	void DealToPlayer();
	void DealToDealer();
	void Start();

private:

	Player player;
	Dealer dealer;
	Graphics graphics;
};