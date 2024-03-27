PYRAMIDHEIGHT = 9

while True:
    try:
        height = int(input("Height: ").strip())

        if 0 < height and height < PYRAMIDHEIGHT:
            break
        continue
    except ValueError:
        continue

row = 0
while row < height:

    cursorplacement = 0
    while cursorplacement < height:

        if row + cursorplacement < height - 1:
            print(" ", end=(""))
        else:
            print("#", end=(""))

        cursorplacement += 1

    print("  ", end=(""))

    cursorplacementright = 0
    while cursorplacementright < (row + 1):

        print("#", end=(""))
        cursorplacementright += 1

    print()
    row += 1
