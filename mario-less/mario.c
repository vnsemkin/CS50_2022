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
        //Count to print hash
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}