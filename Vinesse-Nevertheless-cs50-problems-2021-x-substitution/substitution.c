#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//Prototypes
int validateKey(int len, string key);
string getMessage(void);
void encipherAndPrint(string message, string key);


int main(int argc, string argv[])
{
    string key = argv[1];
    int error = validateKey(argc, key);

    //Program continues only if validation succeeds
    if (error == 0)
    {
        string message = getMessage();
        encipherAndPrint(message, key);
    }
    else
    {
        return error;
    }
}

//validate key
int validateKey(int arrayLen, string key)
{
    //validate if there is only the program name and no arguments
    if (arrayLen == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    int const KEYLEN = strlen(key);
    
    //validate if contains digit. Must use double loops to access the characters in the array
    for (int k = 0; k < KEYLEN ; k++)
    {
        if (!isalpha(key[k]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    //validate if there are 26 letters in key
    if (KEYLEN != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

//validate if there are duplicate letters
//Added loop m to compare a letter to every other letter that comes after it in the array.

    for (int k = 0; k < KEYLEN; k++)
    {
        for (int m = k + 1; m < KEYLEN; m++)
        {
            if (tolower(key[k]) == tolower(key[m]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

//return 0 if none of the above errors were found
    return 0;
}

//get message from user
string getMessage(void)
{
    string mess = get_string("plaintext: ");
    return mess;
}

//encipher message by taking each letter in the message, finding it's position in the regular alphabet and then
//using that position to look up the right char in the key
void encipherAndPrint(string message, string key)
{
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    printf("ciphertext: ");
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        if (!isalpha(message[i]))
        {
            printf("%c", message[i]);
        }
        else
        {
            for (int j = 0, m = strlen(alpha); j < m ; j++)
            {
                if (message[i] == alpha[j])
                {
                    printf("%c", tolower(key[j]));
                }
                else if (message[i] == toupper(alpha[j]))
                {
                    printf("%c", toupper(key[j]));
                }
            }
        }
    }
    printf("\n");
}