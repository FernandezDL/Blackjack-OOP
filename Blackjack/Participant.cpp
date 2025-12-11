#include "Participant.h"

// Initialize each Participant with a Hand
Participant::Participant()
{
    hand = new Hand();
}

// Add a Card to the participant's Hand
void Participant::GiveCard(Card* c)
{
    hand->AddCard(c);
}

// Returns Participant's Hand
Hand* Participant::GetHand()
{
    return hand;
}