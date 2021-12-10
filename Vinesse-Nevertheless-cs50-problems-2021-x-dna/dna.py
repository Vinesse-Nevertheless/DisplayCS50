from cs50 import get_int
from cs50 import get_string
import csv
import sys

# create empty dictionary
STR = {}


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    with open(sys.argv[1], "r") as file:
        populate_Dict(file)

    with open(sys.argv[2], "r") as DNAseq:
        DNAreader = csv.reader(DNAseq)
        find_consecutive_repeats(DNAreader)

    with open(sys.argv[1], newline="") as CSVfile:
        CSVreader = csv.DictReader(CSVfile)
        find_match(CSVreader)


def populate_Dict(file):
    # read .csv file and put rows in a list
    reader = csv.reader(file)
    hlist = []
    for row in reader:
        hlist.append(row)

    # the first item in the list is the first row, but you need to start at index 1 to skip over the "name" header
    header_list = hlist[0]
    heads = header_list[1::]

    # popoulate the dictionary using heads as the keys and assigning all the values to 0
    for h in heads:
        STR[h] = 0


def find_consecutive_repeats(DNAreader):
    # read the rows from the .txt file (there's only 1)
    # create a while loop limit.  Since the shortest sequence is 4 letters.  Divide by 4.
    # Example if there are 100 letters in the row, you can only have the combination AATG a maximum of 25 times.  100/4 = 25
    for row in DNAreader:
        DNA = row[0]
        limit = len(DNA) // 4

    # loop thru keys
    # keep making the key longer by adding to it.  Ex. AATG * 2 becomes AATGAATG.   AATG * 3 becomes AATGAATGAATG
    # keep track of the greatest size repetitve string
    # assign the greatest number as the value to the right dictionary key
        for s in STR.keys():
            c = 1
            greatest = 0
            while c < limit:
                if s*c in DNA:
                    greatest = c
                c += 1
            STR[s] = greatest


def find_match(CSVreader):
    limit = len(STR)
    match = False
    
    # loop thru rows
    # inside rows loop, loop through the length of the names
    # for every key in STR, if the value matches the value in the row, count it
    # if your occurrence reaches the size of the STR dictionary, then everyone occurrence matches, and you have a DNA match.
    # if you have a match, you can break out of the 2 loops
    # if you finish going through the rows and there are not matches, print no match
    for row in CSVreader:
        for i in range(len(row["name"])):
            occurrences = 0
            for key in STR:
                if str(STR[key]) in row[key]:
                    occurrences += 1
                else:
                    break
        if occurrences == limit:
            print(row["name"])
            match = True
            break
        if (match):
            break
    if(match == False):
        print("No match")


if __name__ == "__main__":
    main()