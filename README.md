# Playing With Numbers Program

Feb 20, 2022


## Objectives in Practice:

- Develop, compile, and run a C++ program that requires the definition and use of functions that utilize fundamental algorithms studied to perform common tasks, such as finding the max and min of a data set, counting, summing, tracking a previous value, searching and sorting, reading until EOF, etc. in programs to solve problems.
  
- Transfer a program to the Unix server, use the G++ compiler to compile a program and execute a c++ program that you have written


## The Instructions That Were Given for the Project:


- Write a C++ program to run a menu-driven program with the following choices:
  - Compute all the Cousin Prime Pairs less than a number
  - Compute if a number is a Perfect number
  - Quit

- Follow the course coding standards outlined in Coding Standards_ (COP3363 Introduction to Programming in C++ for Majors).docx ([Coding Standards](https://canvas.fsu.edu/courses/193490/files/15396757/download)) .

- Include the basic header in your program Header for Assignments.docx ([Required Header Template](https://canvas.fsu.edu/courses/193490/files/15396772/download)) , and print a welcome message to the user.

1. Write a function called getValidUserInputPosNumGT0 that allows a user to enter in an integer and validated that the number is > 0. It must have a pass by reference parameter that will store the value selected by the user.

        void GetValidUserInputPosNumGT0(long int &num);

2. Write a function called SumOfDivisors that takes a number as a value parameter. It returns the sum of the divisors of the number.

        long int SumOfDivisors(long int num);

3. Write a function called IsPrime that takes a number as a value parameter. It returns true if the number is prime and false otherwise.

        bool IsPrime(long int num);

4. Write a function called DisplayCousinPrimes that takes a number as a value parameter. It displays all the cousin prime pairs less than the number. See [Cousin Prime Wiki](https://en.wikipedia.org/wiki/Cousin_prime)

        void DisplayCousinPrimes(long int num);
  

5. Write a function called Perfect that takes a number as a value parameter. It returns true if the number is perfect and false otherwise. See [Perfect Number Wiki](https://en.wikipedia.org/wiki/Perfect_number)

        bool IsPerfect(long int num)

6. Add comments wherever necessary. 


## How to Run the Program:

- Use ```g++ playingWithNumbers.cpp -o playingWithNumbers.exe``` and then ```playingWithNumbers.exe``` in a Linux terminal to compile and run.
