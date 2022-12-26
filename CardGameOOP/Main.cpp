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

}