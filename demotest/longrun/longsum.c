// longsum.c
//
// Doesn't do anything useful, it is primarily designed to create long running
// process for demo/test purposes.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include "../../commonlib/common.h"

// forward and external declarations
unsigned long doSum(unsigned long maxIterations,
                    unsigned long divOnIterationNum,
                    unsigned long sumOnInterationNum);


int main(int argc, char *argv[]) {
    //default arguements
    unsigned long divOnIterationNum = 1e12;
    unsigned long sumOnInterationNum = 1e9;

    if (argc >= 2) {
        if (atof(argv[1]) >= ULONG_MAX)
            divOnIterationNum = ULONG_MAX;
        else
            divOnIterationNum = (unsigned long) atof(argv[1]);
    }
    if (argc >= 3)
        sumOnInterationNum = (unsigned long) atof(argv[2]);

    printf("divOnIterationNum=%e;  sumOnInterationNum=%e\n", 
                            (double) divOnIterationNum ,(double) sumOnInterationNum);


    time_t start;
    time(&start);
    printf("sum = %lu\n", doSum(ULONG_MAX, divOnIterationNum, sumOnInterationNum));
    printf("max = %lu\n", ULONG_MAX);
    time_t stop;
    time(&stop);
    printf("\nElapsed time: %ld\n", (long) (stop-start));

    return 0; 
}


unsigned long doSum(unsigned long maxIterations,
                    unsigned long divOnIterationNum,
                    unsigned long sumOnInterationNum) {
    unsigned long bigsum = 0;
    char commaNumStr[30] = "This is a test";
    char commaIterStr[30] = "This is a test";

    unsigned long numOfDivides = 0;
    unsigned long modNum = 0;
    unsigned long i; // used after loop also 
    for (i = 0; i < maxIterations; i++) {
        if (bigsum >=  ULLONG_MAX - i)
            break;

        // add the iteration number to bigsum
        bigsum += i; 

        // periodically print a runnning sum when the iteration is evenly
        // divisible by the amount specified with the modulus operator
        if ((i % sumOnInterationNum) == 0) {

            // add commas to output to make it easier to read
            addCommas_ul(&commaNumStr[0], bigsum);
            addCommas_ul(&commaIterStr[0], i);
            printf("%4lu  iteration: %16s; running sum: %26s - %6.3e - %lu\n", 
                        modNum++, commaIterStr, commaNumStr, (double) bigsum, numOfDivides);    
        }  

        // to make things more interesting, and to make this run longer
        // divide the running sum in half whenever the iteration is evenly
        // divisible by the amount specified with the module operator 
        if ((i>1) && (i % divOnIterationNum) == 0) {
            bigsum /= 2;
            numOfDivides++;
        }   
    }
    addCommas_ul(&commaNumStr[0], bigsum);
    addCommas_ul(&commaIterStr[0], i);
    printf("%4lu Total Iter: %16s;   Total sum: %26s - %6.3e - %lu\n", 
                    modNum, commaIterStr, commaNumStr, (double ) bigsum, numOfDivides);    
    addCommas_ul(&commaNumStr[0], ULONG_MAX);
    printf("Max unsignd long: %56s\n\n", commaNumStr); 

    printf("Number of divides=%lu; divOnIterationNum=%e;  sumOnInterationNum=%e\n", 
                    numOfDivides, (double) divOnIterationNum ,(double) sumOnInterationNum);
       
    return bigsum;
}


