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

### buggy.c

```printf``` is a useful tool to catch bugs.

In this example we want to build a 3 block high stack

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 3; i++)
    {
        printf("i is %i\n", i);
        printf("#\n");
    }
}
```

but it builds 4

#### better ways

printf is just a lot of trial and error. separating functions makes bugs easuer to catch.

the same goal but with a different program

```c
#include <cs50.h>
#include <stdio.h>

void print_column(int height);

int main(void)
{
    int h = get_int("Height: ");
    print_column(h);
}

void print_column(int height)
{
    for (int i = 0; i <= height; i++)
    {
        printf("#\n");
    }
}
```

that has the same problem. It prints 4 blocks.

### Debugger

A debugger will help by excecuting the code one line at a time and displaying values of variables. This will make it possible to see the possible faults in the code.

In CS50 there is a debugger called ```debug50```

Here you can see that the variable h starts at 0 and ends with 3, thus printing 4 bricks instead of 3.

## Arrays

