import math


def main():
    credit_card_number = int(input("Number: "))
    if (checksum(credit_card_number) == True):
        checklength(int(credit_card_number))

    else:
        print("INVALID\n")


def checksum(check_number):

    sum = 0
    secondlastdigit = 0

    # removes 2 digits per "lap"
    while (check_number > 0):
        # Remove last digit and add to sum
        sum += math.trunc(check_number % 10)
        check_number = math.trunc(check_number / 10)

        # Remove second last digit, double it and add the separate digits to sum
        secondlastdigit = (check_number % 10) * 2
        sum += secondlastdigit % 10
        sum += math.trunc(secondlastdigit / 10)
        check_number /= 10

    if (sum % 10 != 0):
        return False

    return True


def checklength(credit_number):
    length = 2

    while credit_number >= 100:
        credit_number = math.trunc(credit_number / 10)
        length += 1

    if (credit_number >= 40 and credit_number <= 49 and (length == 13 or length == 16)):
        print("VISA\n")

    elif ((credit_number == 34 or credit_number == 37) and length == 15):
        print("AMEX\n")

    elif (credit_number >= 51 and credit_number <= 55 and length == 16):
        print("MASTERCARD\n")

    else:
        print("INVALID\n")


main()
