#include "Player.h"
#include "Participant.h"
#include "Graphics.h"

Player::Player(DisplayCardsSignature displaySignature)
{
	hand = new Hand();
	OnDisplayCard = displaySignature;
}

void Player::GiveCard(Card* card)
{
	Participant::GiveCard(card);

	if (OnDisplayCard)
	{
		OnDisplayCard(card->GetValue());
	}
}