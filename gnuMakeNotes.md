# Overview

Notes on the GNU Make program.

# References

* [C_ProgrammingNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/C_ProgrammingNotes.md#overview)

# Terminology and Concpts

# Very Simple Make File

For illustration of basic concepts, start with a very basic make file

```make
# Example comment
hello: hello.c
        gcc hello.c -o hello
```
Compiles directly to the 'hello' executable without any intermediate *.o object files.

**Important Note:** - gnu make requires a **tab** to be used for the indentation of the **command** (gcc here).  Anything proceeded by a **tab** will be interpretted by make as a **command**, so don't use **tabs** for anything other than commands and comments.  The **tab** character is what tells make it is a command, anything that follows is sent to the shell, including comments.

Note that **#** is used to start a **comment**.  This is the same as in shell scripts, which is why comments can be sent to the shell without causing an issue.

**Concepts here:**

* **target** - the **hello:** label. It refers to the file or entity that must be made.  In this the target **hello** is the executable file to be made.  In other cases it might be something like **prog.o** to refer to the object file to be created.
* **prerequisites** - the prerequisite items need to make the **target**, in this case the **hello.c** source file.  There can be more than one prerequisite specified here.  If any **prerequisite** is newer than the **target** the target is **remade**.  If any of the prerequites have a **rule** associated with them, those rules are run first.
**command** - the command to run to build the **target** using the **prerequisites**, in this case **gcc hello.c -o hello**
* **rule** - refers to all three parts of the above, the **target**, the **prerequisites**, and the **command**.  The first rule seen by make is called the **default rule**

Note: a **target** can be specified on the command line, but if it is not the first **target/rule** encountered (the **default rule**) is what is run.

A common **target** specified on the command line is **clean**:

```bash
make clean
```

This would then run the **clean target/rule** in the Makefile, which would clean the environment, such as deleting \*.o files:

```make
TARGET=hello
clean:
        rm -f *.o $(TARGET)
```

# Dependencies

To extend the simple make file we started with, to reference and use a **chain** of dependencies:

```make
hello: hello.o languages.o
        gcc hello.o languages.o -o hello
        
hello.o: hello.c
        gcc -c hello.c
        
languages.o: languages.c
        gcc -c languages.c

```
When the hello.o and languages.o are evaluated for the **hello:** target, the **rules** associated with them are then evaluated and run first.  If these had any further dependencies they would be evaluated and run first, creating the **chain** of dependencies.  Notice that the ordering is the opposite of the order you would follow buiding each step manually, with the most general (the ultimate result) appearing first, working its way down the file to the more specific components.

# Command Line Options

* **-n** - print the output of the make as if the commands executed, but don't actually execute anything.

# Example Makefiles

## Using both nasm and c and creating an iso file

```make
CC=gcc
AS=nasm
TARGET=myos
C_FILES=./kernel.c
OBJS=$(C_FILES:.c=.o)

all compile: $(TARGET)
all: finale
.PHONY: all compile clean finale

%.o:
    $(CC) -c $(@:.o=.c) -o $@ -ffreestanding -fno-exceptions -m32

$(TARGET): $(OBJS)
    $(AS) -f elf kernel_load.asm -o kernel_load.o
    $(CC) -m32 -nostdlib -nodefaultlibs -lgcc kernel_load.o  $? -T linker.ld -o $(TARGET)

finale:
    $(shell cp $(TARGET) ./iso/boot/$(TARGET))
    $(shell grub-mkrescue iso --output=$(TARGET).iso)

clean:
    rm -f *.o $(TARGET) $(TARGET).iso
    find . -name \*.o | xargs --no-run-if-empty rm


