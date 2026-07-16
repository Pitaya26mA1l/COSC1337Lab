/* Tristan Zhang

 Lab 3 Solution

    This program lets the user choose options of which card game to play.
 The High Card game generates two cards, one for each player with card
 values corresponding to random numbers from 1-13. Card values are
 ranked highest to lowest: 1, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 -
 ace, king, queen, jack, ten, nine, eight, seven, six, five, four, three,
 two. Then the game displays which player has won with the highest card.
    In more detail, the High Card game function lets the two players input
 their names and creates two Card objects, one for each player, and utilizes
 the deal() method in the Card class to deal each player a random value for
 their card. The values of the cards are then compared to each other and then
 the winner is displayed.
    The Low Card of Three game generates two decks of three cards each, one
 to each player with the same range of card values and same card value rank
 as the High Card game. Then the game displays which player has won with the
 lowest value of their deck of cards.
    In more detail, the Low Card of Three game function lets the two players
 input their names and creates two arrays of Card objects each of size three,
 one for each player, and utilizes the deal() method in the Card class to deal
 a random value for each card in each player's' deck. The lowest card of each
 player's deck is then compared and it is displayed which player with the
 lowest has the lowest card and therefore wins.
    There are three possible card games with a function representing each:
 High Card, Low Card of Three, and One Hand Poker. The main function displays
 the menu options and contains the code to let the user keep entering input
 to choose which game to play until the user chooses to quit.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "lab3_Hand_Class_Tristan_Zhang.cpp"

using namespace std;

void highCard();
void lowCardOfThree();
void oneHandPoker();

/* Function:  main

Inputs:   no inputs

Outputs:  returns a zero to end the program

Purpose:  This function contains the main logic of displaying the menu and
options and letting the user keep choosing what game they play and playing
the game until the user chooses the option to quit.
*/

int main() {
    
    int userChoice;
    
    /*
    Display menu of choices and let the user choose and play the game corresponding
    to the choice until the user quits. The loop checks if the user quits and if
    not allows the user to keep choosing what game and contains code that calls the
    function to play the corresponding game.
    */
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
        while(userChoice < 1 || userChoice > 4)
        {
            cout << "Invalid choice - try again\n";
            cout << "Enter choice: ";
            cin >> userChoice;
        }
    
        /*
        Decide which choice was entered and call the corresponding function
        if choice 1-3 or quit if choice 4. The cin.ignore() method skips the
        newline character inputted by the user so when the High Card game
        function is called and the function outputs the option for the first
        player to enter their name, the newline does not get processed by the
        cin object corresponding to that output, or else the first player will
        not be able to enter their name.
        */
        cin.ignore();
        if(userChoice == 1)
            highCard();
        else if(userChoice == 2)
            lowCardOfThree();
        else if(userChoice == 3)
            oneHandPoker();
        else
            cout << "You quit.\n";
        }
    while(userChoice != 4);
    return 0;
}

/********************************************************************/

/* Function:  highCard

Inputs:   none

Outputs:  The function is void because it's purpose is to play
the game and display the results of the game.

Purpose:  This function lets the two players input their names
and creates two Card objects, one for each player, and utilizes
the deal() method in the Card class to deal each player a random
value for their card. The values of the cards are then compared
to each other and then the winner is displayed.
*/

void highCard() {
    //Get players' names.
    string playerOneName, playerTwoName;
    
    cout << "Player 1, enter name...";
    getline(cin, playerOneName);
    cout << "Player 2, enter name...";
    getline(cin, playerTwoName);
    
    //Generate a card for each player and deal each card a value.
    Card cardPlayer1;
    Card cardPlayer2;
    
    cardPlayer1.deal();
    cardPlayer2.deal();
    

    
    //Display player 1's card
    string cardPlayer1FaceValueName;
    string cardPlayer1suitName;
    cardPlayer1.getFaceValue(cardPlayer1FaceValueName, cardPlayer1suitName);
    cout << playerOneName << " gets a card with a face value of " << cardPlayer1FaceValueName << " and with a suit of " << cardPlayer1suitName << ".\n";
    
    //Display player 2's card
    string cardPlayer2FaceValueName;
    string cardPlayer2suitName;
    cardPlayer2.getFaceValue(cardPlayer2FaceValueName, cardPlayer2suitName);
    cout << playerTwoName << " gets a card with a face value of " << cardPlayer2FaceValueName << " and with a suit of " << cardPlayer2suitName << ".\n";
    
    //Compare players' cards and display who won
    if(!(cardPlayer1.getValue() == 1 || cardPlayer2.getValue() == 1))
    {
        if(cardPlayer1.getValue() > cardPlayer2.getValue())
            cout << playerOneName << " wins with a card face value of " << cardPlayer1FaceValueName << ".\n";
        else if(cardPlayer1.getValue() < cardPlayer2.getValue())
            cout << playerTwoName << " wins with a card face value of " << cardPlayer2FaceValueName << ".\n";
        else
            cout << "Since both players get equal card face values, it's a tie.\n";
    }
    else if(cardPlayer1.getValue() < cardPlayer2.getValue())
        cout << playerOneName << " wins with a card face value of " << cardPlayer1FaceValueName << ".\n";
    else if(cardPlayer1.getValue() > cardPlayer2.getValue())
        cout << playerTwoName << " wins with a card face value of " << cardPlayer2FaceValueName << ".\n";
    else
        cout << "Since both players get equal card face values, it's a tie.\n";

}

