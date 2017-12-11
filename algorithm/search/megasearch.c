// linearsearch.c
//
// The most basic of searches, a linear search

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <limits.h>
#include "../../commonlib/common.h"

// forward declarations
int linearSearch(unsigned long *ar, unsigned long key, unsigned long min, unsigned long max);
int fillArray(unsigned long *ar, unsigned long numElements);
int displayArray(unsigned long *ar, unsigned long numElements);
int readArrayFromFile(unsigned long *ar, unsigned long numElements);
 
int inputFd, outputFd;
int openFlags = O_CREAT | O_WRONLY | O_TRUNC;
mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP; 
char *dataFile = "megasearch.dat";
unsigned long bufSize;

int main(int argc, char *argv[]) {
    //int ar[] = { 35, 24, 40, 19, 5, 55, 32 , 31 , 8, 23, 47, 27, 44, 2, 7, 1, 11, 33, 21, 15, 50, 22, 12 };
    unsigned long key = 55;
    unsigned long numElements = 1e5;
    bufSize = numElements * sizeof (unsigned long);
    unsigned long *ar = malloc(bufSize);
    int readFromFile = 1; // set to true or false


    
    if (readFromFile) {
        // Open input file
        inputFd = open(dataFile, O_RDONLY);
        if (inputFd == -1)
            die("opening input file");

        readArrayFromFile(ar, numElements);
    }
    else {
        // Open output file
        outputFd = open(dataFile, openFlags, filePerms);
        if (outputFd == -1)
            die("opening output file");

        fillArray(ar, numElements);
    }


//    displayArray(ar, numElements);

    printf("\nEnter number from 1 to %lu to search for (one per line), 0 to end:\n", numElements-1);
    while (key != 0) {   

        scanf("%lu", &key); 
        int result = linearSearch(ar, key, 0, numElements - 1);

        if (result == -1)
            printf("%ld not found\n", key);
        else
            printf("%ld found in position %d\n", key, result);
    }

    if (readFromFile) {
        if (close(inputFd) == -1)
            die("close input");
    }
    else {
        if (close(outputFd) == -1)
            die("close output");
    }
}


int linearSearch(unsigned long *ar, unsigned long key, unsigned long min, unsigned long max) {
    for (unsigned long i = min; i < max; i++) {
        if (ar[i] == key)
            return i;
    }
    return -1;
}

int fillArray(unsigned long *ar, unsigned long numElements) {
    time_t t, start, stop, intervalStart;
    unsigned long num;

    //Intializes random number generator
    srand((unsigned) time(&t));

    unsigned long numIter = 0;
    unsigned long sampleNum = 1000;
    int runningSec = 0;
    time(&start);
    time(&intervalStart);
    for (unsigned long i = 0; i < numElements-1; i++) {
        if (numIter < ULONG_MAX)
            numIter++; // total iterations

        num = rand() % numElements;
        if ((i |= 0) && (linearSearch(ar, num, 0, numElements) != -1)) {
            i--;
            continue;
        }
        ar[i] = num;

        if (i % sampleNum == 0) { 
            time(&stop);
            runningSec = stop - start;
            printf("%10lu: %10lu %6d %6d %12.6f %14e\n", i, ar[i], (int) (stop - intervalStart),
                                            runningSec, (double) runningSec/i*sampleNum, (double) numIter);
            intervalStart = stop;
        }
    }
    time(&stop);
    printf("%10lu: %10lu %6d %6d %12.6f %14e\n", numElements, ar[numElements-2], 
                (int) (stop - intervalStart), (int) (stop-start), 
                                            (double) runningSec/numElements*sampleNum, (double) numIter);

    if (write(outputFd, ar, bufSize) != bufSize)
        die("couldn't write whole buffer");

    printf("\nTotal time: %d\n", (int) (stop-start));
    printf("Total iterations: %lu (%e)\n", numIter, (double) numIter);
    return 0;
}


int displayArray(unsigned long *ar, unsigned long numElements) {

    for (unsigned long i=0; i < numElements-1; i++) {
//        if (i % 1000 == 0) 
            printf("%10lu: %10lu\n", i, ar[i]);
    }
    return 0;
}


int readArrayFromFile(unsigned long *ar, unsigned long numElements) {
    ssize_t numRead;

    if ((numRead = read(inputFd, ar, numElements * bufSize)) < 0)
        die("error reading file");

    printf("%lu bytes read", (unsigned long) numRead);
    return 0;
}
