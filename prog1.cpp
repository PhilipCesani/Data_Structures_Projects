/*
Authors: Samantha Casler & Philip Cesani
Serial Number: 16 & 19
Due Date: Wednesday February 6, 2019
Programming Assingment Number 1
Spring 2019 - CS 3358 - 252

Instructor: Husain Gholoom

Program will generate a number for the player to guess and give
clues as to how their guess relates to the winning number as
well as notify the player if they have won and ask them if they would
like to play again.

*/

#include <iostream>
#include <ctime>
#include <string>
#include <cctype>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <climits>

using namespace std;

void printIntro(); // Function to print instructions before the player guesses
void getGameNumber(string []); // Function to get the random number the player will be guessing
void getPlayerGuess(string []);// Function to get the players guess of the random number
bool compareAndCheckAnswer(string[], string[]);// Function to compare player answer to the correct answer
// and provide feedback hints
void playGame (); // Function to run game
void printOutro (); // Function to print names and date

int main(int argc, const char * argv[]) {

    printIntro();  // Calling the printIntro function to give introduction to the game
    playGame ();   // Calling the playGame function to run the game
    cout<<endl;
    printOutro (); // Calling the printOutro function to print names and date
    return 0;
}

//Prints Game Intro
void printIntro(){
    cout << "Welcome to my game program\n";
    cout << "I am thinking of a 3-digit number. Try to guess what it is. Here are some clues:\n\n";
    cout << "When I say: \t It means:\n\n";
    cout << "\tB \t\t\t No digit is correct\n";
    cout << "\tP \t\t\t One digit is correct but in the wrong position\n";
    cout << "\tF \t\t\t One digit is correct and in the right position\n\n";
    cout << "I have thought up a number. You have 10 guesses to get it.\n\n";
}

//Generates A Random Non-Repeating 3-Digit Number
void getGameNumber(string gameNumber[]){
    srand(time(0));
    char numberHolder[10] = {'0','1','2','3','4','5','6','7','8','9'}; // Character array to hold possible characters for game number
    gameNumber[0] = (numberHolder[rand ()%9 + 1]);  // game number 0 holds first randomly generated number 0-9
    gameNumber[1] = (numberHolder[rand ()%9]);// game number 1 holds second randomly generated number 0-9
    gameNumber[2] = (numberHolder[rand ()%9]);// game number 2 holds third randomly generated number 0-9

    //While loop that will re-generate numbers if any are repeating
    while (gameNumber[0] == gameNumber[1] || gameNumber[0] == gameNumber[2] || gameNumber[1] == gameNumber[2]){
        gameNumber[0] = (numberHolder[rand ()%9 + 1]);
        gameNumber[1] = (numberHolder[rand ()%9]);
        gameNumber[2] = (numberHolder[rand ()%9]);
    }
    //cout << gameNumber[0] << gameNumber[1] << gameNumber[2];    // Left for grader convenience
}

//Function that will get player guess from user and validate that it is 3 characters and non repeating
void getPlayerGuess(string playerGuess[]){
    char tempPlayerAnswerContainer [3]; // temporary character array variable to hold player guess before being transfered into player guess variable
    cin >> tempPlayerAnswerContainer;
    playerGuess[0] = tempPlayerAnswerContainer[0];
    playerGuess[1] = tempPlayerAnswerContainer[1]; // transfer of temporary character array values into string array player guess
    playerGuess[2] = tempPlayerAnswerContainer[2];

    //While loop to make sure player guess is a 3 digit non repeating number and make the player re enter a number if not within parameters
    while(playerGuess[0] == playerGuess[1] || playerGuess[0] == playerGuess[2] || playerGuess[1] == playerGuess[2] || isalpha(tempPlayerAnswerContainer[0])
          || isalpha(tempPlayerAnswerContainer[1]) || isalpha(tempPlayerAnswerContainer[2]) || (unsigned)strlen(tempPlayerAnswerContainer) < 3 || (unsigned)strlen(tempPlayerAnswerContainer) > 3){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "INVALID INPUT! Please enter a non-repeating 3-digit number: ";
        cin >> tempPlayerAnswerContainer;
        playerGuess[0] = tempPlayerAnswerContainer[0];
        playerGuess[1] = tempPlayerAnswerContainer[1];
        playerGuess[2] = tempPlayerAnswerContainer[2];
    }
}

