# Lecture 7 - SQL

SQL - Structured Query Language.

## Flat-File Database

As you have likely seen before, data can often be described in patterns of columns and rows.
Spreadsheets like those created in Excel can be outputted to a csv or "comma-separated values" file.

To manipulate and read these types of files you can use Python.

```Python
import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row["language"])
```

This example uses data from the lectures and prints out the favorite language of each the students present. Just a list of all the answers to that particular question.

-----

```python
# Sorts favorites by value using .get

import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = {}

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

# Print counts
for favorite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favorite}: {counts[favorite]}")
```

Notice the arguments passed to sorted. The key argument allows you to tell Python the method you wish to use to sort items. In this case counts.get is used to sort by the values. reverse=True tells sorted to sort from largest to smallest.

-----

Using a library

```python
import csv

from collections import Counter

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = Counter()

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1

# Print counts
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
```

-----

Gets a specific count

```python
# Gets a specific count

import csv

from collections import Counter

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = Counter()

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1

# Print count
favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite]}")
```

## Relational Databases

Relational databases store data in rows and columns in structures called tables.

Google, Twitter, and Meta all use relational databases to store their information at scale.

