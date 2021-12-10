#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//This program calculate the reading level based on the Coleman-Liau Index.

//Prototypes
int letterCount(string passage);
int wordCount(string passage);
int sentenceCount(string passage);
int Coleman_Liau_calculator(int nLetters, int nWords, int nSentences);
void printIndex(int index);

//constants used for punctuation array
int const TOTAL = 3;

int main(void)
{
    //Ask user for text and call calculation and print methods
    string passage = get_string("Text: ");
    int nLetters = letterCount(passage);
    int nWords = wordCount(passage);
    int nSentences = sentenceCount(passage);
    int index = Coleman_Liau_calculator(nLetters, nWords, nSentences);
    printIndex(index);
}

//calculate the passage's letter count without spaces
int letterCount(string passage)
{
    int c = 0;
    for (int i = 0, n = strlen(passage); i < n; i++)
    {
        if ( isalpha(passage[i]) ){
            c++;
        }
    }
    return c;
}

//calculate the passage's word count based on the number of spaces between words + 1
int wordCount(string passage)
{
    int c = 1;
    for (int i = 0, n = strlen(passage); i < n; i++)
    {
        if ( isspace(passage[i]) )
        {
            c++;
        }
    }
    return c;
}

//calculate the number of sentences in passage by counting end sentence punctuation marks.
int sentenceCount(string passage)
{
    int c = 0;
    char punc[TOTAL];
    punc[0] = '.';
    punc[1] = '?';
    punc[2] = '!';

    for (int i = 0, n = strlen(passage); i < n; i++)
    {
        for (int j = 0; j < TOTAL; j++)
        {
            if ( passage[i] == punc[j] )
            {
                c++;
            }
        }
    }
    return c;
}

//calculate the reading level index used the Coleman-Liau formula with the assumption that all arguments are greater than 0
int Coleman_Liau_calculator(int nLetters, int nWords, int nSentences)
{
    float L = (float) nLetters / nWords * 100;
    float S = (float) nSentences / nWords * 100;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int roundedIndex = round(index);
    return roundedIndex;
}

//Print the index based on the stipulated specifications
void printIndex(int index)
{
    string highLevel = "Grade 16+";
    string lowLevel = "Before Grade 1";
    
    if (index >= 16)
    {
        printf("%s\n", highLevel);
    }
    else if (index <= 1)
    {
        printf("%s\n", lowLevel);
    }
    else
    {
        printf("Grade %i\n", index);
    }
}