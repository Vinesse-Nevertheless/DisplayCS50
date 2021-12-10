#include <stdio.h>
#include <cs50.h>

//Prototype
void printPyramid(int n);
void indentLine(int s);
void buildPyramid(int i);

int main(void)
{
    int num = get_int("Height: ");
    printPyramid(num);
}

//uses request number to call methods for indenting rows and making hashes
void printPyramid(int n)
{
    //if/else restricts height to 1 - 8 hashes
    if (n > 0 && n < 9)
    {
        for (int i = 1; i <= n; i++)
        {
            indentLine(n - i); 
            buildPyramid(i);
        }
    }
    else
    {
        main();
    }
}

//Indents hashes to give pyramid shape
void indentLine(int indent)
{
    for (int i = 0; i < indent; i++)
    {
        printf(" ");
    }
}


void buildPyramid(int i)
{
    //makes # of columns in pyramid
    for (int j = 0; j < 2; j++)
    {
        //makes # of rows in pyramid
        for (int h = 0; h < i; h++)
        {
            printf("#");
        }
        
        //spacing between halves of pyramid
        if (j == 0)
        {
            printf("  ");
        }
    }
    printf("\n");
}
