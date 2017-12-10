// multi.c NOTE: CURRENTLY NOT IN WORKING ORDER, WORK TO BE DONE
//
// A recursive method of doing Karatsuba multiplications 
//

#include <stdio.h>
#include <stdlib.h>

unsigned int iterations = 0;

long multi(int n, int x, int y) {
    
    iterations++;
    if (n == 1)
        return x*y;
    else {
        
        printf("before: %4d %8d %8d\n", n, x, y); 
        return multi(--n, x, y) + (x*y);
        printf("after: %4d %8d %8d\n", n, x, y); 
    }
}


int main(int argc, char *argv[]) {
    int term1 = 5678;
    int term2 = 1234;
    int a = 56;
    int b =78;
    int c = 12;
    int d = 34;
    int n = 4;

    int ac = multi(n, a, c);
    int bd = multi(n, b, d);
    int abcd = multi(n, a+b, c+d);
    int adbc = abcd - ac - bd;
    int result = (ac * (10^n)) + bd + (adbc * (10^(n/2)));

    //result = 10^n * (ac * (10^(n/2))) * ((ad + bc) + bd);    
    printf("Term1=%d term2=%d, product%d, ac=%d bd=%d abcd=%d adbc=%d result=%d\n", term1, term2, 
                                                                term1*term2, ac, bd, abcd, adbc, result);

    return 0;
}
