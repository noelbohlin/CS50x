#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    while (true)
    {
        height = get_int("Height: ");

        if (0 < height && height < 9)
        {
            break;
        }
        continue;
    }

    for (int row = 0; row < height; row++)
    {
        for (int blockplacement = 0; blockplacement < height; blockplacement++)
        {
            if (row + blockplacement < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int blockplacementright = 0; blockplacementright < row + 1; blockplacementright++)
        {
            printf("#");
        }
        printf("\n");
    }
}
