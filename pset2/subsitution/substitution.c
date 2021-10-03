#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_letter(string text);
bool check_unique(string text);
string sub(string text, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid argument!\n");
        return 1;

    }
    string key = argv[1];
    bool all_letters = check_letter(key);
    bool unique = check_unique(key);

    //Check for invalid inputs
    if (strlen(key) != 26)
    {
        printf("The key needs 26 letters!\n");
        return 1;
    }
    if (all_letters == false)
    {
        printf("The key can only take letters!\n");
        return 1;
    }
    if (unique == false)
    {
        printf("All characters in the key must be uniqe!\n");
        return 1;
    }

    string plain = get_string("plaintext: ");
    string cypher = sub(plain, key);
    printf("ciphertext: %s\n", cypher);
}

bool check_letter(string text)
{
    bool check = true;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) == 0)
        {
            check = false;
            break;
        }
    }
    return check;
}

bool check_unique(string text)
{
    bool check = true;
    for (int i = 1, n = strlen(text); i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (text[i] == text[j])
            {
                check = false;
                break;
            }
        }
    }
    return check;
}

string sub(string text, string key)
{
    int n = strlen(text);
    string cypher = text;
    for (int i = 0; i < n ; i++)
    {
        //If is upper get key index by substracting 65
        if (isupper(text[i]))
        {
            cypher[i] = toupper(key[text[i] - 65]);
        }
        //If is upper get key index by substracting 97
        if (islower(text[i]))
        {
            cypher[i] = tolower(key[text[i] - 97]);
        }
    }
    return cypher;
}