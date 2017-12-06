#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <time.h>

int addCommas(char  *commaNum, unsigned long bigsum) {
    char  temp[30];

    
    memset(temp, 0, 30); 
    sprintf(temp, "%lu", bigsum);
    memset(commaNum, 0, 30); 
    int numlen = strlen(temp);

    int adjust = ((numlen % 3 == 0) ? 0 : 1);
    int j = numlen + (numlen/3) + adjust;
    int k = -1;
    for (int i = numlen; i >= 0; i--) {
        if ((k+0) % 3 == 0) {
            if ((k) != 0)
                commaNum[j] = ',';
            j--;
        }
        commaNum[j--] = temp[i];
        k++;
    }
    return numlen;
}

unsigned long doSum(unsigned long maxIterations) {
    unsigned long bigsum = 0;
    char commaNumStr[30] = "This is a test";
    char commaIterStr[30] = "This is a test";

    unsigned long modNum = 0;
    unsigned long i; // used after loop also 
    for (i = 0; i < maxIterations; i++) {
        if (bigsum >=  ULLONG_MAX - i)
            break;

        bigsum += i; 
        if ((i % 1000000000) == 0) {
            addCommas(&commaNumStr[0], bigsum);
            addCommas(&commaIterStr[0], i);
            printf("%4lu  iteration: %16s; running sum: %26s - %6.3e\n", modNum++, commaIterStr, commaNumStr, (double) bigsum);    
        }   
        if ((i % 100000000) == 0) {
            bigsum /= 2;
        }   
    }
    addCommas(&commaNumStr[0], bigsum);
    addCommas(&commaIterStr[0], i);
    printf("%4lu Total Iter: %16s;   Total sum: %26s - %6.3e\n", modNum, commaIterStr, commaNumStr, (double ) bigsum);    
    addCommas(&commaNumStr[0], ULONG_MAX);
    printf("Max unsignd long: %56s\n", commaNumStr);    
    return bigsum;
}

int main(void) {

    time_t start;
    time(&start);
    printf("sum = %lu\n", doSum(ULONG_MAX));
    printf("max = %lu\n", ULONG_MAX);
    time_t stop;
    time(&stop);
    printf("\nElapsed time: %ld\n", (long) (stop-start));

    return 0; 
}
