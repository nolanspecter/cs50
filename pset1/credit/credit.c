#include <stdio.h>
#include <cs50.h>

int get_length(long a)
{
    int length = 0;
    while (a > 0)
    {
        a /= 10;
        length ++;
    }
    return length;
}

int main(void)
{
    long number = get_long("Number: ");
    int check;
    long start = number;
    int sum1 = 0;
    int sum2 = 0;
    int mod1;
    int mod2;
    int digit1; // For number that has 2 digits after times 2
    int digit2;

    int length = get_length(number);

    // Length validation
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Extract each digits of the credit card numbers
    do
    {
        mod1 = number % 10;
        number = number / 10;
        sum1 += mod1;

        mod2 = (number % 10) * 2;
        number = number / 10;
        digit1 = mod2 % 10;
        digit2 = mod2 / 10;
        sum2 = sum2 + digit1 + digit2;
    }
    while (number > 0);

    check = sum1 + sum2;

    // Validate check sum
    if (check % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Get first 2 digits and validate card type
    do
    {
        start /= 10;
    }
    while (start > 100);

    if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}