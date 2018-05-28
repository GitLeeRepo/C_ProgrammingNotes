////////////////////////////////////////////////////////////////////////////////
// simple_recursion.c
//
// Simple example of recursion that counts up to 10, and then back down again.
// It shows three examples that do the same thing, but the each subsequent example
// is cleaner and more balanced.  The difference is simply a matter of where the
// controlling count is incremented, how it is incremented, and what value is 
// initially passed in.
/////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

// forward declarations
void recurseEx1(int count);
void recurseEx2(int count);
void recurseEx3(int count);

int main(void) {
    int count1 = 1, count2 = 0, count3 = 1;

    // Example 1 (less desireable):
    
    // no printf 'Before' here since the same count will be displayed inside the
    // recurse() function before it calls itself again at which point it is incremented
    recurseEx1(count1);
    // for a balanced count(same number of before's as after's) this printf must
    // follow, otherwise the '1' (in this scope) will not be printed, since the
    // recurse has alread incremented it when it falls back out
    printf("After: %d\n", count1);

    printf("Press Return to continue\n");
    getchar();

    // Example 2 (more desireable) 

    // no printf()'s need here, neither before nor after
    recurseEx2(count2);

    printf("Press Return to continue\n");
    getchar();

    // Example 3 (most desireable) 

    // no printf()'s need here, neither before nor after
    recurseEx3(count3);
}


// the less desireable version where the count is increment just before the
// recursive call, which leads to more inconsistent way of dealing with
// the results.
void recurseEx1(int count) {

    printf("Before: %d\n", count);
    if (count < 10) {
        recurseEx1(++count);
        // for a balanced count (same number of before's as after's) this printf
        // must be in the 'if' otherwise after will have two '10's printed
        printf("After: %d\n", count);
    }
}

// only really difference is where count is incremented, with a count of zero 
// initially passed in rather than 1.  This allows a more balanced approach
// both here and in the calling function
void recurseEx2(int count) {
    count++;

    printf("Before: %d\n", count);
    if (count < 10) {
        recurseEx2(count);
    }
    // for this one the printf doesn't need to be in the condition as it did
    // during the first example.  More consistent with how the 'Before' is handled.
    printf("After: %d\n", count);
}

// this example increments the count in the same place as the first example, yet
// has the same desirable behavior and format as the second example.  It is the
// most desirable in that it more consistent with a recursive approach than an
// iterative loop approach.  It does this by not actually changing the value of
// count itself in a given iteration, it instead adds 1 within the parameter
// (without changing the value in the current scope).  Each subsequent level
// still has a count that is one greater using this method.
void recurseEx3(int count) {
    printf("Before: %d\n", count);
    if (count < 10) {
        recurseEx3(count+1);
    }
    // for this one the printf doesn't need to be in the condition as it did
    // during the first example.  More consistent with how the 'Before' is handled.
    printf("After: %d\n", count);
}

