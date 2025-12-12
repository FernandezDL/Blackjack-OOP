#include "Utils.h"
#include "Game.h"
#include <functional>

int main() 
{
	// Initialize Game
	Game game = Game();
	const int gameEndCondition = 21;
	const int initialCardsPerParticipant = 2;

	// Subscriptions

	// TODO: Add subscriptions here

	// Game variables
	bool deal = false;
	int counter = 0;
	bool isGameOver = false;
	bool isDealerWin = false;

	game.Start();
	LOG_LN("Starting game!");

	// Game Loop
	while (true) 
	{
		// First round of dealing
		while (counter < initialCardsPerParticipant)
		{
			game.DealToPlayer();
			// TODO: Print Player's Card's value

			game.DealToDealer();
			// TODO: Print first Dealer's Card
			counter++;
		}

		// Player's turn
		game.UpdateCurrentTurn(CurrentTurn::Input);

		STRING continueInput;
		do
		{
			isGameOver = game.CheckLoseCondition(gameEndCondition);

			CONTINUE_INPUT(continueInput);
			if (continueInput == "y")
			{
				game.DealToPlayer();
				//TODO: Print total Player's Hand value
			}
		} while (continueInput != "n" || !isGameOver);

		if (!isGameOver)
		{
			// Dealer's turn
			game.UpdateCurrentTurn(CurrentTurn::AI);
			do
			{
				isDealerWin = game.CheckDealerWin(gameEndCondition);

				game.DealToDealer();
				// TODO: Print total Dealer's Hand value
			} while (!game.CheckLoseCondition(gameEndCondition) || isDealerWin);

			if (isDealerWin)
			{
				// TODO: Print player lose
			}
			else
			{
				// TODO: Print player win
			}
		}
		else
		{
			// TODO: Print player lose
		}

		STRING playAgainInput;
		PLAYAGAIN_INPUT(playAgainInput);

		if (playAgainInput == "n") break;
		else 
		{
			counter = 0;
			deal = false;
			isGameOver = false;
			isDealerWin = false;
		}
	}

	return 0;
}