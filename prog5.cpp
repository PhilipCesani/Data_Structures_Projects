/*
 Authors: Samantha Casler & Philip Cesani
 Serial Number: 16 & 19
 Group Number: 4
 Due Date: Monday April 8, 2019
 Programming Assignment Number 5
 Spring 2019 - CS 3358 - 252

 Instructor: Husain Gholoom

 Program will generate an array at a user declared size with
 random integer number elements. The program will then run a few functions
 which utilze recursion to: print the array, print the array backwards,
 find the powers of 1 to the first element of the array, find the power of an
 elements, and finally, determine if the elements in an array are prime.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function to print array using recursion
int print(int m [], int SIZE, int i ) {
    if (i == SIZE)
        return 0;
    else
        cout << " " << m[i];
    print(m, SIZE, i+1); // The last executed statement is recursive call
}

//Prints the array backwards using recursion
int printBackward(int m [], int i ) {
    if (i < 0)
        return 0;
    else
        cout << " " << m[i];
    printBackward(m, i-1); // The last executed statement is recursive call
}

//Finds the power of a number using recursion
int power(int x, int y){
    if (y == 0)
        return (1);
    else if (y == 1)
        return (x);
    else
        return (x * power(x, y-1));
}    //    end    of    power()

//Determines if the elements in an array are prime or not using recursion
void isArrayPrime(int array[], int i, int size){
    bool isPrime = true; //check if number is prime
    if (size != 0){
        if(array[i] <= 1){
            cout << "The number " << array[i] << " is Not Prime.\n";
        }

        for(int j = 2; j < array[i]; j++){ //runs through array checking to see if prime
            if (array[i] % j == 0){
                cout << "The number " << array[i] << " is Not Prime.\n";
                isPrime = false;
                break;
            }
        }
        if (isPrime) //if prime print number is prime
            cout << "The number " << array[i] << " is Prime.\n";
        isArrayPrime(array, i+1, size-1);
    }
}

int main ()
{
    srand(time(0));

    int arrSize; //holds how large the user wants the array
    const int MIN_SIZE = 5; //min size

    //Intro to application
    cout << "*** Welcome to My Recursion APP ***\n";
    cout << "Enter The array size. (Must be >= 5) -->\t";
    cin >> arrSize;

    //user input check, if inputed size is smaller than the min size, then end program
    if (arrSize < MIN_SIZE){

        cout << "\n\nInvalid arrays size. Size must >= 5.\n";
        cout << "\nSamantha Casler and Philip Cesani - Tweak Programming Director\n";
        cout << "April 2019";
        return 0;
    }

    int myArray[arrSize];

    //Generate random values for the array
    for (int i = 0; i<arrSize; i++){
        myArray[i] = 10 + (rand() % (375 - 10 + 1));
    }

    int endPrintForward = 0;

    //Prints array
    cout << "\nThe generated array is : ";
    print (myArray, arrSize, endPrintForward);

    //Prints array backwards
    int endPrintBackward = arrSize-1;
    cout << "\n\nReversed Array is : ";
    printBackward (myArray, endPrintBackward);

    int nSqrVal = myArray[0]; //Hold the first number in our array
    cout << "\n\nTable of square values " << "1 - " << nSqrVal;
    cout << "\n\nN\tN Squared\n";

    int powerOfNums; //Hold the power of the numbers being run though the power function

    // Loops through every number from 1 to the number that starts our
    // array and displays the squared value
    for (int j = 1; j <= nSqrVal; j++){
        cout << j << "\t";
        powerOfNums = power (j, 2);
        cout << powerOfNums << "\n";
    }


    int powerNum = myArray [arrSize-1]; //Holds the last number in the array
    int powerResult; //hold the results after the use of the power function
    cout << "\nPower function:\n";
    cout << powerNum << " raised to the 2nd power is : ";
    powerResult = power(powerNum, 2);
    cout << powerResult;

    //Displays the arrays elements and prints if they are prime or not
    cout << "\n\n\nIs It Prime : \n\n";
    int count = 0;
    isArrayPrime(myArray, count, arrSize);

    cout << "\nSamantha Casler and Philip Cesani - Tweak Programming Director\n";
    cout << "April 2019\n";

    return 0;
}