// Function to compare and check player guess against game number and return 1 if the guess is the correct number and 0 if the numbers don't match
bool compareAndCheckAnswer(string gameNumber[], string playerNumber[]){

    //if statement to determine if player guess is equal to game number and return 1 if they are equal
    if ((gameNumber[0]) == (playerNumber[0]) && (gameNumber[1]) == (playerNumber[1]) && (gameNumber[2]) == (playerNumber[2])){
        return true;
    }
    else if ((gameNumber[0]) == (playerNumber[0])){
        cout << "F";
        if ((gameNumber[1]) == (playerNumber[0])){
            cout << "P";                                  // compares player number 0 to game numbers and outputs
            if ((gameNumber[2]) == (playerNumber[0])){    // P if the number is in the wrong spot and F if in the right spot
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else if ((gameNumber[1]) == (playerNumber[1])){
            cout << "F";
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else if ((gameNumber[1]) == (playerNumber[2])){
            cout << "P";
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";

            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else {
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
    }
    else if ((gameNumber[0]) == (playerNumber[1])){
        cout << "P";
        if ((gameNumber[1]) == (playerNumber[0])){
            cout << "P";
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else if ((gameNumber[1]) == (playerNumber[1])){
            cout << "F";
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else if ((gameNumber[1]) == (playerNumber[2])){
            cout << "P";
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else {
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
    }
    else if ((gameNumber[0]) == (playerNumber[2])){
        cout << "P";
        if ((gameNumber[1]) == (playerNumber[0])){
            cout << "P";
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else if ((gameNumber[1]) == (playerNumber[1])){
            cout << "F";
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else if ((gameNumber[1]) == (playerNumber[2])){
            cout << "P";
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
        else {
            if ((gameNumber[2]) == (playerNumber[0])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[1])){
                cout << "P";
            }
            else if ((gameNumber[2]) == (playerNumber[2])){
                cout << "F";
            }
        }
    }
    else if ((gameNumber[1]) == (playerNumber[0])){
        cout << "P";
        if ((gameNumber[2]) == (playerNumber[0])){
            cout << "P";
        }                                                 //compares player number 1 to game numbers and outputs
        else if ((gameNumber[2]) == (playerNumber[1])){   // P if the number is in the wrong spot and F if in the right spot
            cout << "P";
        }
        else if ((gameNumber[2]) == (playerNumber[2])){
            cout << "F";
        }
    }
    else if ((gameNumber[1]) == (playerNumber[1])){
        cout << "F";
        if ((gameNumber[2]) == (playerNumber[0])){
            cout << "P";
        }
        else if ((gameNumber[2]) == (playerNumber[1])){
            cout << "P";
        }
        else if ((gameNumber[2]) == (playerNumber[2])){
            cout << "F";
        }
    }
    else if ((gameNumber[1]) == (playerNumber[2])){
        cout << "P";
        if ((gameNumber[2]) == (playerNumber[0])){
            cout << "P";
        }
        else if ((gameNumber[2]) == (playerNumber[1])){
            cout << "P";
        }
        else if ((gameNumber[2]) == (playerNumber[2])){
            cout << "F";
        }
    }
    else if ((gameNumber[2]) == (playerNumber[0])){
        cout << "P";                                 //compares player number 2 to game numbers and outputs
    }                                               // P if the number is in the wrong spot and F if in the right spot
    else if ((gameNumber[2]) == (playerNumber[1])){
        cout << "P";
    }
    else if ((gameNumber[2]) == (playerNumber[2])){
        cout << "F";
    }
    else{
        cout << "B";        // if the player guesses numbers that aren't in the game number then it will return B
    }
    return false;
}

// Function to call all the function needed to execute the game mechanics
void playGame (){
    string playerGuess[3];  // string array variable to hold 3 digit non repeating players guess
    string gameNumber[3];    // string array variable to hold 3 digit non repeating game number
    const int MAX_TURNS = 10;     // constant integer to hold the max number of turns allowed - 10
    bool isPlayingAgain = false; //bool variable to hold the choice of the player for playing again 1 = play again, 0 = quit
    bool isGameWon = false; //bool variable to hold the results of the player winning 1 = game won, 0 = game lost

    // Loop to execute once if the player only plays once and continues if the player wants to play again
    do{
        char playerAnswer ='N'; // character variable to hold if the player wants to play again Y/y = play again, N/n = quit
        isPlayingAgain = false; // sets isPlayingAgain variable to false (0) until an override is given after asking the player
        getGameNumber(gameNumber); // Calling function to generate random game number

        // Loop to iterate once for every attempt at guessing the number up to the max turns allowed
        for(int turnCounter = 1; turnCounter<=MAX_TURNS; turnCounter++){
            cout << endl << "Turn# " << turnCounter << " Enter your guess here: ";
            getPlayerGuess(playerGuess); // Calling function to get players guess

            //if statement to call compare and check function and will only execute if function returns 1 meaning the numbers are equal and the game has been won
            if((compareAndCheckAnswer(gameNumber, playerGuess))){
                isGameWon = true; // setting the bool variable to 1
                cout << "\nYou Win!" << endl;
                cout << "Would you like to play again (Y/N)?: ";
                cin >> playerAnswer;

                //if statement to check that playerAnswer is Y/y or N/n and not any other character
                if (playerAnswer == 'y'  || playerAnswer == 'Y'){
                    isPlayingAgain = true; // sets isPlayingAgain variable to 1 - true - if the player wants to play again
                }
                else if (playerAnswer == 'n'  || playerAnswer == 'N'){
                    isPlayingAgain = false; // sets isPlayingAgain variable to 0 - false - if the player wants to quit
                }
                else {
                    while (playerAnswer != 'Y' || playerAnswer != 'y' || playerAnswer != 'N' || playerAnswer != 'n'){
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "INVALID INPUT! PLEASE ENTER (Y/N) OR (y/n): ";
                        cin >> playerAnswer;
                        if (playerAnswer == 'Y' || playerAnswer == 'y'){
                            isPlayingAgain = true;
                            break;
                        }
                        else if (playerAnswer == 'N' || playerAnswer == 'n'){
                            isPlayingAgain = false;
                            break;
                        }
                        else {
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                            cout << "INVALID INPUT! PLEASE ENTER (Y/N) OR (y/n): ";
                            cin >> playerAnswer;
                            if (playerAnswer == 'Y' || playerAnswer == 'y'){
                                isPlayingAgain = true;
                                break;
                            }
                            else if (playerAnswer == 'N' || playerAnswer == 'n'){
                                isPlayingAgain = false;
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }

        // if statement to give correct answer and ask the user if they want to play again if the user did not get the correct answer within 10 tries
        if (!isGameWon){
            cout << "\n\nGame Over!" << endl;
            cout << "Sorry, You exceeded your number of guess" << endl;
            cout << "The guessed number is " << gameNumber[0] << gameNumber[1] << gameNumber[2] << endl << endl;
            cout << "Would you like to play again (Y/N)?: ";
            cin >> playerAnswer;

            //if statement to check that playerAnswer is Y/y or N/n and not any other character
            if (playerAnswer == 'y'  || playerAnswer == 'Y'){
                isPlayingAgain = true;
            }
            else if (playerAnswer == 'n'  || playerAnswer == 'N'){
                isPlayingAgain = false;
            }
            else{
                while (playerAnswer != 'Y' || playerAnswer != 'y' || playerAnswer != 'N' || playerAnswer != 'n'){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "INVALID INPUT! PLEASE ENTER (Y/N) OR (y/n): ";
                    cin >> playerAnswer;
                    if (playerAnswer == 'Y' || playerAnswer == 'y'){
                        isPlayingAgain = true;
                        break;
                    }
                    else if (playerAnswer == 'N' || playerAnswer == 'n'){
                        isPlayingAgain = false;
                        break;
                    }
                    else {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "INVALID INPUT! PLEASE ENTER (Y/N) OR (y/n): ";
                        cin >> playerAnswer;
                        if (playerAnswer == 'Y' || playerAnswer == 'y'){
                            isPlayingAgain = true;
                            break;
                        }
                        else if (playerAnswer == 'N' || playerAnswer == 'n'){
                            isPlayingAgain = false;
                            break;
                        }
                    }
                }
            }
        }
    }while(isPlayingAgain);
}

//Function to print names and date
void printOutro (){
    cout << "Implemented by Samantha Casler and Philip Cesani" <<endl;
    cout << "2-6-2019" <<endl;
}
