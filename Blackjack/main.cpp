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

	INSTRUCTIONS(); // prints the introduction and rules of the game
	PAUSE(); // Waits for the player to press ENTER to continue
	CLEAN(); // Clear console

	// Initialize game
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

			counter++; // Increase card counter
			PAUSE(); // Waits for the player to continue
		}

		isGameOver = game.CheckLoseCondition(gameEndCondition); // Verify that the player does not have more than 21 in cards.

		if (!isGameOver) 
		{
			// Player's turn
			LOG_SPACER2_LN;
			LOG_LN("\t\tPLAYER'S TURN");
			LOG_SPACER2;

			// Change turn to the player's
			game.UpdateCurrentTurn(CurrentTurn::Input);
			STRING continueInput; // Define the input string
			do
			{
				// Asks to draw another card
				CONTINUE_INPUT(continueInput); 
				if (continueInput == "y")
				{
					CLEAN(); // Clear the console
					game.DealToPlayer();

					continueInput = "";
				}

				isGameOver = game.CheckLoseCondition(gameEndCondition); // Verify that the player does not have more than 21 in cards.
				if (isGameOver) break; // stop game, as the player has more than 21 in the cards
			}
			while (continueInput != "n"); // stop giving cards to the player
		}

		if (!isGameOver)
		{
			// Dealer's turn
			CLEAN(); // clean 
			LOG_SPACER2_LN;
			LOG_LN("\t\tDEALER'S TURN");
			LOG_SPACER2;

			// Changes the turn to the dealer
			game.UpdateCurrentTurn(CurrentTurn::AI);
			do
			{
				game.DealToDealer();

				// Checks if the dealer have 21 in the cards
				isDealerWin = game.CheckDealerWin(gameEndCondition);
				if (isDealerWin) break; // If the dealer has 21, stops the game
			} while (!game.CheckLoseCondition(gameEndCondition)); // Stops giving cards if the dealer has more than 21 in the cards

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
		PLAYAGAIN_INPUT(playAgainInput); // Asks to play again

		if (playAgainInput == "n") break; // Stop the program
		else 
		{
			// If the player wants to play again, reset the game variables
			counter = 0;
			deal = false;
			isGameOver = false;
			isDealerWin = false;
			game.ResetGame();
			CLEAN(); // clean console
		}
	}

	return 0;
}