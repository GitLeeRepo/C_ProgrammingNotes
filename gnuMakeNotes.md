# Overview

Notes on the GNU Make program.

# References

* [gnuMake Docs](https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents)

## Books

* [Making Projects with GNU Make](https://www.amazon.com/Managing-Projects-GNU-Make-Handbooks/dp/0596006101/ref=cm_cr_arp_d_product_top?ie=UTF8) - from O'Reilly

## My Other Notes

* [C_ProgrammingNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/C_ProgrammingNotes.md#overview)

# Terminology and Concpts

* **target** - refer to the **Very Simple Make File** section
* **prerequisite** - refer to the **Very Simple Make File** section
* **command** - refer to the **Very Simple Make File** section
* **rule** - refer to the **Very Simple Make File** section

* **\\** - the **backslash** is used to **continue a line** to the next line.
* **all** - the standard first **target** in many Makefiles
* **.PHONY** - used to tell make that the **target** is not a file.  The **clean** target is a typical example.  You don't want this interpreted being a file named **clean**, so to prevent this you define clean as a **.PHONY** target".  Phony targets can be used to provide a series of shell commands, such as moving and copying files, or to print informative/help messages.  Phony targets are evaluated before other targets, so in the case of a **clean** phony target it would delete all the \*.o files before the compile is run. In addition, phony targets almost alway execute, because the commands that execute are not directly tied to the target name. Example syntax:

```make
.PHONY: clean finale
```
Note: finale was added here as an example of having two phony targets, to show they are delimeted by spaces.

# Command Line Options

* **-n** - print the output of the make as if the commands executed, but don't actually execute anything.

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

# Wildcard Exampansion

Make supports the Bourne shell wildcards

* **\*** (astericks) - match all for shell commands
* **\%** (percent) - match all - roughly equivellent to shell`s asterisk
* **\?** (question) - match a single character
* **\~** (tilde) - expand to user's home directory
* **\^** (caret) - negate the pattern

Note that wildcard expansion is done by make itself when it applies to the **target** or **prerequisite** lines, where as wildcards on the **command** lines are interpretted by the shell.

# Variables

* **\$\(varname\)** - specifies that variable to be expanded, whatever is in the variable will be expanded to include everything it  contains.  Curly brackets can also be used **\$\{varname\}**.  For a single character variable, the parenthesis and brackedts can be excluded.

## Predefined Variables
* **\@** (at sign) - the target filename
* **\%** (percent sign) - the filename element of an archive member specification.  It can only occur once in a pattern.
* **\$\?** (question mark) - a predefined variable that is the set of the prerequisites that are newer than the target
* **\<** (left angle) - the filename of the first prerequisite
* **\^** (caret) - the filenames of all the prerequisites separated by a space (duplicates removed)
* **\+** (plus) - the filenames of all the prerequisites separated by a space (duplicates included)
* **\*** (asterisks) - the stem portion of the target filename (the part without the extension)
* **\$(@D)** (asterisks) - the directory portion of a filename
* **\$(@F)** (asterisks) - the file portion of a filename

Examples:

```make
# Includes all prerequisites and the target name
hello: hello.o languages.o
        gcc $^ -o $@
        
# Includes the first prerequite 
hello: hello.o 
        gcc -c $<
```

## VPATH variable and vpath directive

### VPATH variable
When the source files are not in the directory where make is run you can specify their location with:

```make
VPATH=src
```

### vpath directive

The sources files are in the src subdirectory

syntax: vpath \<pattern\> \<directory\>

```make
vpath %.c src
vpath %.h include
```
Tells make to look in src for c files, and inlclude for header files

# Built-In Pattern Rules

There are three built-in **pattern rules**

The **\%.o**:

```make
%.o: %.c
        $(COMPILE.c) $(OUTPUT_OPTION) $<
```

The **\%.c**:

```make
%.c: 
        $(COMPILE.c) $(OUTPUT_OPTION) $<
```

The **\%:%%** - the executable file without an extension

```make
# link the object files and output to the target
%: %.o
        $(LINK.O) $^ -o $@
```

# Implicit Rules

There are several built-in implicit rules that you can use.  They can be customized by assigning specific values to the, for example

```make
CC=gcc
AS=nasm
```

A list of implicit rules can be obtained from the make database (enter **make --print-data-base** or **make -p**).  For better filtering of this file try the following:

```bash
# Display the Implicit Rules section of the make database, excluding non-rule based data sections

make -p | sed -n '/# Implicit Rules/,/# Files/ p' | less

# or for a specific rule you can use grep

make -p | grep 'ruleToSearchFor' # to look for a specific rule
```
Note the **sed** option above is useful since it only displays the **# Implicit Rules** section of this much large file.  Be aware though that the search patterns used may not work if the format of the file is different from when this was run, so it may need to be updated.  The idea is to grab all text between the first search pattern and the second search pattern.

## Example of Implicit Rules in Make's Database

Just a few of the many rules:

```make
%: %.o
#  recipe to execute (built-in):
        $(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

%: %.c
#  recipe to execute (built-in):
        $(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@
	
%.o: %.c
#  recipe to execute (built-in):
        $(COMPILE.c) $(OUTPUT_OPTION) $<
```

1. The first rule builds the executable (the **%:** and **-o $@**) from the object files (placeholder **$(LINK.o)** if the prereq is newer (**$^**) and links in any **$(LOADLIBES)** and  **$(LDLIBS)** that are set.
2. The second rule builds the executable (the **%:** and **-o $@**) from the C files (placeholder **$(LINK.c)** if the prereq is newer (**$^**) and links in any **$(LOADLIBES)** and  **$(LDLIBS)** that are set.
3. The third rule builds an object file (the **%.o:** and **-o $@**) from the C files (placeholder **$(COMPILE.c)** with the output options specified by **$(OUTPUT_OPTION)** using the filename of the first prerequisite (**$<**)

Note that these predefined Implicit Rules make the creation of the actual make file much easier since you can rely on the predefined options.  A good example of a makefile that relies on the second rule is the [## Multiple Executables](#multiple-executables) example in the Examples section later in this document.

## Examples of Variable used in Implicit Rules (there are many more than listed)

* **COMPILE.C** -
* **LINK.C** -
* **LINK.o** -
* **LOADLIBES** - 
* **LDLIBS** -
* **OUTPUT_OPTIONS** -
* **CC** - c compiler
* **AS** - assembler
* **RM** - rm -f

# Example Makefiles

## Multiple Executables

Refer to the comment included in the makefile below for details, and to the output which follows

```make
# Simple make for compiling individual C files into individual executables of the same name.
# It is not suitable (in its current form) for executables made up of multiple object files.
# Intended for compiling simple demo/concept programs
# This relies on implicit variables and default actions to do the compile of the ${EXE} target.
# The implicit CC and CFLAGS are redefined here, while RM uses the default 'rm -f'
# Only recompiles the specified files and header if they have changed since last compile

EXE = unix_socket_srv unix_socket_clnt tcp_socket_srv tcp_socket_clnt
INCFILES = unix_socket.h
CC=gcc
CFLAGS = -gdwarf -Wall

.PHONY: info clean

all: info ${EXE}

info:
	@echo "Info: make for: $(EXE)"

# compile happens here
${EXE}: $(INCFILES) 

clean:
	$(RM) $(EXE)
```

**OUTPUTS:**

```bash
$ make clean
rm -f unix_socket_srv unix_socket_clnt tcp_socket_srv tcp_socket_clnt
$ make
Info: make for: unix_socket_srv unix_socket_clnt tcp_socket_srv tcp_socket_clnt
gcc -gdwarf -Wall    unix_socket_srv.c unix_socket.h   -o unix_socket_srv
gcc -gdwarf -Wall    unix_socket_clnt.c unix_socket.h   -o unix_socket_clnt
gcc -gdwarf -Wall    tcp_socket_srv.c unix_socket.h   -o tcp_socket_srv
gcc -gdwarf -Wall    tcp_socket_clnt.c unix_socket.h   -o tcp_socket_clnt
```

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


