#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// That defines a card - they must have suit, name and value
struct Card
{
    string card_name;
    string suit;
    int value;
};

// Function prototypes
void convert_card(Card& theCard, int theNumber);
void get_suit(Card& theCard, int theNumber);

int main() {
    // Seed the random number generator
    srand((unsigned)time(0));

    // Use a pointer to create an array of cards
    Card* pack;
    pack = new Card[52]; // 52 cards in a pack

    int guess_value;
    int card_to_guess_num;
    Card card_to_guess;
    int num_guesses = 0;
    bool not_guessed = true;

    // Give every card a name, suit, and value
    for (int i = 0; i < 52; i++)
    {
        int cardNum = (rand() % 13) + 1; // 13 possible cards
        convert_card(*(pack + i), cardNum);

        int suitNum = (rand() % 4) + 1; // 4 possible suits
        get_suit(*(pack + i), suitNum);
    }

    card_to_guess_num = (rand() % 52); // Randomly select a card for the user to guess
    card_to_guess = pack[card_to_guess_num];
    cout << "Guess the value of the card: " << card_to_guess.card_name << " of " << card_to_guess.suit << endl;
    while (not_guessed)
    { // Keep looping until the user guesses the correct value
        cout << "Enter your guess: ";
        cin >> guess_value;
        num_guesses++;
        if (guess_value < card_to_guess.value)
        {
            cout << "Higher!" << endl;
        }
        else if (guess_value > card_to_guess.value)
        {
            cout << "Lower!" << endl;
        }
        else
        {
            cout << "Correct! The card was the " << card_to_guess.card_name << " of " << card_to_guess.suit << endl;
            not_guessed = false;
        }
    }
    cout << "You used " << num_guesses << " guesses." << endl;

    return 0;
}