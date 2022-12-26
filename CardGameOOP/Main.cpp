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

// Declare a Card class
class CardGame
{
public:
    // Constructor
    CardGame();

    // Method to initialize a pack of cards with name, suit, and value
    void initializeCards();

    // Method to select a random card from the pack and prompt the user to guess its value
    void playGame();

private:
    // Method to set the name and value of a card based on a randomly generated number
    void convertCard(Card* theCard, int theNumber);

    // Method to set the suit of a card based on a randomly generated number
    void getSuit(Card* theCard, int theNumber);

    vector<Card> pack; // Vector to store a dynamic array of cards
    int num_guesses; // Counter for the number of guesses made
};

int main()
{
    // Seed the random number generator
    srand((unsigned)time(0));

    CardGame game; // Create a CardGame object
    game.playGame(); // Play the game

    return 0;
}

// Define the constructor for the CardGame class
CardGame::CardGame()
{
    pack.resize(52); // 52 cards in a pack
    num_guesses = 0; // Initialize the counter to 0
}

// Define the initializeCards method
void CardGame::initializeCards()
{
    // Give every card a name, suit, and value
    for (int i = 0; i < 52; i++)
    {
        int cardNum = (rand() % 13) + 1; // 13 possible cards
        convertCard(&pack[i], cardNum); // Pass a pointer to the card in the vector

        int suitNum = (rand() % 4) + 1; // 4 possible suits
        getSuit(&pack[i], suitNum); // Pass a pointer to the card in the vector
    }
}

// Define the playGame method
void CardGame::playGame()
{
    int guess_value;
    int card_to_guess_num;
    Card* card_to_guess;
    bool not_guessed = true;

    initializeCards(); // Initialize the pack of cards

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
}
// Define the convertCard method
void CardGame::convertCard(Card* theCard, int theNumber)
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
        theCard->value = 11;
        break;
    case 12:
        theCard->card_name = "Queen";
        theCard->value = 12;
        break;
    case 13:
        theCard->card_name = "King";
        theCard->value = 13;
        break;
    }
}

// Define the getSuit method
void CardGame::getSuit(Card* theCard, int theNumber)
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
