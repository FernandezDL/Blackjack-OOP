#include "Utils.h"
#include "Game.h"
#include <functional>

int main() 
{
	// Initialize Game
	Game game = Game();
	const int gameEndCondition = 21;
	const int initialCardsPerParticipant = 2;

	// Game variables
	bool deal = false;
	int counter = 0;
	bool isGameOver = false;
	bool isDealerWin = false;

	INSTRUCTIONS();
	PAUSE();
	CLEAN();

	game.Start();
	LOG_LN("Starting game!");

	// Game Loop
	while (true) 
	{
		// First round of dealing
		while (counter < initialCardsPerParticipant)
		{
			game.DealToPlayer();
			game.DealToDealer();

			counter++;
			PAUSE();
		}

		isGameOver = game.CheckLoseCondition(gameEndCondition);

		if (!isGameOver) 
		{
			LOG_SPACER2_LN;
			LOG_LN("\t\tPLAYER'S TURN");
			LOG_SPACER2;

			// Player's turn
			game.UpdateCurrentTurn(CurrentTurn::Input);
			STRING continueInput;
			do
			{
				CONTINUE_INPUT(continueInput);
				if (continueInput == "y")
				{
					CLEAN();
					game.DealToPlayer();

					continueInput = "";
				}

				isGameOver = game.CheckLoseCondition(gameEndCondition);
				if (isGameOver) break;
			}
			while (continueInput != "n");
		}

		if (!isGameOver)
		{
			CLEAN();
			LOG_SPACER2_LN;
			LOG_LN("\t\tDEALER'S TURN");
			LOG_SPACER2;

			// Dealer's turn
			game.UpdateCurrentTurn(CurrentTurn::AI);
			do
			{
				game.DealToDealer();

				isDealerWin = game.CheckDealerWin(gameEndCondition);
				if (isDealerWin) break;

			} while (!game.CheckLoseCondition(gameEndCondition));

			if (isDealerWin)
			{
				// Dealer reached 21
				LOG_SPACER_LN;
				LOG_LN("Dealer reached 21");
				LOG_LN("DEALER WON");
				LOG_SPACER;
			}
			else
			{
				// The dealer went over 21
				LOG_SPACER_LN;
				LOG_LN("Dealer's hand value is above 21");
				LOG_LN("PLAYER WON");
				LOG_SPACER;
			}
		}
		else
		{
			// The player went over 21
			LOG_SPACER_LN;
			LOG_LN("Players's hand value is above 21");
			LOG_LN("DEALER WON");
			LOG_SPACER;
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
			game.ResetGame();
			CLEAN();
		}
	}

	return 0;
}