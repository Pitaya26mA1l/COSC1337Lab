//
//  lab2_Card_Class_Firstname_Lastname.cpp
//  COSC1337Lab
//
//  Created by Tristan Zhang on 6/27/26.
//
#include <cstdlib>
#include <ctime>

class Card
{
    private:
        int value, suit;
    
    public:
        Card();
    
        int getValue();
        int getSuit();
        void deal();
};

Card::Card()
{
    value = suit = -1;
}

int Card::getValue()
{ return value; }
int Card::getSuit()
{ return suit; }
void Card::deal()
{
    static bool seedStatus = false;
    if(!seedStatus)
        srand(static_cast<unsigned>(time(0)));
    seedStatus = true;
    value = rand() % 13 + 1;
    suit = rand() % 4 + 1;
}
