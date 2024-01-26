#include <cs50.h>
#include <stdio.h>

int checksum(long n);
void checklength(long n);

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

int checksum(long n)
{
    long check_number = n;
    int sum1 = 0;
    int sum2 = 0;
    int sumtotal = 0;
    int lastdigit;
    int secondlastdigit;
    int digit1;
    int digit2;

    // removes 2 digits per "lap"
    do
    {
        // Remove last digit and add to sum1
        lastdigit = check_number % 10;
        check_number /= 10;
        sum1 += lastdigit;

        // Remove second last digit
        secondlastdigit = check_number % 10;
        check_number /= 10;

        // Double second last digit
        secondlastdigit *= 2;

        // add digits to sum
        digit1 = secondlastdigit % 10;
        digit2 = secondlastdigit / 10;
        sum2 = sum2 + digit1 + digit2;
    }

    while (check_number > 0);
    sumtotal = sum1 + sum2;

    if (sumtotal % 10 != 0)
    {
        return 0;
    }
    return 1;
}

void checklength(long n)
{
    long credit_number = n;
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
