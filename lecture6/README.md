# Lecture 6 - Python

## Python

In contrast to the compiled and low-level programming language C, Python is a high-level interpreted language using the Python interpreter.

Python is slower and more resource intensive in excecuting programs but saves you time writing many functions. All the ease of writing comes at the cost of programs in the background managing memory and helper functions that have more features than what you use at the moment.

C only runs the lines you have written, Python runs alot in the background.

## Hello

```python
print("hello, world")
```

Compared to C no main function need to be declared, no standard library need to be included, no semicolons are needed.

The print function also defaults ```end=("\n")```.

## Speller

The problem Speller from week 5 could in python be solved this way.

```python
words = set()


def check(word):
    """Return true if word is in dictionary else false"""
    return word.lower() in words


def load(dictionary):
    """Load dictionary into memory, returning true if successful else false"""
    with open(dictionary) as file:
        words.update(file.read().splitlines())
    return True


def size():
    """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
    return len(words)


def unload():
    """Unloads dictionary from memory, returning true if successful else false"""
    return True
```

The variable **words** is created as a **set** meaning it essentially becomes a list without duplicates.

The ```check(word)``` function simply looks if the inputed word is in the set words, if it is it returns **True**.

The ```load(dictionary)``` fuctions reads the dictionary file and loads each line in the file to the set **words**.

The ```unload()``` function is unnecessary in Python.

## Filter

The Filter problem could be solved this way in Python.

```python
# Blurs an image

from PIL import Image, ImageFilter

# Blur image
before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(1))
after.save("out.bmp")
```

```python
# Finds edges in an image

from PIL import Image, ImageFilter

# Find edges
before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out.bmp")
```

```python
# Find faces in picture
# https://github.com/ageitgey/face_recognition/blob/master/examples/find_faces_in_picture.py

from PIL import Image
import face_recognition

# Load the jpg file into a numpy array
image = face_recognition.load_image_file("office.jpg")

# Find all the faces in the image using the default HOG-based model.
# This method is fairly accurate, but not as accurate as the CNN model and not GPU accelerated.
# See also: find_faces_in_picture_cnn.py
face_locations = face_recognition.face_locations(image)

for face_location in face_locations:

    # Print the location of each face in this image
    top, right, bottom, left = face_location

    # You can access the actual face itself like this:
    face_image = image[top:bottom, left:right]
    pil_image = Image.fromarray(face_image)
    pil_image.show()
```

## Strings

The syntax regarding strings is a little different. Here we are using the CS50 library, just to illustrate that using lbiraries is possible.

```python
from cs50 import get_float, get_int, get_string
```

```python
# get_string and print, with format strings

from cs50 import get_string

answer = get_string("What's your name? ")
print(f"hello, {answer}")
```

## Variables

Python favors counter += 1 to increment by one, losing the ability found in C to type counter++.

## Data Types

Some data types in Python are:

> bool
>
> float
>
> int
>
> str

-----

> range
>
> list
>
> tuple
>
> dict
>
> set

## Calculator

An implementation of a simple calculator using **input()** and **int()**

```py
# Addition with int [using input]

# Prompt user for x
x = int(input("x: "))

# Prompt user for y
y = int(input("y: "))

# Perform addition
print(x + y)
```

Without converting x and y to be integers using **int()*, the characters will concatenate.

## Conditionals

```py
# Conditionals, Boolean expressions, relational operators

from cs50 import get_int

# Prompt user for integers
x = get_int("What's x? ")
y = get_int("What's y? ")

# Compare integers
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

-----

```py
# Logical operators

# Prompt user to agree
s = input("Do you agree? ")

# Check whether agreed
if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")
```

```py
# Logical operators, using lists

# Prompt user to agree
s = input("Do you agree? ")

# Check whether agreed
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")
```

## Object-Oriented Programming

Up until this point, our programs in this course have been linear: sequential.

It’s possible to have certain types of values not only have properties or attributes inside of them but have functions as well. In Python, these values are known as objects

In C, we could create a struct where you could associate multiple variables inside a single self-created data type. In Python, we can do this and also include functions in a self-created data type. When a function belongs to a specific object, it is known as a method.

```py
# Logical operators, using lists

# Prompt user to agree
s = input("Do you agree? ").lower()

# Check whether agreed
if s.lower() in ["y", "yes"]:
    print("Agreed.")
