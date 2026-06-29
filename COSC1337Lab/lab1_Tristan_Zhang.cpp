/* Tristan Zhang

 Lab 1 Solution

 This program lets the user choose options of which card game to play. The High Card game  generates two random numbers from 1-13 representing two players. Card values are ranked highest to lowest: 1, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 - ace, king, queen, jack, ten, nine, eight, seven, six, five, four, three, two. Then the game displays which player has won.
 There are three possible card games with a function representing each: High Card, Low Card of Three, and One Hand Poker. The High Card game function uses a random number generating function to generate two random numbers. The main function displays the menu options and contains the code to let the user keep entering input to choose which game to play until the user chooses to quit.

*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void highCard();
int getOneRandomNum();
void lowCardOfThree();
void oneHandPoker();

/* Function:  main

Inputs:    no inputs

Outputs:  returns a zero to end the program

Purpose:   This function contains the main logic of displaying the menu and options and letting the user keep choosing what game they play and playing the game until the user chooses the option to quit.
*/

int main() {
    // Seed once
    srand(static_cast<unsigned>(time(0)));
    
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
    //Generate two random numbers representing two separate players
    int playerOneNum;
    int playerTwoNum;
    playerOneNum = getOneRandomNum();
    playerTwoNum = getOneRandomNum();
    
    //Display player 1's card
    if (playerOneNum == 1)
        cout << "Player 1 gets an ace.\n";
    else if (playerOneNum == 2)
        cout << "Player 1 gets a two.\n";
    else if (playerOneNum == 3)
        cout << "Player 1 gets a three.\n";
    else if (playerOneNum == 4)
        cout << "Player 1 gets a four.\n";
    else if (playerOneNum == 5)
        cout << "Player 1 gets a five.\n";
    else if (playerOneNum == 6)
        cout << "Player 1 gets a six.\n";
    else if (playerOneNum == 7)
        cout << "Player 1 gets a seven.\n";
    else if (playerOneNum == 8)
        cout << "Player 1 gets an eight.\n";
    else if (playerOneNum == 9)
        cout << "Player 1 gets a nine.\n";
    else if (playerOneNum == 10)
        cout << "Player 1 gets a ten.\n";
    else if (playerOneNum == 11)
        cout << "Player 1 gets a jack.\n";
    else if (playerOneNum == 12)
        cout << "Player 1 gets a queen.\n";
    else if (playerOneNum == 13)
        cout << "Player 1 gets a king.\n";
    
    //Display player 2's card
    if (playerTwoNum == 1)
        cout << "Player 2 gets an ace.\n";
    else if (playerTwoNum == 2)
        cout << "Player 2 gets a two.\n";
    else if (playerTwoNum == 3)
        cout << "Player 2 gets a three.\n";
    else if (playerTwoNum == 4)
        cout << "Player 2 gets a four.\n";
    else if (playerTwoNum == 5)
        cout << "Player 2 gets a five.\n";
    else if (playerTwoNum == 6)
        cout << "Player 2 gets a six.\n";
    else if (playerTwoNum == 7)
        cout << "Player 2 gets a seven.\n";
    else if (playerTwoNum == 8)
        cout << "Player 2 gets an eight.\n";
    else if (playerTwoNum == 9)
        cout << "Player 2 gets a nine.\n";
    else if (playerTwoNum == 10)
        cout << "Player 2 gets a ten.\n";
    else if (playerTwoNum == 11)
        cout << "Player 2 gets a jack.\n";
    else if (playerTwoNum == 12)
        cout << "Player 2 gets a queen.\n";
    else if (playerTwoNum == 13)
        cout << "Player 2 gets a king.\n";
    
    //Compare players' cards and display who won
    if (!(playerOneNum == 1 || playerTwoNum == 1))
    {
        if (playerOneNum > playerTwoNum)
            cout << "Player 1 wins.\n";
        else if (playerOneNum < playerTwoNum)
            cout << "Player 2 wins.\n";
        else
            cout << "It's a tie.\n";
    }
    else if (playerOneNum < playerTwoNum)
        cout << "Player 1 wins.\n";
    else if(playerOneNum > playerTwoNum)
        cout << "Player 2 wins.\n";
    else
        cout << "It's a tie.\n";
}

//Generate a random number from 1-13
int getOneRandomNum(){
    const int upperLimit = 13;
    int num = rand() % upperLimit + 1;
    return num;
}

//Function representing Low Card of Three game
void lowCardOfThree()
{
    cout << "This game has not been developed.";
}

//Function representing One Hand Poker game
void oneHandPoker(){
    cout << "This game has not been developed.";
}



