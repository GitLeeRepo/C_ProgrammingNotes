// factorial.c
//
// Using recursion calculate the factorial (the product of an integer and all integers below it) 
// for the value provided on the command line

#include <stdio.h>
#include <stdlib.h>

unsigned int iterations = 0;

unsigned long long factorial(unsigned long long n) {
    iterations++;
    if (n == 1)
        return 1;
    else if (n == 0)
        return 1;
    else
        return n*factorial(n-1);
}


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("usage: factorial <num> - where num is a positive integer <= 65\n");
        return 1;
    }
        
    int input=atoi(argv[1]);

    if (input <= 0 || input > 65) {
        printf("usage: factorial <num> - where num is a positive integer <= 65\n");
        return 2;
    }

    unsigned long long result=factorial(input);

    if (result > 999999) 
        printf("The factorial for %d is %6.3Le using %d iterations\n", input, (long double) result, iterations);
    else
        printf("The factorial for %d is %llu using %d iterations\n", input, result, iterations);

    return 0;
}
