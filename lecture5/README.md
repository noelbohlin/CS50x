# Lecture 5 - Data Structures

## Data Structures

Are different ways to organize data in memory.

## Stacks and Queues

### Queues

Queues are exaclty like in real life, they are **FIFO**, *First in first out*.

The act of *"Getting in the queue"* is called getting **enqueued**.

The opposite, getting to go on the ride or leaving the queue is called getting **dequeued**.

```c
const int CAPACITY

typedef struct
{
    person people[CAPACITY];
    int size;
} queue;
```

### Stacks

Stacks are like stacking clothes in a drawer, they are **LIFO**, *Last in first out*.

The act of putting something on the top of the stack is called **push**.

The act of taking something from the top of the stack is called **pop**.

```c
typedef struct
{
    person people[CAPACITY];
    int size;
} stack;
```

Observe that this code is in no way different from the queue. this struct does not include the LIFO or FIFO code needed to differentiate the two.

## Resizing Array

An array is a block of continious memory and is a type of data structure.

![Array1](image.png)

```c
#include <stdio.h>

int main(void)
{
    int list[3];

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}
```

Imagine this array of 3. Now you want to store a fourth value. This is not possible due to the string in the way, and storing the next value somewhere else would not make it an array.

![Array2](image-1.png)

![Array3](image-2.png)

You could copy it to another place that is one space bigger and then add the new value.

This is bad design because we have to copy the array number by number and the array takes up double the space during the copying.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // List of size 3
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    // Initialize list of size 3 with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // List of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // Copy list of size 3 into list of size 4
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // Add number to list of size 4
    tmp[3] = 4;

    // Free list of size 3
    free(list);

    // Remember list of size 4
    list = tmp;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);
    return 0;
}
```

It’s useful to think about *list* and *tmp* as both signs that point at a chunk of memory. As in the example above, *list* at one point pointed to an array of size 3. By the end, *list* was told to point to a chunk of memory of size 4. Technically, by the end of the above code, *tmp* and *list* both pointed to the same block of memory.

## Linked Lists

### Operators

A *struct* is a data type that you can define yourself.

A *.* in dot notation allows you to access variables inside that structure.

The *\** operator is used to declare a pointer or dereference a variable.

The *->* operator goes to an address and looks inside of a structure.

A linked list is one of the most powerful data structures within C. A linked list allows you to include values that are located at varying areas of memory. Further, they allow you to dynamically grow and shrink the list as you desire.

### Abstract linked list

You might imagine three values stored at three different areas of memory as follows:

![Linked List1](image-3.png)

A choice between space efficiency and speed has been made. Each datapoint in the linked list takes up two spaces in memory. The first space is the data. The other space, or metadata, is a pointer pointing to the next datapoint in the list.

![Linked List2](image-4.png)

These boxes are called nodes. A node contains both an *item* and a pointer called *next*.

```c
typedef struct node
{
    int number;
    struct node *next;
}
node;
```
