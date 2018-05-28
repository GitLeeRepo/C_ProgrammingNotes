#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// forward declarations
void intFormats();
void floatFormats();
void promptAndClear();
void stringFormats();

int main(void) {
    system("clear"); // clear screen

    printf("\n\nInteger formats (with max/min values):\n");
    intFormats();

    promptAndClear();

    printf("\n\nFloat Formats (col 1 num assiged width, col 2 extra width):\n");
    printf("Note how the double 1 loses precision in the last two digits, it has 15 significant\n");
    printf("digits, but seems to get 17 right.  The long double 1 is able to display the full\n");
    printf("20 sig digits stored, though according to docs it has 18 sig digits (for 80bit).\n");
    printf("Maybe just randomly lucky on the last few digits.\n");
    floatFormats();

    promptAndClear();

    printf("\n\nCharacter String:\n");
    stringFormats();

}

void intFormats() {
    char charEx1 = SCHAR_MAX;
    char charEx2 = SCHAR_MIN;
    unsigned char ucharEx1 = UCHAR_MAX;
    short shortEx1 = SHRT_MAX;
    short shortEx2 = SHRT_MIN;
    unsigned short ushortEx1 = USHRT_MAX;
    int intEx1 = INT_MAX;
    int intEx2 = INT_MIN;
    unsigned int uintEx1 = UINT_MAX;
    long longEx1 = LONG_MAX;
    long longEx2 = LONG_MIN;
    unsigned long ulongEx1 = ULONG_MAX;

    printf("            char 1: %20hd; %020hd sizeof: %lu\n", (short) charEx1, 
                                                (short) charEx1, sizeof(charEx1));
    printf("            char 2: %20hd; %020hd sizeof: %lu\n", (short) charEx2, 
                                                (short) charEx2, sizeof(charEx2));
    printf("   unsigned char 1: %20hu; %020hu sizeof: %lu\n", (short) ucharEx1, 
                                                (short) ucharEx1, sizeof(ucharEx1));

    printf("hex unsign short 1: %20hx; %020hx sizeof: %lu\n", ushortEx1, ushortEx1, sizeof(ushortEx1));
    printf("hex unsign short 2: %20hX; %020hX sizeof: %lu\n", ushortEx1, ushortEx1, sizeof(ushortEx1));

    printf("           short 1: %20hd; %020hd sizeof: %lu\n", shortEx1, shortEx1, sizeof(shortEx1));
    printf("           short 2: %20hd; %020hd sizeof: %lu\n", shortEx2, shortEx2, sizeof(shortEx2));
    printf("  unsigned short 1: %20hu; %020hu sizeof: %lu\n", ushortEx1, ushortEx1, sizeof(ushortEx1));

    printf("hex unsigned int 1: %20x; %020x sizeof: %lu\n", uintEx1, uintEx1, sizeof(uintEx1));
    printf("hex unsigned int 2: %20X; %020X sizeof: %lu\n", uintEx1, uintEx1, sizeof(uintEx1));

    printf("         integer 1: %20d; %020d sizeof: %lu\n", intEx1, intEx1, sizeof(intEx1));
    printf("         integer 2: %20d; %020d sizeof: %lu\n", intEx2, intEx2, sizeof(intEx2));
    printf("unsigned integer 1: %20u; %020u sizeof: %lu\n", uintEx1, uintEx1, sizeof(uintEx1));

    printf(" hex unsign long 1: %20lx; %020lx sizeof: %lu\n", ulongEx1, ulongEx1, sizeof(ulongEx1));
    printf(" hex unsign long 2: %20lX; %020lX sizeof: %lu\n", ulongEx1, ulongEx1, sizeof(ulongEx1));

    printf("            long 1: %20ld; %020ld sizeof: %lu\n", longEx1, longEx1, sizeof(ulongEx1));
    printf("            long 2: %20ld; %020ld sizeof: %lu\n", longEx2, longEx2, sizeof(longEx2));
    printf("   unsigned long 1: %20lu; %020lu sizeof: %lu\n", ulongEx1, ulongEx1, sizeof(ulongEx1));

    printf("\n         pointer to char 1: %10p (six byte address) sizeof: %lu\n", 
                                                                &charEx1, sizeof(&charEx1));
    printf("pointer to unsigned long 1: %10p (six byte address) sizeof: %lu\n\n", 
                                                                &ulongEx1, sizeof(&ulongEx1));
}


void floatFormats() {
    float floatEx1 = 12345.678901;                     // precise through 6 significant digits
    double doubleEx1 = 123456789.0123456789;           // precise through 15 significant digits
    double doubleEx2 = 0.123456789012345678;           // precise through 15 significant digits
    long double longdoubleEx1 = 123456789.0123456789L; // precise through 18 significant digits
                                                       // note the L needed on the end for long prec

    printf("    float 1: %23.4f; %26.10f sizeof: %lu\n", floatEx1, floatEx1, sizeof(floatEx1));
    printf("   double 1: %23.10f; %26.14lf sizeof: %lu\n", doubleEx1, doubleEx1, sizeof(doubleEx1));
    printf("   double 2: %23.15f; %26.20lf sizeof: %lu\n", doubleEx2, doubleEx2, sizeof(doubleEx2));
    printf(" long dbl 1: %23.10Lf; %26.14Lf sizeof: %lu\n\n", longdoubleEx1, longdoubleEx1, 
                                                                                sizeof(longdoubleEx1));

    printf(" g double 1: %23.10g; %26.14g sizeof: %lu\n", doubleEx1, doubleEx1, sizeof(doubleEx1));
    printf(" G double 1: %23.10G; %26.14G sizeof: %lu\n", doubleEx1, doubleEx1, sizeof(doubleEx1));
    printf(" g double 2: %23.18g; %26.20g sizeof: %lu\n", doubleEx2, doubleEx2, sizeof(doubleEx2));
    printf(" G double 2: %23.18G; %26.20G sizeof: %lu\n\n", doubleEx2, doubleEx2, sizeof(doubleEx2));

    printf(" e double 1:  %22.10e; %26.14e\n", doubleEx1, doubleEx1);
    printf(" E double 1:  %22.10e; %26.14E\n", doubleEx1, doubleEx1);
    printf(" e double 2: %23.11e; %25.20e\n", doubleEx2, doubleEx2);
    printf(" E double 2: %23.11E; %25.20E\n\n", doubleEx2, doubleEx2);

    printf("hex double 1: %22a;  %25a\n", doubleEx1, doubleEx1);
    printf("hex double 1: %22A;  %25A\n", doubleEx1, doubleEx1);
}

void stringFormats() {
    char *strEx1 = "Hello, World!";
    char *strEx2 = "How goes things?";

    printf("strings 1 & 2    (\"%%s  %%s\"): %s  %s\n", strEx1, strEx2);
    printf("strings 1 & 2  (\"%%20s  %%s\"): %20s  %s\n", strEx1, strEx2);
    printf("strings 1 & 2 (\"%%-20s  %%s\"): %-20s  %s\n", strEx1, strEx2);
}

void promptAndClear() {
    printf("Press Enter to continue");
    getchar();
    system("clear"); // clear screen
}
