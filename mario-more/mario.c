#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Input height of pyramid: ");
    }
    while (h < 1 || h > 8);
    // Count for columns
    for (int i = 1; i < h + 1; i++)
    {
        // Count for print spaces
        for (int z = h; z > i; z--)
        {
            printf(" ");
        }
        //Count for print hash
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        //Count for print gaps
        for (int g = 1; g < 3; g++)
        {
            printf(" ");
        }
        //Count for print new pyramid
        for (int p = 0; p < i; p++)
        {
            printf("#");
        }
        printf("\n");
    }
}
