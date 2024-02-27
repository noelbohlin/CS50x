#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    // Choose pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRED = 0, sumGREEN = 0, sumBLUE = 0;
            int counter = 0;

            // look at 3x3 square around chosen pixel
            for (int row = -1; row <= 1; row++)
            {
                for (int column = -1; column <= 1; column++)
                {
                    // if pixel in square is outside picture, dont use in calculation
                    if (i + row < 0 || i + row > height - 1)
                    {
                        continue;
                    }
                    if (j + column < 0 || j + column > width - 1)
                    {
                        continue;
                    }
                    counter++;

                    sumRED += image[i + row][j + column].rgbtRed;
                    sumGREEN += image[i + row][j + column].rgbtGreen;
                    sumBLUE += image[i + row][j + column].rgbtBlue;
                }
            }
            tmp[i][j].rgbtRed = round(sumRED / (float) counter);
            tmp[i][j].rgbtGreen = round(sumGREEN / (float) counter);
            tmp[i][j].rgbtBlue = round(sumBLUE / (float) counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}, Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE tempImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gx_Blue = 0, Gy_Blue = 0, Gx_Green = 0, Gy_Green = 0, Gx_Red = 0, Gy_Red = 0;

            for (int row = -1; row < 2; row++)
            {
                for (int column = -1; column < 2; column++)
                {
                    if (i + row < 0 || i + row > height - 1)
                    {
                        continue;
                    }

                    if (j + column < 0 || j + column > width - 1)
                    {
                        continue;
                    }

                    Gx_Blue += image[i + row][j + column].rgbtBlue * Gx[row + 1][column + 1];
                    Gy_Blue += image[i + row][j + column].rgbtBlue * Gy[row + 1][column + 1];
                    Gx_Green += image[i + row][j + column].rgbtGreen * Gx[row + 1][column + 1];
                    Gy_Green += image[i + row][j + column].rgbtGreen * Gy[row + 1][column + 1];
                    Gx_Red += image[i + row][j + column].rgbtRed * Gx[row + 1][column + 1];
                    Gy_Red += image[i + row][j + column].rgbtRed * Gy[row + 1][column + 1];
                }
            }

            int blue = round(sqrt(Gx_Blue * Gx_Blue + Gy_Blue * Gy_Blue)),
                green = round(sqrt(Gx_Green * Gx_Green + Gy_Green * Gy_Green)),
                red = round(sqrt(Gx_Red * Gx_Red + Gy_Red * Gy_Red));

            if (blue > 255)
            {
                blue = 255;
            }

            if (green > 255)
            {
                green = 255;
            }

            if (red > 255)
            {
                red = 255;
            }

            tempImage[i][j].rgbtBlue = blue;
            tempImage[i][j].rgbtGreen = green;
            tempImage[i][j].rgbtRed = red;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tempImage[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tempImage[i][j].rgbtGreen;
            image[i][j].rgbtRed = tempImage[i][j].rgbtRed;
        }
    }

    return;
}
