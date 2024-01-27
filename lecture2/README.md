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

- bool 1 byte
- int 4 bytes
- long 8 bytes
- float 4 bytes
- double 8 bytes
- char 1 byte
- string ? bytes

Your RAM is simply a "canvas" with a finite number of bytes available to store and manipulate.

### scores.c

```c
#include <stdio.h>

int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}
```

each score here is taking up 4 bytes of memory.

```c
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;
```

code like this will get very messy in the long run. And teh memory allocation is not organized by us.

### Array

Array is a sequence of values followed by each other in memory. Numbers back to back to back.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int scores[3];
    scores[0] = get_int("Score: ");
    scores[1] = get_int("Score: ");
    scores[2] = get_int("Score: ");

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```

-----

```c
int scores[3]
```

is a way of telling the compiler to provide you three back-to-back places in memory of size int to store three scores.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int N = 3
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) N);
}
```

-----

Abstracting away the averaging

```c
#include <cs50.h>
#include <stdio.h>

// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void)
{
    // Get scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
```

## Strings

### Strings vs arrays

In this class the library CS50 creates the string class. Usually in **C** you use ```char string[] = "characters";```

```c
#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c%c\n", c1, c2, c3);
}
```

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%c%c%c\n", s[0], s[1], s[2]);
}
```

These are the same.

-----

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}
```

This illustrates that characters are just numbers.

-----

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
}
```

Here the array words in an array where each value is a array with a word. Each word is also an array of characters.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%s\n", words[1]);
}
```

The 2 above gives the same output.

## String Length

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    // Count number of characters up until '\0' (aka NUL)
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
}
```

Abstracting away to a function.

```c
#include <cs50.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);
}

int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
```

-----

Using the string library ```<string.h>```

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("Name: ");
    int length = strlen(name);
    printf("%i\n", length);
}
```

## Uppercase

### Manually

This function looks at the ASCII value and subtract 32 to get the uppercase letter if it is lowercase (betwwen 97 and 122).

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```

Notice how ```i``` doesn't iterate over the function directly. Rather strlen(s) is initialized as ```n``` so that the function strlen() doesn't have to run over and over again:

```c
    for (int i = 0, n = strlen(s); i < n; i++)
```

-----

### Using ```<ctype.h>```

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
```

```toupper()``` will uppercase the letter if it is lowercase.

## Command-Line Arguments

- argc the number of command-line arguments
- argv array of characters passed as arguments.
