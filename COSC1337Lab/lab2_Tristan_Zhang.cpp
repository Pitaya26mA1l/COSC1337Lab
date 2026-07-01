/* Tristan Zhang

 Lab 1 Solution

 This program lets the user choose options of which card game to play. The High Card game  generates two random numbers from 1-13 representing two players. Card values are ranked highest to lowest: 1, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 - ace, king, queen, jack, ten, nine, eight, seven, six, five, four, three, two. Then the game displays which player has won.
 There are three possible card games with a function representing each: High Card, Low Card of Three, and One Hand Poker. The High Card game function uses a random number generating function to generate two random numbers. The main function displays the menu options and contains the code to let the user keep entering input to choose which game to play until the user chooses to quit.

*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "lab2_Card_Class_Tristan_Zhang.cpp"

using namespace std;

void highCard();
void lowCardOfThree();
void oneHandPoker();
void displayPlayerCardValue(string, Card);

/* Function:  main

Inputs:    no inputs

Outputs:  returns a zero to end the program

Purpose:   This function contains the main logic of displaying the menu and options and letting the user keep choosing what game they play and playing the game until the user chooses the option to quit.
*/

int main() {
    
    int userChoice;
    
    //Display menu of choices and let the user choose and play the game corresponding to the choice until the user quits. The loop checks if the user quits and if not allows the user to keep choosing what game and contains code that calls the function to play the corresponding game.
    do {
        // 1. Display menu
        cout << "\nMENU\n"
             << "Choose which card game to play by entering a number 1-4.\n"
             << "1. High Card\n"
             << "2. Low Card of Three\n"
             << "3. One Hand Poker\n"
             << "4. Quit.\n";
        cout << "Enter choice: ";
        cin >> userChoice;
        
        //Check if user entered valid option
        while (userChoice < 1 || userChoice > 4)
        {
            cout << "Invalid choice - try again\n";
            cout << "Enter choice: ";
            cin >> userChoice;
        }
    
        // Decide which choice was entered and call the corresponding function if choice 1-3 or quit if choice 4
        cin.ignore();
        if (userChoice == 1)
            highCard();
        else if (userChoice == 2)
            lowCardOfThree();
        else if (userChoice == 3)
            oneHandPoker();
        else
            cout << "You quit.\n";
        }
    while (userChoice != 4);
    return 0;
}

/********************************************************************/

/* Function:  highCard

Inputs:    none

Outputs:  The function is void because it only displays the results of the High Card game.

Purpose:   This function generates two random numbers from 1-13 representing two players. Card values are ranked highest to lowest: 1, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 - ace, king, queen, jack, ten, nine, eight, seven, six, five, four, three, two. Then the game displays which player has won.

*/

void highCard(){
    string playerOneName, playerTwoName;
    
    cout << "Player 1, enter name...";
    getline(cin, playerOneName);
    cout << "Player 2, enter name...";
    getline(cin, playerTwoName);
    
    Card cardPlayer1;
    Card cardPlayer2;
    
    cardPlayer1.deal();
    cardPlayer2.deal();
    

    
    //Display player 1's card
    displayPlayerCardValue(playerOneName, cardPlayer1);
    //Display player 2's card
    displayPlayerCardValue(playerTwoName, cardPlayer2);
    //Compare players' cards and display who won

    if (!(cardPlayer1.getValue() == 1 || cardPlayer2.getValue() == 1))
    {
        if (cardPlayer1.getValue() > cardPlayer2.getValue())
            cout << playerOneName << " wins.\n";
        else if (cardPlayer1.getValue() < cardPlayer2.getValue())
            cout << playerTwoName << " wins.\n";
        else
            cout << "It's a tie.\n";
    }
    else if (cardPlayer1.getValue() < cardPlayer2.getValue())
        cout << playerOneName << " wins.\n";
    else if(cardPlayer1.getValue() > cardPlayer2.getValue())
        cout << playerTwoName << " wins.\n";
    else
        cout << "It's a tie.\n";

}

