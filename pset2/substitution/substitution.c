#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool validate_length(int i, string s);
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    if (validate_length(argc, argv[1]) == false)
    {
        return 1;
    }

    encrypt(get_string("plaintext: "), argv[1]);
}

void encrypt(string text, string key)
{
    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            if (isupper(text[i]) != 0)
            {
                int index = text[i] - 'A';
                printf("%c", toupper(key[index]));
            }
            else
            {
                int index = text[i] - 'a';
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

bool validate_length(int c, string s)
{
    if (c != 2)
    {
        printf("Usage: $./substitution key\n");
        return false;
    }

    if (strlen(s) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == 0)
        {
            printf("Key must contain alphabetic characters only. \n");
            return false;
        }
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (toupper(s[j]) == toupper(s[i]))
            {
                printf("Key must not use repeat charaters. \n");
                return false;
            }
        }
    }
    return true;
}
