#pragma once

#include "Utils.h"
#include "Player.h"
#include "Dealer.h"
#include "Graphics.h"
#include "Deck.h"
#include "Hand.h"

enum CurrentTurn
{
	Input,
	AI
};

class Game
{

public:

	Game();
	void DealToPlayer();
	void DealToDealer();
	void Start();
	void ResetGame();
	void UpdateCurrentTurn(CurrentTurn current);
	bool CheckLoseCondition(int loseCon);
	bool CheckDealerWin(int winCon);

	CurrentTurn GetCurrentTurn();

private:

	CurrentTurn currentTurn = CurrentTurn::Input;
	Player player;
	Dealer dealer;
	Graphics graphics;
};