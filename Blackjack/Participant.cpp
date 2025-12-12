#include "Participant.h"

// Add a Card to the participant's Hand
void Participant::GiveCard(Card* c)
{
    hand->AddCard(c);

    if (OnDisplayCard) 
    {
        OnDisplayCard(c->GetValue());
    }
}

// Returns Participant's Hand
Hand* Participant::GetHand()
{
    return hand;
}