/*
 Authors: Samantha Casler & Philip Cesani
 Serial Number: 16 & 19
 Due Date: Wednesday March , 2019
 Programming Assignment Number 3
 Spring 2019 - CS 3358 - 252

 Instructor: Husain Gholoom

 Program will ask the user to input an integer and then will ask
 what integer manipulation the user wants to perform on the integer:
 Finding out if the integer is a multiple of 7, 11, or 13.
 If the sum of the numbers digits if even or odd.
 What the square root it.
 If the number is prime or not.
 or If the number is perfect.
 Then it will ask the user if they want to run another operation or terminate the program.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;


// myInt Class - Holds the users integer to be manipulated and the square root value.
class myInt
{
private:
    int number; // user integer
    double squareRootValue; //holds the square root value of the user integer
public:
    void setNumber (int); //sets the user integer
    void multiple (); //determines if the user int is a multiple of 7,11,13
    void sumODigits (); //determines if the user int's sum is even or odd
    void squareRoot (); //finds the square root of the user int
    void isPrime (); //finds out if the user int is prime or not
    void isPerfect (); //finds out if the user int is a perfect number or not.
};


//***********************************************************
//Sets the user integer and determines if it's valid
//***********************************************************
void myInt::setNumber(int n)
{
    do{
        if (n >= 0)
            number = n;
        else
            cout << "The number must be greater than or equal to 0.";
    }while (number < 0);
}
//***********************************************************
//Determines if the user int is a multiple of 7,11,13
//***********************************************************
void myInt::multiple ()
{
    if ((number-7 * (number/7)) == 0){
        cout << endl << number << " is a multiple of 7.\n\n";
        if((number-11 * (number/11)) == 0){
            cout << endl << number << " is a multiple of 11.\n\n";
            if((number-13 * (number/13)) == 0){
                cout << endl << number << " is a multiple of 13.\n\n";
            }
        }
        else if((number-13 * (number/13))){
            cout << endl << number << " is a multiple of 13.\n\n";
        }
    }
    else if ((number-11 * (number/11)) == 0){
        cout << endl << number << " is a multiple of 11.\n\n";
        if((number-13 * (number/13)) == 0){
            cout << endl << number << " is a multiple of 13.\n\n";
        }
    }
    else if ((number-13 * (number/13)) == 0){
        cout << endl << number << " is a multiple of 13.\n\n";
    }
    else{
        cout << endl << number << " is not a multiple of 7, 11, or 13. \n\n";
    }
}
//************************************************************
//Determines if the user int's sum is even or odd
//************************************************************
void myInt::sumODigits ()
{
    int sum = 0;
    int tempNumber = number;
    int remainderCatch = 0;

    while(tempNumber>0){
        remainderCatch = tempNumber%10;
        sum+=remainderCatch;
        tempNumber=tempNumber/10;
    }

    if (sum%2 == 0){
        cout << "The sum is even.\n\n";
    }
    else
        cout << "The sum is odd.\n\n";
}
//**************************************************************
//Finds the square root of the user int
//**************************************************************
void myInt::squareRoot ()
{
    squareRootValue = number;
    squareRootValue = (sqrt(squareRootValue));
    cout << "The square root value is: " << squareRootValue << endl << endl;

}
//************************************************************
//Finds out if the user int is prime or not
//************************************************************
void myInt::isPrime ()
{
    bool isPrime = true;
    for (int i = 2; i < number; i++){
        if(number%i == 0){
            isPrime = false;
            break;
        }
    }

    if (!isPrime){
        cout << number << " is not prime.\n\n";
    }
    else{
        cout << number << " is prime.\n\n";
    }

}
//************************************************************
//Finds out if the user int is a perfect number or not.
//************************************************************
void myInt::isPerfect ()
{
    int sum = 0;
    int count = 1;
    while (count<number){
        if(number%count == 0){
            sum = sum+count;
        }
        count++;
    }
    if(sum==number){
        cout << "The number is a perfect number.\n\n";
    }
    else{
        cout << "The number is not a perfect number.\n\n";
    }
}

int main ()
{

    cout << "Welcome to my Integer Manipulations Program.\n";

    myInt userInt; //Declares the userInt object
    int userNumber; //Gets the user choice
    char userChoice; //Char that holds 'A','B','C','D','E','F','Z' to determine what operation to perform
    char runAgain; //Holds 'Y','y','N','n' to determine if the player wants to select another operation
    bool again = false; //Flag for running the game again

    //Get's the user's number
    cout << "\nPlease enter a number you would like to manipulate: ";
    cin >> userNumber;

    //Sorts the user's int in user.Int
    userInt.setNumber(userNumber);

    //Plays the game
    do{
        //User interface
        cout << "\n\nWhat would you like to do to that number?\n";
        cout << "Please select one of the following: \n";
        cout << "A. Is it a multiple of 7, 11, or 13?\n";
        cout << "B. Is the sum of its digits odd or even?\n";
        cout << "C. What is the square root value?\n";
        cout << "D. Is it a prime number?\n";
        cout << "E. Is it a perfect number (ie. the sum of the factors is equal to itself)?\n";
        cout << "F. All of the above\n";
        cout << "Z. exit\n";

        //Get's the user's choice
        cin >> userChoice;

        userChoice = toupper (userChoice);

        //Determines which operation to run based off of the user's choice
        if (userChoice == 'A' ||userChoice == 'B'|| userChoice == 'C'||userChoice == 'D'||userChoice == 'E'
            ||userChoice == 'F'||userChoice == 'Z'){

            switch (userChoice)
            {
                //Runs the multiple operations
                case 'A':
                    userInt.multiple();
                    break;
                //Runs the sum of digits operations
                case 'B':
                    userInt.sumODigits ();
                    break;
                //Runs the square root operations
                case 'C':
                    userInt.squareRoot();
                    break;
                //Runs the isPrime operations
                case 'D':
                    userInt.isPrime ();
                    break;
                //Runs the isPerfect operations
                case 'E':
                    userInt.isPerfect ();
                    break;
                //Runs the all operations
                case 'F':
                    userInt.multiple ();
                    userInt.sumODigits ();
                    userInt.squareRoot ();
                    userInt.isPrime ();
                    userInt.isPerfect ();
                    break;
                //Ends the program
                case 'Z':
                    cout << "\n\nThis program is implemented by Samantha Casler and Philip Cesani\n";
                    cout << "March - 2019\n";
                    return 0;
            }
            //Asks the user if they would like to run another operation
            cout << "Would you like to re-run the program again\n";
            cout << "Enter Y or N\t--->\t";
            cin >> runAgain;
            //If true, run again.
            if(runAgain == 'Y' || runAgain == 'y'){
                again = true;
            }
            //Else - end the program
            else if (runAgain == 'N' || runAgain == 'n'){
                cout << "\n\nThis program is implemented by Samantha Casler and Philip Cesani\n";
                cout << "March - 2019\n";
                return 0;
            }
            //User input validation. Makes sure they enter 'Y','y','N','n' and runs the appropriate response
            else{
                while (runAgain != 'Y' || runAgain != 'N' || runAgain != 'y' || runAgain != 'n'){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Error *** Invalid choice - Must enter y|Y or n|N\n\n";
                    cout << "Would you like to re-run the program again\n";
                    cout << "Enter Y or N\t--->\t";
                    cin >> runAgain;
                    if (runAgain == 'Y' || runAgain == 'y')
                    {
                        again = true;
                        break;
                    }
                    else if (runAgain == 'N' || runAgain == 'n')
                    {
                        cout << "\n\nThis program is implemented by Samantha Casler and Philip Cesani\n";
                        cout << "March - 2019\n";
                        return 0;
                    }
                }
            }
        }
        else
            cout << "Invalid choice! Please enter valid choice.\n";

    }while (userChoice != 'Z' || again);
}
