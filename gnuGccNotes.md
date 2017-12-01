# Overview

Notes on the GNU GCC compiler

# References

* [GCC online documentation](https://gcc.gnu.org/onlinedocs/)

## My Other Notes

* [C_ProgrammingNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/C_ProgrammingNotes.md#overview)
* [gnuMakeNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuMakeNotes.md#overview)
* [gnuDebuggerNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuDebuggerNotes.md#overview)

# Command Line Options

## Output type

* **gcc -o** - **output to** the specified file.  It could be an object file, executable, or decompiled assembler source file
* **gcc -c** - combpile or assemble, but do NOT link.  Typically produces an *.o object file.
* **gcc -S -o hello.asm hello.c** - generate an assembly source version of the specified file (c file in this case)
* **gcc -E** - run through the **preprocessing phase** but do NOT compile.  The output is preprocessor information.
