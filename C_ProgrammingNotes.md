# Overview

Notes on the C programming language, primarily in a Linux environment.  It is a companion to the [LinuxSysProgNotes](https://github.com/GitLeeRepo/LinuxSysProgNotes/blob/master/LinuxSysProgNotes) and [LinuxKernelNotes](https://github.com/GitLeeRepo/LinuxKernelNotes) repositories, in order to deal with topics that are not Linux System Programming or Kernel/Module specific as it relates to C and the associated tools.

This repository also contain information on the [gcc compiler](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuGccNotes.md#overview) itself and the associated tools such as [make](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/GnuMakeNotes.md#overview) and [gdb debugger](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuDebuggerNotes.md#overview).

# References

* [Datat Type Limits](https://en.wikibooks.org/wiki/C_Programming/limits.h)


## My Other Notes

* [Data Structures](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/DataStructuresNotes.md#overview)
* [AlgorithmNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/AlgorithmNotes.md#overview)
* [gnuGccNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuGccNotes.md#overview)
* [GnuMakeNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/GnuMakeNotes.md#overview)
* [gdb debugger](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuDebuggerNotes.md#overview)
* [LinuxSysProgNotes](https://github.com/GitLeeRepo/LinuxSysProgNotes/blob/master/LinuxSysProgNotes) - C related Linux System Program Notes.
* [LinuxKernelNotes](https://github.com/GitLeeRepo/LinuxKernelNotes) - C related Linux Kernel and Module programming notes.

## YouTube Videos

* [C Programming in Linux Series](https://www.youtube.com/watch?v=CKNjXvMB0MY&list=PLypxmOPCOkHXbJhUgjRaV2pD9MJkIArhg) - approx 100 videos on a wide range of C and Linux System Programming.


# Fundemental Data Types

TOOD - Placeholder

## Data Type Limits

* [Datat Type Limits](https://en.wikibooks.org/wiki/C_Programming/limits.h)

## Type Conversions

TOOD - Placeholder

# Character Strings

TOOD - Placeholder

## Printf Format Strings

Format   | Examples                 | Description                         | Footnotes
---------|--------------------------|-------------------------------------|-----------
d        | "%d - %6d - %05d"        | print signed integer                | 1, 2
du       | "%du - %6du - %06du"     | print unsigned integer              | 1, 2
ld       | "%ld - %9ld - %09ld"     | print signed long                   | 1, 2
lu       | "%lu - %9lu - %09lu"     | print unsigned long                 | 1, 2
lld      | "%lld - %9lld - %09lld"  | print signed long long              | 1, 2
llu      | "%llu - %9llu - %09llu"  | print unsigned long long            | 1, 2
h        | "%d - %6d - %05d"        | print signed integer                | 1, 2
du       | "%du - %6du - %06du"     | print unsigned integer              | 1, 2


1. Number proceeding the type placeholder specifies the output lenghth
2. Leading zero as in "%05d" or %09lu" will print leading zeros

## Printf Format String Examples

### Integer Formats

```c
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

    printf("            char 1: %20hd; %020hd\n", (short) charEx1, (short) charEx1);
    printf("            char 2: %20hd; %020hd\n", (short) charEx2, (short) charEx2);
    printf("   unsigned char 1: %20hu; %020hu\n", (short) ucharEx1, (short) ucharEx1);

    printf("hex unsign short 1: %20hx; %020hx\n", ushortEx1, ushortEx1);
    printf("hex unsign short 2: %20hX; %020hX\n", ushortEx1, ushortEx1);

    printf("           short 1: %20hd; %020hd\n", shortEx1, shortEx1);
    printf("           short 2: %20hd; %020hd\n", shortEx2, shortEx2);
    printf("  unsigned short 1: %20hu; %020hu\n", ushortEx1, ushortEx1);

    printf("hex unsigned int 1: %20x; %020x\n", uintEx1, uintEx1);
    printf("hex unsigned int 2: %20X; %020X\n", uintEx1, uintEx1);

    printf("         integer 1: %20d; %020d\n", intEx1, intEx1);
    printf("         integer 2: %20d; %020d\n", intEx2, intEx2);
    printf("unsigned integer 1: %20u; %020u\n", uintEx1, uintEx1);

    printf(" hex unsign long 1: %20lx; %020lx\n", ulongEx1, ulongEx1);
    printf(" hex unsign long 2: %20lX; %020lX\n", ulongEx1, ulongEx1);

    printf("            long 1: %20ld; %020ld\n", longEx1, longEx1);
    printf("            long 2: %20ld; %020ld\n", longEx2, longEx2);
    printf("   unsigned long 1: %20lu; %020lu\n", ulongEx1, ulongEx1);

    printf("\n         pointer to char 1: %10p (six byte address)\n", &charEx1);
    printf("pointer to unsigned long 1: %10p (six byte address)\n\n", &ulongEx1);
```

**Output:***

```bash
Integer formats (with max/min values):
            char 1:                  127; 00000000000000000127
            char 2:                 -128; -0000000000000000128
   unsigned char 1:                  255; 00000000000000000255
hex unsign short 1:                 ffff; 0000000000000000ffff
hex unsign short 2:                 FFFF; 0000000000000000FFFF
           short 1:                32767; 00000000000000032767
           short 2:               -32768; -0000000000000032768
  unsigned short 1:                65535; 00000000000000065535
hex unsigned int 1:             ffffffff; 000000000000ffffffff
hex unsigned int 2:             FFFFFFFF; 000000000000FFFFFFFF
         integer 1:           2147483647; 00000000002147483647
         integer 2:          -2147483648; -0000000002147483648
unsigned integer 1:           4294967295; 00000000004294967295
 hex unsign long 1:     ffffffffffffffff; 0000ffffffffffffffff
 hex unsign long 2:     FFFFFFFFFFFFFFFF; 0000FFFFFFFFFFFFFFFF
            long 1:  9223372036854775807; 09223372036854775807
            long 2: -9223372036854775808; -9223372036854775808
   unsigned long 1: 18446744073709551615; 18446744073709551615

         pointer to char 1: 0x7ffd09f4436b (six byte address)
pointer to unsigned long 1: 0x7ffd09f44380 (six byte address)
```

# Operators and Expressions

TOOD - Placeholder

# Control Statements

TOOD - Placeholder

# Input and Output

TOOD - Placeholder

## Character Input and Output

TOOD - Placeholder

## String and Text Input and Output

TOOD - Placeholder

### Input Validation

TOOD - Placeholder

# Loops

TOOD - Placeholder

# Arrays and Pointers

TOOD - Placeholder

## Arrays

TOOD - Placeholder

## Pointers

TOOD - Placeholder

# Structures

TOOD - Placeholder

# Functions

TOOD - Placeholder

# Memory and Memory Allocation

TOOD - Placeholder

# Static Data Types and Functions

The word **static** has different meanings depending on whether you are deailing with **global static variables**, which effect the **scope of the variable** and **local static variables**, which effect the **lifetime of the variable**.

## Global Static

Within a module (a single C file), delcaring a variable to be **global** and **static**, means that variable is global to the module, but it is not visible outside the module.  **Non-static global variables** are accessible to other modules through the **extern** declarations and the **linker** resoving these references.

## Local Static

Static local variables (declared within functions) and static functions remain active for the life time of the application.  The static variables are defined in the data section of memory rather than on the stack, so they retain their values from one call to the next. 

# File Input and Output

Refer also to: * [LinuxSysProgNotes](https://github.com/GitLeeRepo/LinuxSysProgNotes/blob/master/LinuxSysProgNotes) - specifically the file I/O topics.

TOOD - Placeholder

# Preprocessor

TOOD - Placeholder

# Mutliple Modules

TOOD - Placeholder

# Data Structures

* [Data Structures](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/DataStructuresNotes.md#overview)

# Algorithms

* [AlgorithmNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/AlgorithmNotes.md#overview)
