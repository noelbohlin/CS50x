# Lecture 3

## Search

### Linear Search

```c
For each door from left to right
    If 50 is behind door
        Return true
Return false
```

psuedocode

Linear Search search an array by going through each entry in order until the result is found.

```c
For i from 0 to n-1
    If 50 is behind doors[i]
        Return true
Return false
```

psuedocode

### Binary Search

```c
If no doors left
    Return false
If 50 is behind middle door
    Return true
Else if 50 < middle door
    Search left half
Else if 50 > middle door
    Search right half
```

psuedocode

Also called the divide and counquer method.

```c
If no doors left
    Return false
If 50 is behind doors[middle]
    Return true
Else if 50 < doors[middle]
    Search doors[0] through doors[middle - 1]
Else if 50 > doors[middle]
    Search doors[middle + 1] through doors[n - 1]
```

psuedocode

### Running Time

![Running Time](image.png)

Running time is often described and simplified using "*big O*" notation. *Big O* removes the constants and describe the sorting times using the *order of n*.

Some common running times are:

- *O*(n²)
- *O*(n log n)
- *O*(n)
- *O*(log n)
- *O*(1)

In these examples *O*(1) is the best and *O*(n²) is the worst.

Linear search was of order *O*(n) because it could take n steps in the worst case to run. Binary search was of order *O*(log n) because it would take fewer and fewer steps to run even in the worst case, or upper bound.

The best case, or lower bound, is denoted using the omega **Ω** symbol, like **Ω**(log n).
the **Θ** symbol is used when the upper and lower bounds are the same.

### search.c

Linear search:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // An array of integers
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // Search for number
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

```c

```

## Data Structures