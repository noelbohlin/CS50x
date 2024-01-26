# Lecture 2 - Arrays

## Compiling

### make and clang

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

```make``` is a program that uses another compiler to make it easier for the user to compile code.

```make hello``` == ```clang -o hello hello.c```

**clang** is the actual compiler

### clang with libraries

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
```

trying to compile this won't work because the library isn't included in **C**

You have to run this:

```clang -o hello hello.c -lcs50``` which still is equal to ```make hello```

### What is compiling

#### 1. Preprocessing

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
```

**#** means the line is a "Preprocessor directive"

Those lines gets replaced with definitions of functions

```c
string get_string(string prompt);
int printf(string format, ...);

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
```

I.E. **converts include files to the underlying prototypes**

#### 2. Compiling

The program is converted to Assembly language

#### 3. Assembling

Converts Assembly code to machine code i.e. **0's and 1's**

#### 4. Linking

Code from the included libraries aare converted to machine code and combined with the programs code.

The final code is the outputted.

## Debugging





## Arrays

## Strings
