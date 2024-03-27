PYRAMIDHEIGHT = 9

while True:
    try:
        height = int(input("Height: ").strip())

        if 0 < height < PYRAMIDHEIGHT:
            break
        continue
    except ValueError:
        continue

row: int = 0
while row < height:

    cursorplacement: int = 0
    while cursorplacement < height:

        if row + cursorplacement < height - 1:
            print(" ", end="")
        else:
            print("#", end="")

        cursorplacement += 1

    print("  ", end="")

    cursorplacementright: int = 0
    while cursorplacementright < (row + 1):

        print("#", end="")
        cursorplacementright += 1

    print()
    row += 1
