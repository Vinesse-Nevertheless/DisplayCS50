# Vinesse-Nevertheless. CS 50 Lab 8: Trivia

## Getting Started
Here’s how to download this lab into your own CS50 IDE. Log into CS50 IDE and then, in a terminal window, execute each of the below.

Execute cd to ensure that you’re in ~/ (i.e., your home directory, aka ~).

Execute wget https://cdn.cs50.net/2020/fall/labs/8/lab8.zip to download a (compressed) ZIP file with this problem’s distribution.

Execute unzip lab8.zip to uncompress that file.

Execute rm lab8.zip followed by yes or y to delete that ZIP file.

Execute ls. You should see a directory called lab8, which was inside of that ZIP file.

Execute cd lab8 to change into that directory.
E
xecute ls. You should see an index.html and a styles.css file.

## Implementation Details
Design a webpage using HTML, CSS, and JavaScript to let users answer trivia questions.

### In index.html, add beneath “Part 1” a multiple-choice trivia question of your choosing with HTML.
You should use an h3 heading for the text of your question.
You should have one button for each of the possible answer choices. There should be at least three answer choices, of which exactly one should be correct.
### Using JavaScript, add logic so that the buttons change colors when a user clicks on them.
If a user clicks on a button with an incorrect answer, the button should turn red and text should appear beneath the question that says “Incorrect”.
If a user clicks on a button with the correct answer, the button should turn green and text should appear beneath the question that says “Correct!”.
### In index.html, add beneath “Part 2” a text-based free response question of your choosing with HTML.
You should use an h3 heading for the text of your question.
You should use an input field to let the user type a response.
You should use a button to let the user confirm their answer.
### Using JavaScript, add logic so that the text field changes color when a user confirms their answer.
If the user types an incorrect answer and presses the confirmation button, the text field should turn red and text should appear beneath the question that says “Incorrect”.
If the user types the correct answer and presses the confirmation button, the input field should turn green and text should appear beneath the question that says “Correct!”.
Optionally, you may also:

### Edit styles.css to change the CSS of your webpage!
I personalized this assignment in the following ways:
     1. I added a hero header.
     2. I changed the title and the background colors.
     3. I also added a small acknowledgment sound that only occurs when you submit the correct answer to a question.  

