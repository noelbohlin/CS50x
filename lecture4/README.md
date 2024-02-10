# Lecture 4 - Memory

## Pixelart

![photoshop](image.png)

A picture is represented by many pixels with a colour value of Red Green and Blue. Each colour has a value between **1** and **255**

## Hexadecimal

hexadecimal is counting with base 16, **0-F**(*0-15*)

    0 1 2 3 4 5 6 7 8 9 a b c d e f

    9 [base 10] == 09 [base 16]
    15 [base 10] == 0F [base 19]
    255 [base 10] == FF [base 16]

It is convention to prefix hexadecimal numbers with "**0x**"

    123 == 0x7B

## Memory

We have earlier visualized memory as a grid:

![Memory Grid](image-1.png)

### addresses.c

```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}
```

    & Provides the address of something stored in memory.
    * Instructs the compiler to go to a location in memory.

This program 