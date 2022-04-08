#include <cs50.h>
#include <stdio.h>

//initilize function
long long get_card_number();
int card_lenght();
int card_validation();
void card_issue();
//main function
int main(void)
{
    //Ask user to input card number
    long long card_number = get_card_number();

    //Determine lenght of card
    int lenght_of_number = card_lenght(card_number);

    //Determine if card is valid
    int valid = card_validation(card_number);
    //Determine what kind of card is?
    card_issue(card_number, valid, lenght_of_number);
}
//Get number of card
long long get_card_number()
{
    long long card_number;
    do
    {
        card_number = get_long("Input your credit number:");
    }
    while (card_number < 0);
    return card_number;
}
//Looking for card lenght
int card_lenght(long long card_number)
{
    //Find lenght of card number and check
    int lenght_of_number = 0;
    long long i = card_number;
    while (i > 0)
    {
        i = i / 10;
        lenght_of_number++;
    }
    return lenght_of_number;
}
//Validate card using Luhn`s Algoritm
int card_validation(long long card_number)
{
    int even_sum = 0;
    int odd_sum = 0;
    int i;
    int odd_sum_raw = 0;
    int odd_sum_split = 0;
    for (i = 0; card_number != 0; i++, card_number /= 10)
    {
        if (i % 2 == 0)
        {
            even_sum = even_sum + (card_number % 10);
        }
        else
        {
            odd_sum_raw = ((card_number % 10) * 2);
            odd_sum_split = (odd_sum_raw / 10) + (odd_sum_raw % 10);
            odd_sum = odd_sum + odd_sum_split;
        }
    }
    int sum = odd_sum + even_sum;
    int valid = (sum % 10);
    return valid;
}
//Whait card is it?
void card_issue(long long card_number, int valid, int lenght_of_number)
{
    if ((valid == 0) && (lenght_of_number == 13 || lenght_of_number == 15 || lenght_of_number == 16))
    {
        if ((card_number >= 34e13 && card_number < 35e13) || (card_number >= 37e13 && card_number < 38e13))
        {
            printf("AMEX\n");
        }
        else if (card_number >= 51e14 && card_number < 56e14)
        {
            printf("MASTERCARD\n");
        }
        else if ((card_number >= 4e12 && card_number < 5e12) || (card_number >= 4e15 && card_number < 5e15))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}