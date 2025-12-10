#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Graphics.h"

class Game
{
public:
	Game() {}
	void dealToPlayer(int value) {}
	void dealToDealer(int value) {}
	void start() {}

private:
	Player player;
	Dealer dealer;
	Graphics graphics;
};