/* Function:  Low Card of Three
 
 Inputs:   none

 Outputs:  The function is void because it's purpose is to play
 the game and display the results of the game.

 Purpose:  This function generates two decks of three cards each, one
 to each player with the same range of card values and same card value rank
 as the High Card game. Then the game displays which player has won with the
 lowest value of their deck of cards.
 */

void lowCardOfThree() {
    //Get players' names.
    string playerOneName, playerTwoName;
    
    cout << "Player 1, enter name...";
    getline(cin, playerOneName);
    cout << "Player 2, enter name...";
    getline(cin, playerTwoName);
    
    //Generate a hand of cards for each player.
    Hand playerOneHand;
    Hand playerTwoHand;
    
    //Deal each player's cards in their hand of cards
    playerOneHand.dealHand();
    playerTwoHand.dealHand();
    
    /*
    Display player 1's cards in sorted order.
    */
    playerOneHand.sortHands();
    string playerOneCardFaceValueName;
    string playerOneCardSuitName;
    string playerTwoCardFaceValueName;
    string playerTwoCardSuitName;
    
    cout << playerOneName << " has card face values and suits in sorted ascending order of face values:\n";
    playerOneHand.getCardFaceValues(0, playerOneCardFaceValueName, playerOneCardSuitName);
    cout << "First card's face value, suit: " << playerOneCardFaceValueName << ", " << playerOneCardSuitName << "\n";
    playerOneHand.getCardFaceValues(1, playerOneCardFaceValueName, playerOneCardSuitName);
    cout << "Second card's face value, suit: " << playerOneCardFaceValueName << ", " << playerOneCardSuitName << "\n";
    playerOneHand.getCardFaceValues(2, playerOneCardFaceValueName, playerOneCardSuitName);
    cout << "Third card's face value, suit: " << playerOneCardFaceValueName << ", " << playerOneCardSuitName << "\n\n";
    
    /*
    Display player 2's cards in sorted order.
    */
    playerTwoHand.sortHands();
    
    cout << playerTwoName << " has card face values and suits in sorted ascending order of face values:\n";
    playerTwoHand.getCardFaceValues(0, playerTwoCardFaceValueName, playerTwoCardSuitName);
    cout << "First card's face value, suit: " << playerTwoCardFaceValueName << ", " << playerTwoCardSuitName << "\n";
    playerTwoHand.getCardFaceValues(1, playerTwoCardFaceValueName, playerTwoCardSuitName);
    cout << "Second card's face value, suit: " << playerTwoCardFaceValueName << ", " << playerTwoCardSuitName << "\n";
    playerTwoHand.getCardFaceValues(2, playerTwoCardFaceValueName, playerTwoCardSuitName);
    cout << "Third card's face value, suit: " << playerTwoCardFaceValueName << ", " << playerTwoCardSuitName << "\n\n";
    
    //Compare players' lowest cards
    int playerOneValueInt;
    int playerOneSuitInt;
    int playerTwoValueInt;
    int playerTwoSuitInt;
    
    playerOneHand.getCardNumericValues(0, playerOneValueInt, playerOneSuitInt);
    playerTwoHand.getCardNumericValues(0, playerTwoValueInt, playerTwoSuitInt);
    
    playerOneHand.getCardFaceValues(0, playerOneCardFaceValueName, playerOneCardSuitName);
    playerTwoHand.getCardFaceValues(0, playerTwoCardFaceValueName, playerTwoCardSuitName);
    
    //Display the winner and their lowest card.
    if(playerOneValueInt > playerTwoValueInt)
        cout << playerOneName << " wins with a card face value of " << playerOneCardFaceValueName << ".\n";
    else if(playerOneValueInt < playerTwoValueInt)
        cout << playerTwoName << " wins with a card face value of " << playerTwoCardFaceValueName << ".\n";
    else
        cout << "It's a tie since " << playerOneName << " got a card face value of " << playerOneCardFaceValueName << " and " << playerTwoName << " got a card face value of " << playerTwoCardFaceValueName << ".\n";
}

//Function representing One Hand Poker game
void oneHandPoker() {
    cout << "This game has not been developed.\n";
}
