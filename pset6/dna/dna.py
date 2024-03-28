import csv
from sys import argv, exit


def main():
    # Check for command-line usage
    if len(argv) != 3:
        print("Missing command-line arguments")
        exit(1)

    # Read database file into a variable
    database = []
    with open(argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    with open(argv[2]) as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    STRs = reader.fieldnames
    STRs.remove("name")

    STR_count = {}
    for STR in STRs:
        STR_count[STR] = longest_match(sequence, STR)

    # Check database for matching profiles
    for person in database:
        match = True
        for STR in STRs:
            if int(person[STR]) != STR_count[STR]:
                match = False

        if match == True:
            print(person["name"])
            exit(0)

    print("No Match")
    exit(0)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
