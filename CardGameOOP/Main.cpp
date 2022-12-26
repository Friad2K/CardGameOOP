#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector> // Include the vector header

using namespace std;

// That defines a card - they must have suit, name and value
struct Card
{
    string card_name;
    string suit;
    int value;
};

// Function prototypes
void convert_card(Card* theCard, int theNumber);
void get_suit(Card* theCard, int theNumber);

int main() {
    // Seed the random number generator
    srand((unsigned)time(0));

    // Use a vector to create a dynamic array of cards
    vector<Card> pack;
    pack.resize(52); // 52 cards in a pack

    int guess_value;
    int card_to_guess_num;
    Card* card_to_guess;
    int num_guesses = 0;
    bool not_guessed = true;

    // Give every card a name, suit, and value
    for (int i = 0; i < 52; i++)
    {
        int cardNum = (rand() % 13) + 1; // 13 possible cards
        convert_card(&pack[i], cardNum); // Pass a pointer to the card in the vector

        int suitNum = (rand() % 4) + 1; // 4 possible suits
        get_suit(&pack[i], suitNum); // Pass a pointer to the card in the vector
    }

    card_to_guess_num = (rand() % 52); // Randomly select a card for the user to guess
    card_to_guess = &pack[card_to_guess_num]; // Get a pointer to the chosen card
    cout << "Guess the value of the card: " << card_to_guess->card_name << " of " << card_to_guess->suit << endl;
    while (not_guessed)
    { // Keep looping until the user guesses the correct value
        cout << "Enter your guess: ";
        cin >> guess_value;
        num_guesses++;
        if (guess_value < card_to_guess->value)
        {
            cout << "Higher!" << endl;
        }
        else if (guess_value > card_to_guess->value)
        {
            cout << "Lower!" << endl;
        }
        else
        {
            cout << "Correct! The card was the " << card_to_guess->card_name << " of " << card_to_guess->suit << endl;
            not_guessed = false;
        }
    }
    cout << "You used " << num_guesses << " guesses." << endl;

    return 0;
}

// Declare function called convert_card that takes a reference to a card object called the card
// And an integer called thenumber as arguments
void convert_card(Card* theCard, int theNumber)
{
    switch (theNumber)
    {
    case 1:
        theCard->card_name = "Ace";
        theCard->value = 1;
        break;
    case 2:
        theCard->card_name = "2";
        theCard->value = 2;
        break;
    case 3:
        theCard->card_name = "3";
        theCard->value = 3;
        break;
    case 4:
        theCard->card_name = "4";
        theCard->value = 4;
        break;
    case 5:
        theCard->card_name = "5";
        theCard->value = 5;
        break;
    case 6:
        theCard->card_name = "6";
        theCard->value = 6;
        break;
    case 7:
        theCard->card_name = "7";
        theCard->value = 7;
        break;
    case 8:
        theCard->card_name = "8";
        theCard->value = 8;
        break;
    case 9:
        theCard->card_name = "9";
        theCard->value = 9;
        break;
    case 10:
        theCard->card_name = "10";
        theCard->value = 10;
        break;
    case 11:
        theCard->card_name = "Jack";
        theCard->value = 10;
        break;
    case 12:
        theCard->card_name = "Queen";
        theCard->value = 10;
        break;
    case 13:
        theCard->card_name = "King";
        theCard->value = 10;
        break;
    }
}

// Declare function called get_suit that takes a reference to a card object called theCard
// And an integer called theNumber as arguments
void get_suit(Card* theCard, int theNumber)
{
    switch (theNumber)
    {
    case 1:
        theCard->suit = "Spades";
        break;
    case 2:
        theCard->suit = "Hearts";
        break;
    case 3:
        theCard->suit = "Clubs";
        break;
    case 4:
        theCard->suit = "Diamonds";
        break;
    }
}
