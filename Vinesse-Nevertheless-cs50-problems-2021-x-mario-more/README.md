# Vinesse-Nevertheless edEX CS50 Class Mario (More Comfortable) Problem Set

Completed in 2021 for the CS50 course that I took while completing my IBM apprenticeship.

Mario
World 1-1
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

screenshot of Mario jumping over adjacent pyramids

Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller than they are wide.

<img width="141" alt="Screen Shot 2021-12-14 at 11 01 45 AM" src="https://user-images.githubusercontent.com/88684757/146034601-4791fbce-995f-40bb-9a70-ee35a10e5332.png">

The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:

$ ./mario
Height: 8

<img width="225" alt="Screen Shot 2021-12-14 at 11 01 55 AM" src="https://user-images.githubusercontent.com/88684757/146034649-95c0cdc3-660a-4f24-a69b-55969aaa2fab.png">

Here’s how the program might work if the user inputs 4 when prompted:

$ ./mario
Height: 4

<img width="141" alt="Screen Shot 2021-12-14 at 11 01 45 AM" src="https://user-images.githubusercontent.com/88684757/146034705-e9d30646-ab21-4a25-9734-d7d43ae7a28e.png">

Here’s how the program might work if the user inputs 2 when prompted:

$ ./mario
Height: 2

<img width="108" alt="Screen Shot 2021-12-14 at 11 02 15 AM" src="https://user-images.githubusercontent.com/88684757/146034736-b017de2b-28d6-4a21-bba1-2fbaf9b832d5.png">

And here’s how the program might work if the user inputs 1 when prompted:

$ ./mario
Height: 1

<img width="88" alt="Screen Shot 2021-12-14 at 11 02 23 AM" src="https://user-images.githubusercontent.com/88684757/146034803-4fbacda2-11dc-4fe8-8ce9-59121e1e06e9.png">


If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4

<img width="141" alt="Screen Shot 2021-12-14 at 11 01 45 AM" src="https://user-images.githubusercontent.com/88684757/146034845-66fd1e0c-4a33-4a99-9eca-18c84a08e5a3.png">

Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.
