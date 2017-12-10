# Overview

Notes on the GNU Make program.

# References

* [gnuMake Docs](https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents)

## Books

* [Making Projects with GNU Make](https://www.amazon.com/Managing-Projects-GNU-Make-Handbooks/dp/0596006101/ref=cm_cr_arp_d_product_top?ie=UTF8) - from O'Reilly

## My Other Notes

* [C_ProgrammingNotes](https://github.com/GitLeeRepo/C_ProgrammingNotes/blob/master/C_ProgrammingNotes.md#overview)

# Terminology and Concpts

## Rules

* **target** - refer to the **Very Simple Make File** section
* **prerequisite** - refer to the **Very Simple Make File** section
* **command** - refer to the **Very Simple Make File** section
* **rule** - refer to the **Very Simple Make File** section

## General

* **\\** - the **backslash** is used to **continue a line** to the next line.
* **%** - the **percent** is used in **built-in/pattern rules** much like the asterisk in shell scripts as a wildcard match.  Refer to **built-in rules**
* **all** - the standard first **target** in many Makefiles
* **automatic variables** - a set of built-in variables that provide access to the **target** and **prerequisites** without having to provide literal filenames.  Examples include **$@**, **$^**, etc.
* **built-in rules** - are **pattern rules** and are like normal rules except the **stem** of the file (the non-suffix part) are represented by **%**.  They include **%.c** for C files, **%.o**for object files and **%** by itself for stem files (executable).  The percent sign functions much like the shell's **\*** asterisk as a wildcard match
* **implicit rules** - are **pattern or suffix rules** found in the **rules database** that handle many common task such as compiling and linking to object files or executables with default behaviors that can be changed through changing the associated built-in variables (**CC**, **CFLAGS**, etc).  They make building make files easier by not having to explicitly specify commands and parameters.
* **.PHONY** - used to tell make that the **target** is not a file.  The **clean** target is a typical example.  You don't want this interpreted being a file named **clean**, so to prevent this you define clean as a **.PHONY** target".  
* **predefined variables** - those variables defined or used in the **rules database** that are used by **built-in** and **implicit** rules.  They include **CC**, **CFLAGS**, **COMPILE.c**, **LINK.c**, **LINK.o**, **RM**, **LOADLIBES**, **LDLIBS**, **OUTPUT_OPTION**, etc
* **rules database** - access with **make -p** contains **variables** (including **automatic variables**),  **implicit rules**, **file types** (\*.c, \*.o, etc) and their associated **built-in rules**

# Command Line Options

* **-n** - print the output of the make as if the commands executed, but don't actually execute anything.
* **-p** or **--print-data-base** - print the make **database** which contains **variables** (including **automatic variables**),  **Implicit Rules**, **Files Types** (\*.c, \*.o, etc) and their associated **Built-In Rules**

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

## Automatic Variables
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

## Predefined Variables

**predefined variables** - those variables defined or used in the **rules database** that are used by **built-in** and **implicit** rules.  All of these variables can be redefined in the user's make file.

All the variables listed here are **used** in the **rules database**, regardless of whether they are initialized or not.  Any variable that remains uninitialized when included in a rule will be ignored.

* **CC** - default: cc
* **CFLAGS** - not pre-initialized
* **COMPILE.c** - default: $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
* **LINK.c** - default: $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)
* **LINK.o** - default: $(CC) $(LDFLAGS) $(TARGET_ARCH)LDFLAGS** - 
* **LDFLAGS** - not pre-initialized
* **RM** - default: rm -f
* **LOADLIBES** - not pre-initialized
* **LDLIBS** - not pre-initialized
* **OUTPUT_OPTION** - default: -o $@

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

# .PHONY

* **.PHONY**  is used to tell make that the **target** is not a file.  The **clean** target is a typical example.  You don't want this interpreted being a file named **clean**, so to prevent this you define clean as a **.PHONY** target".  Phony targets can be used to provide a series of shell commands, such as moving and copying files, or to print informative/help messages.  Phony targets are evaluated before other targets, so in the case of a **clean** phony target it would delete all the \*.o files before the compile is run. In addition, phony targets almost alway execute, because the commands that execute are not directly tied to the target name. Example syntax:

```make
.PHONY: clean finale
```
Note: finale was added here as an example of having two phony targets, to show they are delimeted by spaces.

# Example Makefiles

## Multiple Executables

Refer to the comment included in the makefile below for details, and to the output which follows

```make
# Simple make for compiling individual C files into individual executables of 
# the same name. Intended for compiling simple demo/concept programs with 
# multiple executables in same directory This relies on implicit variables 
# and default actions to do the compile of the $(EXE) target. The implicit CC 
# and CFLAGS are redefined here, while RM uses the default 'rm -f'. Only 
# recompiles the specified files and header if they have changed since last 
# compile

# common library and include directory
COMMON_DIR = ../commonlib
COMMON_LIB = $(COMMON_DIR)/common.o
COMMON_INCL = $(COMMON_DIR)/common.h

EXE = unix_socket_srv unix_socket_clnt tcp_socket_srv tcp_socket_clnt
INCFILES = $(COMMON_INCL) socket.h
LDLIBS = $(COMMON_LIB)
CC=gcc
CFLAGS = -gdwarf -Wall

.PHONY: info clean

all: info $(LDLIBS) $(EXE)

info:
	@echo "Info: make for: $(EXE)"

# compile happens here
$(EXE): $(INCFILES)  

# compile common object file
$(LDLIBS): $(INCFILES) 

clean:
	$(RM) $(EXE) *.o

```

**OUTPUTS:**

```bash
$ make clean
rm -f unix_socket_srv unix_socket_clnt tcp_socket_srv tcp_socket_clnt
$ make
gcc -gdwarf -Wall unix_socket_srv.c ../commonlib/common.h socket.h  ../commonlib/common.o -o unix_socket_srv
gcc -gdwarf -Wall unix_socket_clnt.c ../commonlib/common.h socket.h  ../commonlib/common.o -o unix_socket_clnt
gcc -gdwarf -Wall tcp_socket_srv.c ../commonlib/common.h socket.h  ../commonlib/common.o -o tcp_socket_srv
gcc -gdwarf -Wall tcp_socket_clnt.c ../commonlib/common.h socket.h  ../commonlib/common.o -o tcp_socket_clnt
```

## Including a GCC Library (mathlib)

This one includes the math.h related mathlib by using the **-lm** switch.  This required more specific rules defined in this make, than in the prior example which relied almost entirely on default behaviors. This one specifies more explict rules such as **$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) $(OUTPUT_OPTION)** so that the **OUTPUT_OPTION** on the end could include the **-lm** flag (it doesn't work by including it in the CFLAGS or LDFLAGS).

Note the use of the **%:** wildcard for the target instead of my usual **$(EXE):** target.  This was necessary so I could use the **%.c** prerequisite needed by the **LINK.c** variable.  Even though the **$(EXE)** is not explicitly used here as the target it is still related, notice the **all:** specifies it which provides a reference to the **%:** target label.

```make
# common library and include directory
COMMON_DIR = ../../commonlib
COMMON_LIB = $(COMMON_DIR)/common.o
COMMON_INCL = $(COMMON_DIR)/common.h

EXE = math_example
INCFILES = $(COMMON_INCL)
LDLIBS = $(COMMON_LIB)
CC=gcc
CFLAGS = -gdwarf -Wall 
# Note math.h functions need math lib linked (-lm)
OUTPUT_OPTION = -o $@ -lm

.PHONY: info clean

all: info $(LDLIBS) $(EXE) 

info:
	@echo "Info: make for: $(EXE)"

	
# compile happens here
%: %.c $(INCFILES) 
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) $(OUTPUT_OPTION)

# compile common object tile
$(LDLIBS): $(INCFILES) 

clean:
	$(RM) $(EXE) *.o
```

**Output:**

```bash
Info: make for: math_example
gcc -gdwarf -Wall     math_example.c ../../commonlib/common.h  ../../commonlib/common.o -o math_example -lm
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


