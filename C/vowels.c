// Vowels.c

/*
A Small program that takes in a character from user and tells
whether the char is vowel or not.

Things to consider:
- input char must be an alphabet
- input char must be a single character
- must be case-insenstive (Uppercase & lowercase should
                             affect the behaviour of program)

*/

#include <stdio.h>
#include <ctype.h>

char get_char(char *prompt);
int is_vowel(char c);

int main(void)
{
    // Get the char from user
    char c = get_char("Enter an alphabet: ");
    if (!isalpha(c))
    {
        printf("input '%c': expected an alphabetic character.\n", c);
        return 1;
    }

    if (is_vowel(c))
    {
        printf("Is vowel.\n");
    }
    else
    {
        printf("Not vowel.\n");
    }

    return 0;
}

char get_char(char *prompt)
{
    char c;
    printf(prompt);
    scanf("%c", &c);
    return c;
}

int is_vowel(char c)
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    // Check if c is vowel, (1 is yes), (0 is no).
    for (int i = 0; i < 5; i++)
    {
        if (c == vowels[i] || c == (vowels[i] - 32))
        {
            return 1; // vowel
        }
    }
    return 0;
}