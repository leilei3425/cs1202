// hw7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
//CIS 1202 803
//March 15 2025


#include <iostream>
using namespace std;

enum suits { HEARTS, DIAMONDS, SPADES, CLUBS };
enum ranks { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct cards
{
    suits suit;
    ranks rank;
};

// Function declarations
void createDeck(cards[]);
void printDeck(cards[]);
string cardName(cards);
cards deal(cards[]);
string winner(cards, cards);



int main()
{
    cards deck[52];
    cards card1, card2;

    createDeck(deck);
    printDeck(deck);

    // deal cards
    card1 = deal(deck);
    card2 = deal(deck);

    // display cards
    cout << "Card 1 is the " << cardName(card1) << endl;
    cout << "Card 2 is the " << cardName(card2) << endl;

    // display winner
    cout << winner(card1, card2) << endl;

}

// Function to create a deck of 52 cards (each suit and rank combination)
void createDeck(cards deck[]) {
    int index = 0;
    for (int s = 0; s < 4; ++s) {// Loop through each suit (4 suits in total)
        for (int r = 0; r < 13; ++r) { // Loop through each rank (13 ranks in total)
            // reference: https://stackoverflow.com/questions/11452920/how-to-cast-int-to-enum-in-c
            deck[index].suit = static_cast<suits>(s); // Convert int to suits
            deck[index].rank = static_cast<ranks>(r); // Convert int to ranks
            ++index;
        }
    }
}

// Function to print the names of all the cards in the deck
void printDeck(cards deck[]) {
    for (int i = 0; i < 52; ++i) {// Loop through all 52 cards
        cout << cardName(deck[i]) << endl;
    }
}

// Function to convert a card to its human-readable name
string cardName(cards card) {
    const string suitNames[] = { "Hearts", "Diamonds", "Spades", "Clubs" };
    const string rankNames[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

    // reference: https://stackoverflow.com/questions/11452920/how-to-cast-int-to-enum-in-c
    string name = rankNames[static_cast<int>(card.rank)] + " of " + suitNames[static_cast<int>(card.suit)];

    return name;
}

// Function to deal a random card
cards deal(cards deck[]) {
    // the static varible make sure the following code only run once
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<unsigned>(time(0)));  // Seed random number generator
        initialized = true;
    }

    int randomIndex = rand() % 52;  // Random card from deck
    return deck[randomIndex];
}

// Function to determine the winner
string winner(cards crd1, cards crd2) {
    if (static_cast<int>(crd1.rank) > static_cast<int>(crd2.rank)) {
        return "The Winner is the " + cardName(crd1);
    }
    else if (static_cast<int>(crd1.rank) < static_cast<int>(crd2.rank)) {
        return "The Winner is the " + cardName(crd2);
    }
    else {
        return "It's a tie! Both players have " + cardName(crd1);
    }
}