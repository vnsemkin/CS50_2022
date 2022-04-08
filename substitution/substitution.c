#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //1.Check that we have 1 arguments and lenght of key is 26;
    if (argc != 2)
    {
        printf("Provide valid key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Provide valid key\n");
        return 1;
    }
    //2.Check the key is only alphabets
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Provide valid key\n");
            return 1;
        }
    }
    //3.Making 3 arrays: array_key_upper to compare with  array_uppercase and original key;
    int array_key_origin[26];//Array origin key from user;
    int array_key_upper[26];//Array origin key in uppercase;
    int array_key_lower[26];
    int array_uppercase[26];//Array from A to Z;
    int array_lowercase[26];
    int array_spec_simbols[26];
    for (int i = 0; i <= 25; i++)
    {
        {
            array_key_origin[i] = argv[1][i];
            array_key_upper[i] = toupper(argv[1][i]);
            array_key_lower[i] = tolower(argv[1][i]);
            array_uppercase[i] = i + 65;
            array_lowercase[i] = i + 97;
            array_spec_simbols[i] = i + 32;
        }
    }
    //Check the word is not twic in text;
    for (int y = 0; y <= 25; y++)
    {
        int x = 0;
        for (int z = 0; z <= 25; z++)
        {
            if (array_uppercase[y] == array_key_upper[z])
            {
                x++;
            }
        }
        if (x > 1)
        {
            printf("x= %i\n", x);
            printf("Provide valid key\n");
            return 1;
        }
    }
    //Input users text;
    string text = get_string("plaintext:");
    printf("ciphertext:");
    //Cipher text using key;
    for (int y = 0; y < strlen(text); y++)
    {
        for (int z = 0; z <= 25; z++)
        {
            if (text[y] == array_uppercase[z])
            {
                printf("%c", array_key_upper[z]);
            }
            else if (text[y] == array_lowercase[z])
            {
                printf("%c", array_key_lower[z]);
            }
            else if (text[y] == array_spec_simbols[z])
            {
                printf("%c", text[y]);
            }
        }
    }
    printf("\n");
    return 0;
}
