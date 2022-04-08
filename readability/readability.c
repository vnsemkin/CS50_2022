#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

//Initilize function
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float index_count(float var_count_letters, float var_count_words, float var_count_sentences);

int main(void)
{
    //Gettng string from user
    string text = get_string("Text:");
    //Count letters
    int var_count_letters = count_letters(text);
    //Count words
    int var_count_words = count_words(text);
    //Count sentences
    int var_count_sentences = count_sentences(text);
    float var_index1 = index_count(var_count_letters, var_count_words, var_count_sentences);
    int var_index = round(var_index1);

    if (var_index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (var_index >= 1 && var_index <= 16)
    {
        printf("Grade %i\n", var_index);
    }
    if (var_index > 16)
    {
        printf("Grade 16+\n");
    }
}
//Count letters
int count_letters(string text)
{
    int x = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = toupper(text[i]);
        if (text[i] != '\0' && text[i] >= 'A' && text[i] <= 'Z')
        {
            x++;
        }
    }
    return x;
}
//Count words
int count_words(string text)
{
    int x = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = toupper(text[i]);
        if (text[i] == ' ')
        {
            x++;
        }
    }
    return x;
}
//Count sentences
int count_sentences(string text)
{
    int y = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //text[i] = toupper(text[i]);
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            y++;
        }
    }
    return y;
}
float index_count(float var_count_letters, float var_count_words, float var_count_sentences)
{
    float l = (var_count_letters / var_count_words) * 100;
    float s = (var_count_sentences / var_count_words) * 100;
    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    return index;
}





