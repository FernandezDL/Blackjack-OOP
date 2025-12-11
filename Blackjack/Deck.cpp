#include <cstdlib>
#include <ctime>
#include "Deck.h"
#include "Hand.h"


// initialize static instance pointer
Deck* Deck::instance = nullptr;

// Constructor
Deck::Deck()
{
	srand((unsigned int)time(nullptr));
	Reset();
}

// Singleton
Deck* Deck::GetInstance()
{
	if (instance) return instance;

	instance = new Deck();
	return instance;
}

// Returns a random valid card that hasn't reached limit
Card* Deck::GetCard()
{
    // Check if deck is empty (all 44 cards used)
    bool deckEmpty = true;
    for (int i = 1; i <= 11; i++)
    {
        if (CanCreate(i))
        {
            deckEmpty = false;
            break;
        }
    }
    if (deckEmpty) return nullptr;

    // Generate random value till one is available
    int value = 0;
    do 
    {
        value = (rand() % 11) + 1;
    } while (!CanCreate(value));

    valueCount[value - 1]++;
    drawnCards++;

    return new Card(value);
}

// Reset drawn cards
void Deck::Reset()
{
    for (int i = 0; i < 11; i++)
        valueCount[i] = 0;
}

// Reset drawn cards
void Deck::Reset(VECTOR(Participant*) participants)
{
	for (int i = 0; i < 11; i++)
		valueCount[i] = 0;

    for (Participant* participant : participants)
    {
        Hand* participantHand = participant->GetHand();

        for (Card* card : participantHand->GetCards()) 
            valueCount[card->GetValue() - 1]++;
    }
}

// Check if a card with this value can still be created (max 4)
bool Deck::CanCreate(int value) const
{
    if (drawnCards >= TOTAL_CARDS)
        return false;

	if (value < 1 || value > 11)
		return false;

    if (value == 10) return valueCount[value - 1] < 16;
	return valueCount[value - 1] < 4;
}