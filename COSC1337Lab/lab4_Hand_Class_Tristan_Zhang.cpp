
#include <cstdlib>
#include <ctime>
#include <string>
#include "lab3_Card_Class_Tristan_Zhang.cpp"

using namespace std;

class Hand {
    private:
        Card handOfThree[3];
        int numCards;
    
    public:
        Hand();
    
        int getNumCards();
        void dealHand();
        void getCardFaceValues(int index, string &faceValueName, string &suitName);
        void getCardNumericValues(int index, int &cardValueInt, int &cardSuitInt);
        void sortHands();
};

//Constructor to set the default number of cards in the hand object
Hand::Hand() {
    numCards = 3;
}

//Accessor method
int Hand::getNumCards() {
    return numCards;
}

//Method to deal each Card object in the handOfThree array
void Hand::dealHand() {
    for(int i = 0; i < 3; i++)
        handOfThree[i].deal();
}

//Method to display of a card their face value name and suit value name
void Hand::getCardFaceValues(int index, string &faceValueName, string &suitName) {
    if((index < 0) || (index > 2)){
        faceValueName = "None";
        suitName = "None";
    }
    else{
        handOfThree[index].getFaceValue(faceValueName, suitName);
    }
}

//Method to display of a card their value number and suit number
void Hand::getCardNumericValues(int index, int &cardValueInt, int &cardSuitInt) {
    if((index < 0) || (index > 2)){
        cardValueInt = 0;
        cardSuitInt = 0;
    }
    else{
        cardValueInt = handOfThree[index].getValue();
        cardSuitInt = handOfThree[index].getSuit();
    }
}

//Sort the cards in the array handOfThree in ascending order of card with the lowest to highest value
void Hand::sortHands() {
    int currIndex, minIndex;
    Card temp;
    
    /*
     The outer for loop below ensures that the starting search value for the Card object
     with the next minimum face value of the Card objects in the handOfThree array gets
     reset to the next index in the handOfThree array after placing the Card object with
     the next minimum face value in its correct position in the handOfThree array
     */
    for(currIndex = 0; currIndex < 2; currIndex++)
    {
        //Assume the current item in the array of Card objects has the minimum face value
        minIndex = currIndex;
        
        /*
         One full start and exit out of the for loop below finds the Card object with the
         next minimum face value
         */
        for(int i = currIndex+1; i < 3; i++)
        {
            /*
             First focus on the case of if the first card is an ace, as reflected by the first
             if statement, as that is the special case of the highest card.
             */
            if(handOfThree[minIndex].getValue() == 1){
                if(handOfThree[minIndex].getValue() < handOfThree[i].getValue())
                    minIndex = i;
            }
            else{
                if(handOfThree[minIndex].getValue() > handOfThree[i].getValue() && !(handOfThree[i].getValue() == 1))
                    minIndex = i;
            }
        }
            // Swap Card object with the next minimum face value with the current Card object
            temp = handOfThree[currIndex];
            handOfThree[currIndex] = handOfThree[minIndex];
            handOfThree[minIndex] = temp;
    }
}



                         
