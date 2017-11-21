# Overview

Notes on the GNU Make program.

# References

* [C_ProgrammingNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/C_ProgrammingNotes.md#overview)

# Terminology and Concpts

# Very Simple Make File

For illustration of basic concepts, start with a very basic make file

```make
hello: hello.c
        gcc hello.c -o hello
```
Compiles directly to the 'hello' executable without any intermediate *.o object files.

**Important Note:** - gnu make requires a **tab** to be used for the indentation of the **command** (gcc here)

Concepts here:

* **target* - the **hello:** label. It refers to the file or entity that must be made.  In this the target **hello** is the executable file to be made.  In other cases it might be something like **prog.o** to refer to the object file to be created.
* **prerequisites** - the prerequisite items need to make the **target**, in this case the **hello.c** source file.  There can be more than one prerequisite specified here.  If any **prerequisite** is newer than the **target** the target is **remade**.  If any of the prerequites have a **rule** associated with them, those rules are run first.
**command** - the command to run to build the **target** using the **prerequisites**, in this case **gcc hello.c -o hello**
* **rule** - refers to all three parts of the above, the **target**, the **prerequisites**, and the **command**.  The first rule seen by make is called the **default rule**

Note: a **target** can be specified on the command line, but if it is not the first **target/rule** encountered (the **default rule**) is what is run.


