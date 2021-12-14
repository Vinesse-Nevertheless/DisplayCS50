# Vinesse-Nevertheless Python CS 50

## Credit
Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.

    $ python credit.py
    Number: 378282246310005
    AMEX
    
## Specification
<ul>
<li>In credit.py in ~/pset6/credit/, write a program that prompts the user for a credit card number and then reports (via print) whether it is a valid American Express, MasterCard, or Visa card number, exactly as you did in Problem Set 1, except that your program this time should be written in Python.</li>
<li>So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less.</li>
<li>For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card).</li>
<li>Best to use get_int or get_string from CS50’s library to get users’ input, depending on how you to decide to implement this one.</li>
</ul>

## Usage
Your program should behave per the example below.

    $ python credit.py
    Number: 378282246310005
    AMEX
    
## Testing
While check50 is available for this problem, you’re encouraged to first test your code on your own for each of the following.
<ul>
<li>Run your program as python credit.py, and wait for a prompt for input. Type in 378282246310005 and press enter. Your program should output AMEX.</li>
<li>Run your program as python credit.py, and wait for a prompt for input. Type in 371449635398431 and press enter. Your program should output AMEX.</li>
<li>Run your program as python credit.py, and wait for a prompt for input. Type in 5555555555554444 and press enter. Your program should output MASTERCARD.</li>
<li>Run your program as python credit.py, and wait for a prompt for input. Type in 5105105105105100 and press enter. Your program should output MASTERCARD.</li>
<li>Run your program as python credit.py, and wait for a prompt for input. Type in 4111111111111111 and press enter. Your program should output VISA.</li>
<li>Run your program as python credit.py, and wait for a prompt for input. Type in 4012888888881881 and press enter. Your program should output VISA.</li>
<li>Run your program as python credit.py, and wait for a prompt for input. Type in 1234567890 and press enter. Your program should output INVALID.</li>
</ul>  

Execute the below to evaluate the correctness of your code using check50. But be sure to compile and test it yourself as well!

check50 cs50/problems/2021/x/sentimental/credit

Execute the below to evaluate the style of your code using style50.

style50 credit.py

This problem will be graded only along the axes of correctness and style.

## How to Submit
Execute the below, logging in with your GitHub username and password when prompted. For security, you’ll see asterisks (*) instead of the actual characters in your password.

submit50 cs50/problems/2021/x/sentimental/credit