elif s.lower() in ["n", "no"]:
    print("Not agreed.")
```

s **.lower()** is a method of the object **str**

## Loops

### While Loop

While loop in C:

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}
```

While loop in Python:

```py
i = 0
while i < 3:
    print("meow")
    i += 1
```

-----

```py
while True:
    print("meow")
```

### For Loop

-----

For loop in C:

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
}
```

For loop in Python:

```py
for _ in range(3):
    print("meow")
```

The underscore is used to show that a variable is needed for the loop, but it will never be used.

### Uppercase

```py
before = input("Before: ")
print("After:  ", end="")
for c in before:
    print(c.upper(), end="")
print()
```

using a loop to uppercase and print 1 character at a time.

```py
before = input("Before: ")
print(f"After:  {before.upper()}")
```

This would be the smart way to do it.

## Abstraction

```py
def main():
    meow(3)


# Meow some number of times
def meow(n):
    for i in range(n):
        print("meow")


main()
```

You can define your own functions in Python, but if you define a main funcion, you have to call it att the end of your file.

It is convention that you create a main function.

## Truncation

```py
# Prompt user for x
x = int(input("x: "))

# Prompt user for y
y = int(input("y: "))

# Divide x by y
z = x / y
print(z)
```

Notice that executing this code results in a value, but that if you were to see more digits after .333333 you’d see that we are faced with floating-point imprecision. Truncation does not occur. The int will behave like a float.

**Integer overflow does not exist** in Python, the int size will grow with the int.

## Exceptions

A flawed implementations of a calculator:

```py
def get_int(prompt):
    return int(input(prompt))


def main():

    # Prompt user for x
    x = get_int("x: ")

    # Prompt user for y
    y = get_int("y: ")

    # Perform addition
    print(x + y)


main()
```

If you were to input something that is not an int this program will crash.

```py
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer")


def main():

    # Prompt user for x
    x = get_int("x: ")

    # Prompt user for y
    y = get_int("y: ")

    # Perform addition
    print(x + y)


main()
```

Using **try** and **except** to try and catch errors in a forever loop is one way to solve this.

In this case looking for a *ValueError*

## Mario

![Mario1](image.png)

This in code:

```py
from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0:
        break

for i in range(n):
    print("#")
```

-----

![Mario2](image-1.png)

```py
print("?" * 4)
```

-----

![Mario3](image-2.png)

```py
from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0:
        break

for i in range(n):
    print("#" * n)
```

## Lists

lists are a data structure within Python.

They can expand and shrink like a linked list, but they are included and does not need to be implemented in code.

lists have built in methods or functions within them.

```py
# Scores
scores = [72, 73, 33]

# Print average
average = sum(scores) / len(scores)
print(f"Average: {average}")
```

This is an example of the **sum** method.

```py
from cs50 import get_int

# Get scores
scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)

# Print average
average = sum(scores) / len(scores)
print(f"Average: {average}")
```

This uses the **.append()** method. Doing all of the mallocing and linking lists for you.

## Searching

```py
# A list of names
names = ["Carter", "David", "John"]

# Ask for name
name = input("Name: ")

# Search for name
for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not found")
```

Notice that a for loop can have an else statement aswell. If a for loop finishes it will go to the else statement and continue code as normal. but the break statement will skip any else statement if called.

```py
names = ["Carter", "David", "John"]

# Ask for name
name = input("Name: ")

# Search for name
if name in names:
    print("Found")
else:
    print("Not found")
```

This would be the *pythonic* way to implemet linear search.

## Dictionaries

```py
people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+1-617-495-1000"},
    {"name": "John", "number": "+1-949-468-2750"},
]

# Search for name
name = input("Name: ")

for person in people:
    if person["name"] == name:
        print(f"Found {person['number']}")
        break
else:
    print("Not found")
```

**people[]** is a **list** of **dictionaries**. Each dictionary having 2 entries with entries being a key-value pair.

A dictionary in Python lets you index in to it. Using the key to access the value. **person["name"]** will get you the value (name) associated with the **name** key.

-----

```py
people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John": "+1-949-468-2750",
}

name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")
```

If you dont need email and other things like would be possible in the previous approach, using just a dictionary instead of a list of dictionary is simpler.

## sys

```py
from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")
```

Using **sys** to access command line arguments

```py
import sys

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)
```

Using **sys** to exit program with exit codes.
