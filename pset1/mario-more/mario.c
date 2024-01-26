#include <cs50.h>
#include <stdio.h>

#define PYRAMIDHEIGHT 9

int main(void)
{
    int height;

    while (true)
    {
        height = get_int("Height: ");

        if (0 < height && height < PYRAMIDHEIGHT)
        {
            break;
        }
        continue;
    }

    for (int row = 0; row < height; row++)
    {
        for (int cursorplacement = 0; cursorplacement < height; cursorplacement++)
        {
            if (row + cursorplacement < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int cursorplacementright = 0; cursorplacementright < row + 1; cursorplacementright++)
        {
            printf("#");
        }
        printf("\n");
    }
}
