#include "Dealer.h"
#include "Graphics.h"

Dealer::Dealer(DisplayCardsSignature displaySignature)
{
	hand = new Hand();
	OnDisplayCard = displaySignature;
}

void Dealer::GiveCard(Card* card)
{
	Participant::GiveCard(card);

	if (OnDisplayCard) 
	{
		OnDisplayCard(card->GetValue());
	}
}