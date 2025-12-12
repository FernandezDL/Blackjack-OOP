#include "Game.h"

// Initialize Game's components
Game::Game()
{
	player = Player();
	dealer = Dealer();
	graphics = Graphics();
}

// Deal a card to the Player
void Game::DealToPlayer()
{
	player.GiveCard(Deck::GetInstance()->GetCard());
}

// Deal a card to the Dealer
void Game::DealToDealer()
{
	dealer.GiveCard(Deck::GetInstance()->GetCard());
}

// Start a round
void Game::Start()
{
	// Reset Deck
	Deck::GetInstance()->Reset();

	// Reset both participants Hand's
	player.GetHand()->Clear();
	dealer.GetHand()->Clear();
}

void Game::UpdateCurrentTurn(CurrentTurn current)
{
	currentTurn = current;
}

// Returns true if Participant lose the game
bool Game::CheckLoseCondition(int loseCon)
{
	switch (currentTurn)
	{
	case Input:
		return player.GetHand()->GetValue() > loseCon;
		break;
	case AI:
		return dealer.GetHand()->GetValue() > loseCon;
		break;
	}
}

bool Game::CheckDealerWin(int winCon)
{
	return player.GetHand()->GetValue() == winCon;
}

CurrentTurn Game::GetCurrentTurn()
{
	return currentTurn;
}
