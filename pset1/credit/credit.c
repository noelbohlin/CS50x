#include <cs50.h>
#include <stdio.h>

int checksum(long check_number);
void checklength(long credit_number);

int main(void)
{
    long credit_card_number = get_long("Number: ");

    if (checksum(credit_card_number) == 1)
    {
        checklength(credit_card_number);
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

int checksum(long check_number)
{
    int sum = 0;
    int secondlastdigit;

    // removes 2 digits per "lap"
    do
    {
        // Remove last digit and add to sum
        sum += check_number % 10;
        check_number /= 10;

        // Remove second last digit, double it and add the separate digits to sum
        secondlastdigit = (check_number % 10) * 2;
        sum += secondlastdigit % 10;
        sum += secondlastdigit / 10;
        check_number /= 10;
    }
    while (check_number > 0);

    if (sum % 10 != 0)
    {
        return 0;
    }
    return 1;
}

void checklength(long credit_number)
{
    int length = 2;

    while (credit_number >= 100)
    {
        credit_number = credit_number / 10;
        length++;
    }

    if (credit_number >= 40 && credit_number <= 49 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else if ((credit_number == 34 || credit_number == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if (credit_number >= 51 && credit_number <= 55 && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
