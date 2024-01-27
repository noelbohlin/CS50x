#import <cs50.h>
#import <ctype.h>
#import <stdio.h>
#import <string.h>

int scrabble_score(string input);

int main(void)
{
    int score1 = scrabble_score(get_string("Player 1: "));
    int score2 = scrabble_score(get_string("Player 2: "));

    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
        return 0;
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        return 0;
    }
    printf("Tie!\n");
    return 0;
}

int scrabble_score(string input)
{
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]) == 0)
        {
            continue;
        }
        score += points[(toupper(input[i]) - 65)];
    }
    return score;
}
