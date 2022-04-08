#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score(string word1);
int score(string word2);
int compute_score1(string word1);
int compute_score2(string word2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score1(word1);
    printf("Score1: %i\n", score1);
    // int count_score(string word1);
    int score2 = compute_score2(word2);
    printf("Score2: %i\n", score2);


    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score1(string word1)
{
//find the lenght of input string
    int n = 0;
    while (word1[n] != '\0')
    {
        n++;
    }
    //Doing Uppercase
    for (int i = 0; i < n; i++)
    {
        if (word1[i] >= 'a' && word1[i] <= 'z')
        {
            word1[i] = word1[i] - 32;
        }
    }
    //Doing coint
    int score1 = 0;
    int j;
    for (int i = 0; i < 26; i ++)
    {
        for (j = 0; j <= n; j++)
        {
            if (word1[j] >= 65 && word1[j] <= 90)
            {
                score1 = score1 + POINTS[i];
            }
        }
    }
    return score1;
}

int compute_score2(string word2)
{
    //find the lenght of input string
    int l = 0;
    while (word2[l] != '\0')
    {
        l++;
    }
    //Doing Uppercase
    for (int m = 0; m < l; m++)
    {
        if (word2[m] >= 'a' && word2[m] <= 'z')
        {
            word2[m] = word2[m] - 32;
        }
    }
    //Making count
    int score2 = 0;
    int i = 0;
    while (POINTS[i] != '\0')
    {
        if (word2[i] >= 65 && word2[i] <= 90)
        {
            for ()
        }

                {
                    score2 = score2 + POINTS[i];
                }

            }
        }
    }
    return score2;
}







