#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(sizeof(int));
    x = 123;
    printf("%i\n", x);
}