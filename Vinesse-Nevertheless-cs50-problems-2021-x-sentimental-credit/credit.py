#from cs50 import get_string
import string

evens = 0
odds = 0
subtotal = 0

# get input from user
strnum = input("Number: ")

# any input that doesn't meet length requirements
if(len(strnum) < 13 or len(strnum) > 16):
    print(f"INVALID")

# loop thru reversed string
# multiply every other number starting from the second to last number by 2
# if muliple is greater than 10, split number into its digits, ie 12 would be 1 and 2
# total all single digits
# Line 20 means for every element in strnum count backwards starting at the second to last char,
# down the length of strnum until you get to the first char.
for e in strnum[0:len(strnum):-2]:
    subtotal = int(e) * 2
    if(subtotal > 9):
        evens += subtotal // 10
        evens += subtotal % 10
    else:
        evens += subtotal

# loop through reversed string starting from the last number and stopping at 1
# total
subtotal = 0
for o in strnum[1:len(strnum):-1]:
    subtotal = int(o)
    odds += subtotal

# add totals together and check to see if card number meets other requirements
sum = evens + odds

if(sum % 10 == 0):

    if (strnum.startswith("34") or strnum.startswith("37") and len(strnum) == 15):
        print(f"AMEX")

    elif (strnum.startswith("51") or strnum.startswith("52") or strnum.startswith("53") or strnum.startswith("54") or strnum.startswith("55") and len(strnum) == 16):
        print(f"MASTERCARD")

    elif (strnum.startswith("4") and len(strnum) == 13 or len(strnum) == 16):
        print(f"VISA")

else:
    print(f"INVALID")