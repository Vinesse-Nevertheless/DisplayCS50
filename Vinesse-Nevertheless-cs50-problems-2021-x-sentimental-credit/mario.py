from cs50 import get_int

# prompt user for height repeatedly until they enter value from 1 - 8
height = -1

while (height < 1 or height > 8):
    height = get_int("Height: ")


# build doubled sided pyramid
# line 19 indents
# line 21 prints hash blocks on left side
# line 23 puts space between blocks
# line 24 prints hash blocks on right side
# print moves to new line and counters make indent and block count adjustments

c = 1
for i in range(height):
    for h in range(height - 1):
        print(" ", end="")
    for j in range(c):
        print("#", end="")
    print("  ", end="")
    for k in range(c):
        print("#", end="")
    print()
    c += 1
    height -= 1