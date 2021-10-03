#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int start_size;
    int end_size;
    int year = 0;
    int size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);
    size = start_size;

    while (size < end_size)
    {
        size = size + size / 3 - size / 4;
        year ++;
    }

    printf("Years: %i\n", year);
}