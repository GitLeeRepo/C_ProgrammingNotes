# Overview

Notes on the C programming language, primarily in a Linux environment.  It is a companion to the [LinuxSysProgNotes](https://github.com/GitLeeRepo/LinuxSysProgNotes/blob/master/LinuxSysProgNotes) and [LinuxKernelNotes](https://github.com/GitLeeRepo/LinuxKernelNotes) repositories, in order to deal with topics that are not Linux System Programming or Kernel/Module specific as it relates to C and the associated tools.

This repository also contain information on the [gcc compiler](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuGccNotes.md#overview) itself and the associated tools such as [make](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/GnuMakeNotes.md#overview) and [gdb debugger](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuDebuggerNotes.md#overview).

# References

* [Datat Type Limits](https://en.wikibooks.org/wiki/C_Programming/limits.h)


## My Other Notes

* [gnuGccNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuGccNotes.md#overview)
* [GnuMakeNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/GnuMakeNotes.md#overview)
* [gdb debugger](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/gnuDebuggerNotes.md#overview)
* [LinuxSysProgNotes](https://github.com/GitLeeRepo/LinuxSysProgNotes/blob/master/LinuxSysProgNotes) - C related Linux System Program Notes.
* [LinuxKernelNotes](https://github.com/GitLeeRepo/LinuxKernelNotes) - C related Linux Kernel and Module programming notes.

## YouTube Videos

* [C Programming in Linux Series](https://www.youtube.com/watch?v=CKNjXvMB0MY&list=PLypxmOPCOkHXbJhUgjRaV2pD9MJkIArhg) - approx 100 videos on a wide range of C and Linux System Programming.


# TDB - Initial stages of creation

# Data Types

## Data Type Limits

* [Datat Type Limits](https://en.wikibooks.org/wiki/C_Programming/limits.h)

# Static Data Types and Functions

The word **static** has different meanings depending on whether you are deailing with **global static variables**, which effect the **scope of the variable** and **local static variables**, which effect the **lifetime of the variable**.

## Global Static

Within a module (a single C file), delcaring a variable to be **global** and **static**, means that variable is global to the module, but it is not visible outside the module.  **Non-static global variables** are accessible to other modules through the **extern** declarations and the **linker** resoving these references.
 
## Local Static

Static local variables (declared within functions) and static functions remain active for the life time of the application.  The static variables are defined in the data section of memory rather than on the stack, so they retain their values from one call to the next. 
