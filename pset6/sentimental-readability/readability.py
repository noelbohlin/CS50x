def main():
    input_text = input("Text: ")

    output = grade(
        letter_count(input_text), word_count(input_text), sentence_count(input_text)
    )

    if output < 1:
        print("Before Grade 1\n")

    elif output >= 16:
        print("Grade 16+\n")

    else:
        print(f"Grade {output}\n")


def letter_count(input):
    count = 0

    for char in input:
        if char.isalpha():
            count += 1

    return count


def word_count(input):
    count = 1

    for char in input:
        if char.isspace():
            count += 1

    return count


def sentence_count(input):
    count = 0

    for char in input:
        if char in ('.', '!', '?'):
            count += 1

    return count


def grade(l, w, s):

    L = l / (w / 100)
    S = s / (w / 100)

    index = 0.0588 * L - 0.296 * S - 15.8

    return round(index)


main()
