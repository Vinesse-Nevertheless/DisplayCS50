from cs50 import get_string
from cs50 import get_int
import string

# This program calculate the reading level based on the Coleman-Liau Index.


def main():
    # Ask user for text and call calculation and print methods
    passage = get_string("Text: ")
    nLetters = letterCount(passage)
    nWords = wordCount(passage)
    nSentences = sentenceCount(passage)
    index = Coleman_Liau_calculator(nLetters, nWords, nSentences)
    printIndex(index)


# calculate the passage's letter count without spaces
def letterCount(passage):
    c = 0
    for let in passage:
        if let.isalpha():
            c += 1

    return c


# calculate the passage's word count based on the number of spaces between words + 1
def wordCount(passage):
    c = 1
    
    for space in passage:
        if space.isspace():
            c += 1

    return c


# calculate the number of sentences in passage by counting end sentence punctuation marks.
def sentenceCount(passage):
    c = 0
    punc = ['.', '?', '!']
    for p in passage:
        for i in punc:
            if p == i:
                c += 1

    return c


# calculate the reading level index used the Coleman-Liau formula with the assumption that all arguments are greater than 0
def Coleman_Liau_calculator(nLetters, nWords, nSentences):
    L = nLetters / nWords * 100
    S = nSentences / nWords * 100

    index = (0.0588 * L) - (0.296 * S) - 15.8
    roundedIndex = round(index)

    return roundedIndex

# Print the index based on the stipulated specifications


def printIndex(index):
    highLevel = "Grade 16+"
    lowLevel = "Before Grade 1"

    if index >= 16:
        print(highLevel)
    elif index <= 1:
        print(lowLevel)
    else:
        print("Grade " + str(index))


if __name__ == "__main__":
    main()