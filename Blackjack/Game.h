#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Graphics.h"

class Game
{
public:

	Game() {}
	void DealToPlayer(int value);
	void DealToDealer(int value);
	void Start();

private:

	Player player;
	Dealer dealer;
	Graphics graphics;
};