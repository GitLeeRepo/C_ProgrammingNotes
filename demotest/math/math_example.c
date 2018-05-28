// math_examples.c
//
// Some examples of the math functions in math.h and its corresponding library, which must
// be linked in with the -l flag (i.e., -lm), in addition to specifying the include here.

#include <stdio.h>
#include <math.h>
#include "../../commonlib/common.h"

int main() {
    // 1st 3 have example values assigned but they will be overwritten by stdio input
    double base = 2;  // base for exponent and log
    double exp = 8;   // exponent for pow() function
    double x = 256;   // used by log() function
    const double e = M_E;   // Euler's constant, approx 2.718281828459045235...

    printf("\nEnter a 'base' number (used by both pow() & log())\n>");
    if (scanf("%lf", &base) <=0)
        info_die("Invalid base, exiting");
    printf("\nEnter an 'exponent' number (used by pow(), while log() result is exponent)\n>");
    if (scanf("%lf", &exp) <=0)
        info_die("Invalid base, exiting");

    printf("\nEnter an 'x' number (used by log(), while pow() result is x)\n>");
    if (scanf("%lf", &x) <=0)
        info_die("Invalid base, exiting");

    printf("\n----------------------------------------------------------------------------------------\n\n");

    printf("  Using pow(base, exp) -> base: %10.3lf exponent:  %10.3lf    result(x): %10.3lf\n", 
                                                                        base, exp, pow(base, exp));
    printf("Using log(x)/log(base) -> base: %10.3lf        x:  %10.3lf  result(exp): %10.3lf \n", 
                                                                        base, x, (log(x)/log(base)));

    printf("\nLog components -> base: %10.3lf  x: %10.3lf  log(base):  %10.3lf  log(x): %10.3lf\n", 
                                                                        base, x, log(base), log(x));
    printf("\ne - Euler's number: %lf  log(e):%lf log(e+1): %lf log(e-1): %lf\n", 
                                                                        e, log(e), log(e+1), log(e-1));
    printf("\n----------------------------------------------------------------------------------------\n");
}
