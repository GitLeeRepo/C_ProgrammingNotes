// megasearch.c
//
// Fills an array, either randomly generated unsigned long numbers, or unsigned numbers read in
// from a data file.  In the case of the randomly generated numbers, it discards duplicates, and 
// will continue to fill each element of the array with a unique number, which can make for
// a long run on the last few elements of a large number, because almost all elements generated
// randomly will be rejected as duplicates (the last few elements in a 1 million element array
// can take a very long time.  There is no practical reason for doing this other than it is 
// interesting, and provides a long running program when desired for testing purposes.
//
// After the array is filled, either from file or random generation, the user is prompted for 
// numbers to search for.
//
// This is currently using a linear search, which for searching a million element array on
// todays hardware interactively appears just as fast as any other algorithm, i.e. instantaneous.
// The plan is to add additional search and sorting algorithms which should make a difference
// in the time to generated long arrays, since it does one or more searches everytime it
// tries to add a new number, in order to discard duplicates.
//
// Because this is not a practical program, but more of an experimental and informational
// program, it contains a lot of print statements, providing various statistics, along with
// periodic (and configurable as to the sample rate) output of progress.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include "../../commonlib/common.h"

// forward declarations
int linearSearch(unsigned long *ar, unsigned long key, unsigned long min, unsigned long max);
int fillArray(unsigned long *ar, unsigned long numElements);
int getInputType();
int readArrayFromFile(unsigned long *ar, unsigned long numElements);
unsigned long getNumOfElements(unsigned long defaultNumElements);
 
int inputFd, outputFd;
int openFlags = O_CREAT | O_WRONLY | O_TRUNC;
mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP; 
char *dataFile = "megasearch.dat";
unsigned long bufSize;

int main(int argc, char *argv[]) {
    unsigned long key = 55;
    unsigned long numElements = 1e5;  // default;
    unsigned long *ar = malloc(bufSize);
    int readFromFile = 1; // set to true or false
    struct stat fs;

    // choose to either get array input from file or to randomly generate 
    readFromFile = getInputType();
    if (readFromFile) {
        if (stat(dataFile, &fs) != 0)
            die("Unable to stat() file");
        bufSize = fs.st_size; // buffer size is file size
        numElements = bufSize / sizeof (unsigned long);
        ar = malloc(bufSize);

        // Open input file
        inputFd = open(dataFile, O_RDONLY);
        if (inputFd == -1)
            die("opening input file");

        readArrayFromFile(ar, numElements);
    }
    else { // randomly generate array
        numElements = getNumOfElements(numElements);
        bufSize = numElements * sizeof (unsigned long);
        ar = malloc(bufSize);
        // Open output file
        outputFd = open(dataFile, openFlags, filePerms);
        if (outputFd == -1)
            die("opening output file");

        // random generation of elements
        fillArray(ar, numElements);
    }

    // get search input
    printf("\nEnter number from 1 to %lu to search for (one per line), 0 to end:\n", numElements-1);
    while (key != 0) {   

        int ret = scanf("%lu", &key);
        if (key == 0 || ret == 0)
            break;  // either zero or non-numeric input triggers exit from loop
        int result = linearSearch(ar, key, 0, numElements - 1);

        if (result <= -1)
            printf("%ld not found\n", key);
        else
            printf("%ld found in position %d\n", key, result);
    }

    // close open files
    if (readFromFile) {
        if (close(inputFd) == -1)
            die("close input");
    }
    else {
        if (close(outputFd) == -1)
            die("close output");
    }
}


// simple linear search
int linearSearch(unsigned long *ar, unsigned long key, unsigned long min, unsigned long max) {
    for (unsigned long i = min; i < max; i++) {
        if (ar[i] == key)
            return i;
    }
    return -1;
}

// fill the array with randomly generated unsigned long numbers.  It discards duplicates, and 
// will continue to fill each element of the array with a unique number, which can make for
// a long run on the last few elements of a large number, because almost all elements generated
// randomly will be rejected as duplicates (the last few elements in a 1 million element array
// can take a very long time.  There is no practical reason for doing this other than it is 
// interesting, and provides a long running program when desired for testing purposes.. 
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

// read the array data in from a data file which stores the data in unsigned long format
int readArrayFromFile(unsigned long *ar, unsigned long numElements) {
    ssize_t numRead;

    if ((numRead = read(inputFd, ar, numElements * bufSize)) < 0)
        die("error reading file");

    printf("%lu (%e) bytes read, with %lu (%e) elements", (unsigned long) numRead, (double) numRead,
                                                        (unsigned long) numElements, (double) numElements);
    return 0;
}

// strip off the trailing newline, useful after fgets()
char *stripTrailingNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[--len] = '\0';
    }
    return str;
}

// get input type, either from file or randomly generated 
int getInputType() {
    int readFromFile = 1; // default to true
    char ch;

    while (ch != 'f' && ch != 'g') {
        printf("Read array from f)ile or g)enerate or q)uit (f/g/q): ");
        ch = tolower(getchar());
        if (ch == 'q')
            exit (1);
        readFromFile = (ch == 'g' ? 0 : 1);
        printf("\n");
    }
    getchar();  // remove newline from the buffer
    return readFromFile;
}

// get the number of elements in the array from the user
unsigned long getNumOfElements(unsigned long defaultNumElements) {
    unsigned long numElements;
    char inputStr[80]; // = {'\0'};

    printf("Enter the number of elements for the array (or press Enter to accept default: %lu (%e)):",
                                                        defaultNumElements, (double) defaultNumElements);
    fflush(stdin);

    if (fgets(inputStr, 80, stdin) == NULL)
        die("Invalid input, exiting");

    if (strcmp(inputStr, "\n") == 0)
        return defaultNumElements;

    stripTrailingNewline(inputStr);
    numElements = (unsigned long) atof(inputStr); // use atof incase scientific notation specified

    printf("\n%lu (%e) elements selected\n", numElements, (double) numElements);
    return numElements;
}
