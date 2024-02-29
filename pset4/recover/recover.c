#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Can't open the provided file\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    FILE *output = NULL;
    int JPEGcount = 0;
    char *filename = malloc(3 * sizeof(int));

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // I don't really know why this closing of the file is needed. but I get a memory leak otherwise.
            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(filename, "%03d.jpg", JPEGcount++);
            output = fopen(filename, "w");
        }

        if (output != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);
    free(filename);
}
