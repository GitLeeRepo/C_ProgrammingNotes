// recursepower.c
//
// Provides both a recursive and interative (loop) based means of raising a number 
// to a specified power using multiplication and addition.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// forward and external declarations
long raiseToRecurse(long, long);
long raiseToLoop(long, long);
void info_die(char*);
 
int main() {
    long x, y;
    char ch = 'r';

    printf("Use loop or recursion (l/r):\n>");
    if (scanf("%c", &ch) <= 0) {
       info_die("Invalid selection, exiting"); 
    }
    ch = tolower(ch);
    if (ch != 'r' && ch != 'l')
       info_die("Invalid selection, exiting"); 

    
    while (1) {
        printf("%s: Entering a negative exponent will toggle between loop and recursion\n",
                            (ch == 'l' ? "Loop" : "Recursion"));
        printf("%s: Enter a base number followed by its exponent, separated by a space\n>",
                            (ch == 'l' ? "Loop" : "Recursion"));
        if (scanf("%ld %ld", &x, &y) > 0) {
            if (y < 0) {
                ch = (ch == 'l' ? 'r' : 'l');
                y = abs(y);
            }
            if (ch == 'r')
                printf("The final answer is: %ld\n", raiseToRecurse(x, y));
            else if(ch == 'l')
                printf("The final answer is: %ld\n", raiseToLoop(x, y));
        }
        else
            break;
    }
    return 0;
}

// recursive solution
long raiseToRecurse(long b, long e) {
    if (e > 1) {
        b += raiseToRecurse(b, --e) * b -b;
        printf("%4ld %24ld %16e\n", e+1, b, (double) b);
    }
    return b;
}

// iterative solution
long raiseToLoop(long b, long e) {
    long result = 0;

    for (long i = 0; i < e - 1; i++) {
        result = (result == 0 ? b * b : result * b);
        printf("%6ld %24ld %16e\n", i+1, result, (double) result);
    }
    return result;
}
