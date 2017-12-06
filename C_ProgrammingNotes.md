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

* **char** / **unsigned char** - 1 byte/8 bits on 32/64 bit Linux
* **short** / **unsigned short** -  2 bytes/16 bits on 32/64 bit Linux
* **int** / **unsigned int** - 4 bytes/32 bits on 32/64 bit Linux
* **long** / **unsigned long** - 8 bytes/64 bits on 64 bit Linux; same as int on 32 bit Linux
* **long long** / **unsigned long long** - 8 bytes/64 bits on 32/64 bit Linux
* **float** - 4 bytes/32 bits (6 signficant digits)
* **double** -  8 bytes/64 bits (15 significant digits)
* **long double** - 16 bytes/128 bits (18 significant digits)

## Data Type Limits

* [Datat Type Limits](https://en.wikibooks.org/wiki/C_Programming/limits.h)

## Type Conversions

TOOD - Placeholder

# Character Strings

TOOD - Placeholder

## Printf Format Strings

Format   | Examples                 | Description                               | Footnotes
---------|--------------------------|-------------------------------------------|-----------
d        | "%d - %6d - %05d"        | print signed integer                      | 1, 2
u        | "%du - %6du - %06du"     | print unsigned integer                    | 1, 2
ld       | "%ld - %9ld - %09ld"     | print signed long                         | 1, 2
lu       | "%lu - %9lu - %09lu"     | print unsigned long                       | 1, 2
lld      | "%lld - %9lld - %09lld"  | print signed long long                    | 1, 2
llu      | "%llu - %9llu - %09llu"  | print unsigned long long                  | 1, 2
hd       | "%hd - %6hd - %05hd"     | print signed short                        | 1, 2
hu       | "%hu - %6hu - %06hu"     | print unsigned short                      | 1, 2
x, X     | "%x - %6x - %09x"        | print hexadecimal unsigned integer        | 1, 2, 4
lx, lX   | "%lx - %9lx - %09lx"     | print hexadecimal unsigned long           | 1, 2, 4
hx, hX   | "%hx - %6hx - %09hx"     | print hexadecimal unsigned short          | 1, 2, 4
p        | "%p - %9p - %09p"        | print pointer (six byte address)          | 1, 2
f        | "%6.3f; %02.14f"         | print float/double                        | 2, 3
g. G     | "%6.3f; %02.14f"         | print float/dbl (either dec or exp)       | 2, 3, 5
e, E     | "%9e - %9E"              | print float/double in exponential format  | 2, 3, 6
c        | "%c - %5c"               | print a single character                  | 1, 7
s        | "%s - %10s - %-10s       | print a character string                  | 1, 8

1. Number proceeding the type placeholder specifies the output length
2. Leading zero as in "%05d" or %09lu" will print leading zeros
3. For floats the decimal number preceeding the type specfies how many digits before and after the decimal point
4. the x/X prints the number as an exponent.  The lower case 'x' prints a lower case letter 'x' in the hex number, and an upper case 'X' prints and uppercase letter 'X' in the hex number.
5. the g/G types will either print as a decimal number or as an exponent depending on the size.  The lower case 'g' prints a lower case letter 'e' in the exponent, and an upper case 'G' prints and uppercase letter 'E' in the exponent.
6. the e/E prints the number as an exponent.  The lower case 'e' prints a lower case letter 'e' in the exponent, and an upper case 'E' prints and uppercase letter 'E' in the exponent.
7. Be aware that for character formats it will try to print the ASCII equivellent to the numeric value, many of which are non-printable characters.  This is intended for printable ASCII characters (A-Z, a-z, 0-9, punctuation, etc.)
8. This character string example shows a negative **-10s**, which will cause the string to be left justified, rather than the default right justified.


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

### Float Formats

```c
    float floatEx1 = 12345.6789;
    double doubleEx1 = 123456789.0123456789;
    double doubleEx2 = 0.000000123456789;

    printf("    float 1: %23.4f; %26.10f\n", floatEx1, floatEx1);
    printf("   double 1: %23.10f; %26.14f\n", doubleEx1, doubleEx1);
    printf("   double 2: %23.15f; %26.20f\n\n", doubleEx2, doubleEx2);

    printf(" g double 1: %23.10g; %26.14g\n", doubleEx1, doubleEx1);
    printf(" G double 1: %23.10G; %26.14G\n", doubleEx1, doubleEx1);
    printf(" g double 2: %23.18g; %26.20g\n", doubleEx2, doubleEx2);
    printf(" G double 2: %23.18G; %26.20G\n", doubleEx2, doubleEx2);

    printf(" e double 1:  %22.10e; %26.14e\n", doubleEx1, doubleEx1);
    printf(" E double 1:  %22.10e; %26.14E\n", doubleEx1, doubleEx1);
    printf(" e double 2: %23.11e; %25.20e\n", doubleEx2, doubleEx2);
    printf(" E double 2: %23.11E; %25.20E\n\n", doubleEx2, doubleEx2);

    printf("hex double 1: %22a;  %25a\n", doubleEx1, doubleEx1);
    printf("hex double 1: %22A;  %25A\n", doubleEx1, doubleEx1);
```

**Output:**

```bash
Float Formats (col 1 num assiged width, col 2 extra width):
    float 1:              12345.6787;           12345.6787109375
   double 1:    123456789.0123456717;   123456789.01234567165375
   double 2:       0.000000123456789;     0.00000012345678900000

 g double 1:               123456789;            123456789.01235
 G double 1:               123456789;            123456789.01235
 g double 2: 1.23456788999999994e-07;  1.2345678899999999393e-07
 G double 2: 1.23456788999999994E-07;  1.2345678899999999393E-07
 e double 1:        1.2345678901e+08;       1.23456789012346e+08
 E double 1:        1.2345678901e+08;       1.23456789012346E+08
 e double 2:       1.23456789000e-07; 1.23456788999999993933e-07
 E double 2:       1.23456789000E-07; 1.23456788999999993933E-07

hex double 1:  0x1.d6f34540ca458p+26;      0x1.d6f34540ca458p+26
hex double 1:  0X1.D6F34540CA458P+26;      0X1.D6F34540CA458P+26
```

### Character String Format

```c
    char *strEx1 = "Hello, World!";
    char *strEx2 = "How goes things?";

    printf("strings 1 & 2    (\"%%s  %%s\"): %s  %s\n", strEx1, strEx2);
    printf("strings 1 & 2  (\"%%20s  %%s\"): %20s  %s\n", strEx1, strEx2);
    printf("strings 1 & 2 (\"%%-20s  %%s\"): %-20s  %s\n", strEx1, strEx2);
```

**Output:**

```bash
Character String:
strings 1 & 2    ("%s  %s"): Hello, World!  How goes things?
strings 1 & 2  ("%20s  %s"):        Hello, World!  How goes things?
strings 1 & 2 ("%-20s  %s"): Hello, World!         How goes things?
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
