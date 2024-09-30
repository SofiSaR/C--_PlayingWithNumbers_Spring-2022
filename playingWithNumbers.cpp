/* Name: Sofia Sanchez
Date: 02/20/2022
Section: 0011
Assignment: Playing With Numbers Program
Due Date: 02/20/2022
About this project: This program computes all the cousin primes up to a number
inputted by the user, determines if the number entered is a perfect number, or
quits, depending on what the user wants to do.
Assumptions: NA
All work below was performed by Sofia Sanchez */

#include <iostream>
using namespace std;

//function prototypes
void GetValidUserInputPosNumGT0(long int &);
void DisplayCousinPrimes(long int);
bool IsPrime(long int);
bool IsPerfect(long int);
long int SumOfDivisors(long int);

//main function
int main() {
    //define variable that will store the user's option selection
    int choice;
    /* define variable that will store the upper limit inputted by the user
    for choice 1 */
    long int maxValue;
    /* define variable that will store the number the user wants to test
    for perfection */
    long int numForPerfectTest;

    //welcome message
    cout << "Welcome to the Playing With Numbers Program! \n";
    //display options
    cout << "1) Compute all the cousin prime pairs less than a number \n"
         << "2) Compute if a number is a perfect number \n" << "3) Quit \n";
    //prompt user for their choice
    cout << "To get started, select an option by entering the number"
         << " corresponding to it: \n";
    //stores the value entered by the user in the choice variable
    cin >> choice;
    //as long as the user enters something that isn't either of the 3 choices,..
    while (choice != 1 && choice != 2 && choice != 3) {
        //re-prompt
        cout << "Please enter either 1, 2, or 3: \n";
        //stores input in choice variable
        cin >> choice;
    }
    //as long as the user entered either of the first two options,...
    while (choice == 1 || choice == 2) {
        //if the user chose the first option,...
        if (choice == 1) {
            //prompt user for max value
            cout << "Enter a number to set the upper limit for the range of \n"
                 << "numbers inside which you would like to look for cousin \n"
                 << "prime numbers. This value should be at least 1: \n";
            //stores the value entered by the user in the maxValue variable
            cin >> maxValue;
            //call GetValidUserInputPosNumGT0 function to validate user input
            GetValidUserInputPosNumGT0(maxValue);
            //call DisplayCousinPrimes function
            DisplayCousinPrimes(maxValue);
        }
        //if the user chose the second option,...
        if (choice == 2) {
            //prompt user for the number they want to test
            cout << "Enter a number to test if it is a perfect number. \n"
                 << "This number should be at least 1: \n";
            //stores user input in numForPerfectTest variable
            cin >> numForPerfectTest;
            //call GetValidUserInputPosNumGT0 function to validate user input
            GetValidUserInputPosNumGT0(numForPerfectTest);
            /* if the value of IsPerfect given numForPerfectTest (calls
            IsPerfect function inside if statement) is true,... */
            if (IsPerfect(numForPerfectTest)) {
                //say the number the user entered is perfect
                cout << numForPerfectTest << " is perfect. \n";
            }
            //otherwise,...
            else {
                //say the number the user entered is not perfect
                cout << numForPerfectTest << " is not perfect. \n";
            }
        }
        //display options again
        cout << "1) Compute all the cousin prime pairs less than a number \n"
             << "2) Compute if a number is a perfect number \n" << "3) Quit \n";
        //prompt
        cout << "Select an option by entering the number"
             << " corresponding to it: \n";
        //stores the value entered by the user in the choice variable
        cin >> choice;
        //input validation for choices again
        while (choice != 1 && choice != 2 && choice != 3) {
            cout << "Please enter either 1, 2, or 3: \n";
            cin >> choice;
        }
    }
    //in any other case (if option 3 is chosen), end the program
    return 0;
}
//input validation function
void GetValidUserInputPosNumGT0(long int &numChosen) {
    //as long as the user enters a number less than or equal to 0,...
    while (numChosen <= 0) {
        //display error message / re-prompt
        cout << "The value you entered is invalid. Please input an integer"
             << " of 1 or more: \n";
        //replace the variable value with the newly inputted value
        cin >> numChosen;
    }
}
//function used to display cousin primes
void DisplayCousinPrimes(long int upperLimit) {
    //declare counter variable and initialize it to 1
    long int counter = 1;
    //declare counterIsPrime bool variable
    bool counterIsPrime;
    //declare cousinIsPrime bool variable
    bool cousinIsPrime;
    //declare numberOfPrimePairs variable and initialize it at 0
    int numberOfPrimePairs = 0;
    //as long as counter is less than the max value inputted,...
    while (counter < upperLimit) {
        /* call IsPrime function for both counter and counter+4 to determine if
        they are prime and then store the results in the counterIsPrime and
        cousinIsPrime variables */
        counterIsPrime = IsPrime(counter);
        cousinIsPrime = IsPrime(counter + 4);
        /* if counterIsPrime and cousinIsPrime are true,... */
        if (counterIsPrime && cousinIsPrime) {
            //display counter and counter+4 as a cousin prime pair
            cout << "(" << counter << "," << (counter + 4) << ") \n";
            //increment the number of prime pairs by 1
            numberOfPrimePairs++;
        }
        //increment counter by 1
        counter++;
    }
    //if the number of prime pairs equals 0,...
    if (numberOfPrimePairs == 0) {
        //say that there were no cousin prime numbers found
        cout << "No cousin prime numbers found. \n";
    }
    //if the number of prime pairs is equal to 1,...
    else if (numberOfPrimePairs == 1) {
        //say that there is 1 cousin prime pair found
        cout << numberOfPrimePairs << " cousin prime pair found. \n";
    }
    //otherwise,...
    else {
        //display the number of prime pairs found in the following sentence
        cout << numberOfPrimePairs << " cousin prime pairs found. \n";
    }
}
//function used to determine if counter and counter+4 are prime
bool IsPrime(long int num) {
    //declare divisor variable and initialize it to 1
    long int divisor = 1;
    //declare numNotDivisible variable and initialize it to true
    bool numNotDivisible = true;
    /* as long as the divisor is less than the number being used (either counter
    or counter+4), or while the divisor and number are both equal to 1,... */
    while (divisor < num || (divisor == 1 && num == 1)) {
        /* if the divisor is more than 1 and the number is divisible by the
        divisor, or if the number is 1 (1 is not a prime number),... */
        if ((num % divisor == 0 && divisor > 1) || num == 1) {
            //set numNotDivisible to false
            numNotDivisible = false;
        }
        //increment divisor by 1
        divisor++;
    }
    /* end function with the return of the value of numNotDivisible
    to the DisplayCousinPrimes function */
    return numNotDivisible;
}
//function determines whether the number entered by the user is perfect
bool IsPerfect(long int numBeingTested) {
    //define boolean variable perfect
    bool perfect;
    /* if the number the user entered equals sum of its divisors as determined
    by the SumOfDivisors function being called,... */
    if (numBeingTested == SumOfDivisors(numBeingTested)) {
        //set perfect variable to true
        perfect = true;
    }
    //otherwise,...
    else {
        //set perfect variable to false
        perfect = false;
    }
    //end function with return of the value of perfect to the main function
    return perfect;
}
//function sums all the divisors of the number the user entered for choice 2
long int SumOfDivisors(long int numBeingTested) {
    //define variable divisor and initialize it to 1
    long int divisor = 1;
    //define variable sumDivisors and initialize it to 0
    long int sumDivisors = 0;
    //as long as the divisor is less than the number being tested,...
    while (divisor < numBeingTested) {
        //if the number being tested is divisible by the divisor,
        if (numBeingTested % divisor == 0) {
            //add the value of divisor to the sumDivisors variable
            sumDivisors += divisor;
        }
        //increment divisor by 1
        divisor++;
    }
    //end function with return of sumDivisors value to IsPerfect function
    return sumDivisors;
}

