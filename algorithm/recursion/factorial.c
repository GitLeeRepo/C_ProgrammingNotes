/////////////////////////////////////////////////////////////////////////////////////////////////
// factorial.c
//
// Using recursion to calculate the factorial (the product of an integer and all integers 
// below it) for the value provided on the command line
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

unsigned int iterations = 0;

unsigned long long factorial(unsigned long long n) {
    iterations++;
    if (n == 1)
        return 1;
    else
        return n*factorial(n-1);
}


int main(int argc, char *argv[]) {
    const int maxNum = 20; // largest before it starts to overflow the unsigned long long

    if (argc != 2) {
        printf("usage: factorial <num> - where num is a positive integer <= %d\n", maxNum);
        return 1;
    }
        
    int input=atoi(argv[1]);

    if (input <= 0 || input > maxNum) {
        printf("usage: factorial <num> - where num is a positive integer <= %d\n", maxNum);
        return 2;
    }

    unsigned long long result=factorial(input);

    if (result > 999999) 
        printf("The factorial for %d is %6.6Le using %d iterations\n", input, (long double) result, iterations);
    else
        printf("The factorial for %d is %llu using %d iterations\n", input, result, iterations);

    return 0;
}
