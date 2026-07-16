/* Tristan Zhang

 Lab 3 Solution

    This program is the Card class file for the card games of Lab 2.
 Each Card object represents a card with a suit and a value. Card
 values are ranked highest to lowest: 1, 13, 12, 11, 10, 9, 8, 7, 6,
 5, 4, 3, 2 - ace, king, queen, jack, ten, nine, eight, seven, six,
 five, four, three, two.
*/

#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Card {
private:
    int value, suit;
    
public:
    Card();

    int getValue();
    int getSuit();
    void deal();
    void getFaceValue(string &faceValueName, string &suitValueName);
};

//Constructor to set the default suit and value of the Card object
Card::Card() {
    value = suit = -1;
}

//Accessor methods
int Card::getValue() {
    return value;
}

int Card::getSuit() {
    return suit;
}

//Method to deal each Card object a random suit and a random value
void Card::deal() {
    static bool seedStatus = false;
    if(!seedStatus){
        srand(static_cast<unsigned>(time(0)));
        seedStatus = true;
    }
    value = rand() % 13 + 1;
    suit = rand() % 4 + 1;
}

//Method to assign a card a face value name and a suit value name
void Card::getFaceValue(string &faceValueName, string &suitName) {
    //Check if the card has not been dealt. If so do not assign a specific face and suit value name to the card but indicate it has not been dealt.
    if((value == -1) || (suit == -1)){
        faceValueName = "Card has not been dealt yet.";
        suitName = "Card has not been dealt yet.";
    }
    else if(value == 1)
        faceValueName = "Ace";
    else if(value == 2)
        faceValueName = "Two";
    else if(value == 3)
        faceValueName = "Three";
    else if(value == 4)
        faceValueName = "Four";
    else if(value == 5)
        faceValueName = "Five";
    else if(value == 6)
        faceValueName = "Six";
    else if(value == 7)
        faceValueName = "Seven";
    else if(value == 8)
        faceValueName = "Eight";
    else if(value == 9)
        faceValueName = "Nine";
    else if(value == 10)
        faceValueName = "Ten";
    else if(value == 11)
        faceValueName = "Jack";
    else if(value == 12)
        faceValueName = "Queen";
    else if(value == 13)
        faceValueName = "King";
    
    if(suit == 1)
        suitName = "Clubs";
    else if(suit == 2)
        suitName = "Diamonds";
    else if(suit == 3)
        suitName = "Hearts";
    else if(suit == 4)
        suitName = "Spades";
}
