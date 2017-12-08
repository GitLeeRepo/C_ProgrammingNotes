// linearsearch.c
//
// The most basic of searches, a linear search
//
// In addition to the search, it checks for duplicates, and gets min and max 
// for the array values.
//
// Inputs is from stdio console prompts, looping until the user enters a number
// outside the range of min to max values contained in the array.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// forward & external declarations
int linearSearch(int *ar, int key, int min, int max);
int maxIntAr(int *ar, int numElements);
int minIntAr(int *ar, int numElements);
int checkDupeIntAr(int *ar, int numElements, int *dupeNum);
 
int main(int argc, char *argv[]) {
    int ar[] = { 35, 24, 40, 19, 5, 45, 32 , 31 , 8, 23, 47, 27, 44, 38, 7, 6, 11, 33, 21, 15, 50,
                 22, 12, 16, 28 };
    int key = 55;
    int numElements = sizeof ar / sizeof (int);
    int maxInt = maxIntAr(ar, numElements);
    int minInt = minIntAr(ar, numElements);
    int dupe = 0; // false

    if (checkDupeIntAr(ar, numElements, &dupe)) {
        printf("%d is a duplicate, which is not allowed, exiting\n", dupe);
        return 1;
    }
    
    // provide a few stats and instructions
    printf("\nInteger array contains %d elements\n", numElements);
    printf("You have a %3.3f%% chance of picking a number that exists\n", 
                     (double) numElements / (maxInt - minInt + 1) * 100) ;
    printf("Enter number from %d to %d to search for (one per line), outside this range to end:\n", 
                                                                                    minInt, maxInt);

    // loop until the user selects a value outside of the range
    while (key != 0) {   

        if (scanf("%d", &key) <= 0)
            break;
        if (key < minInt || key > maxInt)
            break; 
        int result = linearSearch(ar, key, 0, numElements);

        if (result == -1)
            printf("%d not found\n", key);
        else
            printf("%d found in position %d\n", key, result);
    }
}


// perform the linear search
int linearSearch(int *ar, int key, int min, int max) {
    for (int i = min; i < max; i++) {
        if (ar[i] == key)
            return i;
    }
    return -1;
}


