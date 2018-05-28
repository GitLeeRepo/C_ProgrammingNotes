// Test for printing a memory address in MyOS kernel.  Since MyOS doesn't
// have access to the C library (at least not yet), I needed a lower level
// way of printing out a memory address without using printf format strings.
// This example includes printf functions, but only for reference to verify
// the accurracy.

#include <stdio.h>


void kprintaddr(long long addr) {
    long long div = 0x100000000000;
    long long result;

    printf("%08llx\n", addr);    // full addr in hex for visual comparison reference
    for (int i = 0; i < 12; i++) {
        result = addr/div;
        if (result >= 0 && result <= 9) {
            printf("%c", (char) result+48);
        }
        else if (result >= 10 && result <= 15) {
            printf("%c", (char) result+87);
        }
        else {
            printf("x");
        }
        addr = addr - (result*div);
        div = div/0x10;
    }
    printf("\n");
}

int main() {
    char *s1 = "test";

    // I was hoping a string literal would give me the address of the line of code
    // being executed, similar to an immediate in assembler, but it instead is placed
    // on the stack adjacent to the local string var (s1) in memory.  In fact, he second 
    // literal has the same address as the first literal, when they are identical..
    printf("%s and %s\n", s1, "literal");  // strings themselves for reference
    printf("%p and %p\n", s1, "literal");  // string addresses for reference
    kprintaddr((long long)s1);
    kprintaddr((long long)"literal");

}
