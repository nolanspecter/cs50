#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int index(float L, float S);

int main(void)
{
    string text = get_string("Text: ");
    float l = 0;
    float s = 0;
    int letter = 0;
    int word = 1;
    int sentence = 0;

    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        //Check for character
        if ((64 < text[i] && text[i] < 91) || (96 < text[i] && text[i] < 123))
        {
            letter++;
        }
        //Check for spaces.
        if (text[i] == 32)
        {
            word++;
        }
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence++;
        }
    }

    l = ((float) letter / word) *  100;
    s = ((float) sentence / word) *  100;

    int ind = index(l, s);

    if (ind < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (ind > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", ind);
    }
}

int index(float L, float S)
{
    float ind =  0.0588 * L - 0.296 * S - 15.8;
    return round(ind);
}