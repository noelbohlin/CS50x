#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letter_count(string input);
int word_count(string input);
int sentence_count(string input);
int grade(int l, int w, int s);

int main(void)
{
    string input_text = get_string("Text: ");

    int output = grade(letter_count(input_text), word_count(input_text), sentence_count(input_text));

    if (output < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (output >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", output);
    }
}

int letter_count(string input)
{
    int count = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]) != 0)
        {
            count++;
        }
    }
    return count;
}

int word_count(string input)
{
    int count = 1;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isspace(input[i]) != 0)
        {
            count++;
        }
    }
    return count;
}

int sentence_count(string input)
{
    int count = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int grade(int l, int w, int s)
{
    float L = (float) l / ((float) w / 100);

    float S = (float) s / ((float) w / 100);

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}
