# Vinesse-Nevertheless Python CS 50

## Mario (more comfortable version)

Implement a program that prints out a double half-pyramid of a specified height, per the below.

$ python mario.py

Height: 4

<img width="141" alt="Screen Shot 2021-12-14 at 11 01 45 AM" src="https://user-images.githubusercontent.com/88684757/146057694-3a80bb78-70a4-4358-87a7-e5279b7a0843.png">

## Specification
Write, in a file called mario.py in ~/pset6/mario/more/, a program that recreates these half-pyramids using hashes (#) for blocks, exactly as you did in Problem Set 1, except that your program this time should be written in Python.

To make things more interesting, first prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive. (The height of the half-pyramids pictured above happens to be 4, the width of each half-pyramid 4, with a gap of size 2 separating them).

If the user fails to provide a positive integer no greater than 8, you should re-prompt for the same again.
Then, generate (with the help of print and one or more loops) the desired half-pyramids.

Take care to align the bottom-left corner of your pyramid with the left-hand edge of your terminal window, and ensure that there are two spaces between the two pyramids, and that there are no additional spaces after the last set of hashes on each row.

## Usage
Your program should behave per the example below.

$ python mario.py

Height: 4

<img width="141" alt="Screen Shot 2021-12-14 at 11 01 45 AM" src="https://user-images.githubusercontent.com/88684757/146057694-3a80bb78-70a4-4358-87a7-e5279b7a0843.png">

