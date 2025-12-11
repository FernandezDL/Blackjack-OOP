#include "Utils.h"
#include "Game.h"

int main() 
{
	// Initialize Game
	Game game = Game();
	const int gameWinCondition = 21;
	const int initialCardsPerParticipant = 2;

	game.Start();
	LOG_LN("Starting game!");

	int counter = 0;
	while (counter < initialCardsPerParticipant)
	{
		LOG_LN("Dealing!");
		game.DealToPlayer();
		game.DealToDealer();

		counter++;
	}

	LOG_LN("Finished first round of dealing");

	// Game Loop
	/*while (true) 
	{
	}*/

	

	return 0;
}