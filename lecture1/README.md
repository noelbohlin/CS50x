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

make the funcion accept input

```c
#include <stdio.h>

void meow(int n);

int main(void)
{
    meow(3);
}

// Meow some number of times
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

## Calculator
