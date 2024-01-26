# Lecture 1 - C

## Hello, World

``` c
printf("hello, world\n");
```

- \n = new line
- printf = print format
- \# include standard I/O
- semicolon at the end

### hello.c

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

### Hello You

Using the cs50 library we have a I assume class string we get with the get_string function, **not standard in C**

in C using the **"%s"** as placeholder for the variable answer

``` C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```

### printf Format Codes

These are some of the simple format codes (not all of them)

``` C
%c /* char */

%f /* float or double */

%i /* int */

%li

%s /* string */
```

## Comparison

### Variables

These are the same:

```c
counter = counter + 1;

counter += 1;

counter++;
```

Same but with subtraction

```c
counter = counter - 1;

counter -= 1;

counter--;
```

-----

```c
#include <stdio.h>

int main(void)
{
    int counter = 0;
    counter++;
    counter++;
    counter--;
    printf("%i\n", counter);
}
```

```bash
$ ./compare
1
```

### compare.c

Compares input

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else if (x == y)
    {
        printf("x is equal to y\n");
    }
}
```

-----

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("%i is less than %i\n", x, y);
    }
    else if (x > y)
    {
        printf("%i is greater than %i\n", x, y);
    }
    else
    {
        printf("%i is equal to %i\n", x, y);
    }
}
```

### agree.c

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* Prompt user to agree */
    char c = get_char("Do you agree? (Y/N) ");

    /* Check whether agreed */
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}
```

- **'** single qoutes for single characters
- **"** double quotes for multiple characters
- **||** means **"or"**
- **&&** means **"and"**

## Loops

### meow.c

```c
#include <stdio.h>

int main(void)
{
    int i = 3;
    while (i > 0)
    {
        printf("meow\n");
        i--;
    }
}
```

Same but with counting up

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}
```

-----

using for loop, most used way to make loops

```c
for (int i = 0; i < 3; i++)
```

1. initializes variable
2. boolean expression
3. the end of the loop

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
}
```

## Functions

### meow function

abstract the problem

```c
#include <stdio.h>

void meow(void);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

void meow(void)
{
    printf("meow\n");
}
```

add this to the top. This **prototype** calls the definition of the funcion at the bottom of the code.

```c
void meow(void);
```

-----

### make the funcion accept input

```c
#include <stdio.h>

void meow(int n);

int main(void)
{
    meow(3);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

## Calculator

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", x + y);
}
```

### Abstract the addition to a separate function

```c
int add(int a, int b)
{
    int c = a + b;
    return c;
}
```

This get you the total of

```c
#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
}
```

after a little compacting.

-----

### Scope

You have to define new variables in the new function. The scope of the variables exist only in the context they were created.

## Linux

- ```cd```, for changing our current directory (folder)
  - ```cd ..```
- ```cp```, for copying files and directories
- ```ls```, for listing files in a directory
  - ```ls -la```
- ```mkdir```, for making a directory
- ```mv```, for moving (renaming) files and directories
  - ```mv oldfilename newfilename```
- ```rm```, for removing (deleting) files
- ```rmdir```, for removing (deleting) directories

## Mario

### Horisontal **?**

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n");
}
```

### Vertical blocks

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("#\n");
    }
}
```

### Cube

```c
#include <stdio.h>

int main(void)
{
    // print one row at a time
    for (int i = 0; i < 3; i++)
    {
        // print a column
        for (int j = 0; j < 3; j++)
        {
            printf("#");
        }

        // start printing next line
        printf("\n");
    }
}
```

With constant size but easily changeble:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int 5
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```

With variable size:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```

This uses the

```c
do
{}
while ();
```

loop

## Types

### Integer Overflow

if the PC don't have enough memory the numbers will "wrap around" and start at 0 again.

```int```s maximal size is 4294967295

### example of types

- bool, a Boolean expression of either true or false
- char, a single character like a or 2
- double, a floating-point value with more digits than a float
- float, a floating-point value, or real number with a decimal value
- int, integers up to a certain size, or number of bits
- long, integers with more bits, so they can count higher than an int
- string, a string of characters

### Truncation

int / int will throw away all the decimals. You have to use type casting to make this work.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    float z = (float) x / (float) y
    printf("%f\n", z);
}
```

### Floating point imprecision

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    double z = (double) x / (double) y
    printf("%.20f\n", z);
}
```

due to memory limitation and how computers deal with numbers floats and doubles won't be exact.

## Summary

- How to create your first program in C.
- Predefined functions that come natively with C and how to implement your own functions.
- How to use variables, conditionals, and loops.
- How to approach abstraction to simplify and improve your code.
- How to approach problem-solving for a computer science problem.
- How to use the Linux command line.
- How to integrate comments into your code.
- How to utilize types and operators.