//Function representing Low Card of Three game
void lowCardOfThree()
{
    string playerOneName, playerTwoName;
    
    cout << "Player 1, enter name...";
    getline(cin, playerOneName);
    cout << "Player 2, enter name...";
    getline(cin, playerTwoName);
    
    Card playerOneDeck[3];
    Card playerTwoDeck[3];
    
    //Deal each player's cards in their deck of cards
    for(int i = 0; i < 3; i++){
        playerOneDeck[i].deal();
        playerTwoDeck[i].deal();
    }
    
    //Display player 1's cards
    for(int i = 0; i < 3; i++){
        displayPlayerCardValue(playerOneName, playerOneDeck[i]);
    }
    
    //Display player 2's cards
    for(int i = 0; i < 3; i++){
        displayPlayerCardValue(playerTwoName, playerTwoDeck[i]);
    }
    
    //Get player 1's lowest card
    int playerOneLowestCard = playerOneDeck[0].getValue();
    for( int i = 0; i < 2; i++){
        if(playerOneLowestCard == 1){
            if(playerOneLowestCard < playerOneDeck[i + 1].getValue())
                playerOneLowestCard = playerOneDeck[i + 1].getValue();
        }
        else{
            if (playerOneLowestCard > playerOneDeck[i + 1].getValue() && !(playerOneDeck[i + 1].getValue() == 1))
                playerOneLowestCard = playerOneDeck[i + 1].getValue();
        }
    }
    
    //Test code to check player 1's lowest
    cout << playerOneName << " has lowest card value of " << playerOneLowestCard << "\n";
    
    //Get player 2's lowest card
    int playerTwoLowestCard = playerTwoDeck[0].getValue();
    for( int i = 0; i < 2; i++){
        if(playerTwoLowestCard == 1){
            if(playerTwoLowestCard < playerTwoDeck[i + 1].getValue())
                playerTwoLowestCard = playerTwoDeck[i + 1].getValue();
        }
        else{
            if (playerTwoLowestCard > playerTwoDeck[i + 1].getValue() && !(playerTwoDeck[i + 1].getValue() == 1))
                playerTwoLowestCard = playerTwoDeck[i + 1].getValue();
        }
    }
    
    //Test code to check player 2's lowest
    cout << playerTwoName << " has lowest card value of " << playerTwoLowestCard << "\n";
    
    //Compare players' lowest cards
    if (!(playerOneLowestCard == 1 || playerTwoLowestCard == 1))
    {
        if (playerOneLowestCard < playerTwoLowestCard)
            cout << playerOneName << " wins.\n";
        else if (playerOneLowestCard > playerTwoLowestCard)
            cout << playerTwoName << " wins.\n";
        else
            cout << "It's a tie.\n";
    }
    else if (playerOneLowestCard > playerTwoLowestCard)
        cout << playerOneName << " wins.\n";
    else if(playerOneLowestCard < playerTwoLowestCard)
        cout << playerTwoName << " wins.\n";
    else
        cout << "It's a tie.\n";
    
}

//Function representing One Hand Poker game
void oneHandPoker(){
    cout << "This game has not been developed.";
}

void displayPlayerCardValue(string nameOfPlayer, Card c){
    if (c.getValue() == 1)
        cout << nameOfPlayer << " gets an ace.\n";
    else if (c.getValue() == 2)
        cout << nameOfPlayer << " gets a two.\n";
    else if (c.getValue() == 3)
        cout << nameOfPlayer << " gets a three.\n";
    else if (c.getValue() == 4)
        cout << nameOfPlayer << " gets a four.\n";
    else if (c.getValue() == 5)
        cout << nameOfPlayer << " gets a five.\n";
    else if (c.getValue() == 6)
        cout << nameOfPlayer << " gets a six.\n";
    else if (c.getValue() == 7)
        cout << nameOfPlayer << " gets a seven.\n";
    else if (c.getValue() == 8)
        cout << nameOfPlayer << " gets an eight.\n";
    else if (c.getValue() == 9)
        cout << nameOfPlayer << " gets a nine.\n";
    else if (c.getValue() == 10)
        cout << nameOfPlayer << " gets a ten.\n";
    else if (c.getValue() == 11)
        cout << nameOfPlayer << " gets a jack.\n";
    else if (c.getValue() == 12)
        cout << nameOfPlayer << " gets a queen.\n";
    else if (c.getValue() == 13)
        cout << nameOfPlayer << " gets a king.\n";
}

