#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int rotate(string text, int key);

int main(int argc, string argv[])
{
//Get the key and remind user to input right key using only number;
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    //Check the argument is digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }
    if (atoi(argv[1]) >= 0 && atoi(argv[1]) <= 99)
    {
        int key = atoi(argv[1]);
        //Ask user to type massage
        string text = get_string("plaintext:");
        printf("ciphertext: ");
        //Call function to cipther message
        rotate(text, key);
    }
    else
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
}
//Doing iteration for reversing string.
int rotate(string text, int key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Check if letter is UPPERCASE
        if (text[i] != '\0' && text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", (((text[i] - 65) + key) % 26) + 65);
        }
        //Check if letter is lowercase
        else if (text[i] != '\0' && text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%c", (((text[i] - 97) + key) % 26) + 97);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 1;
}
























