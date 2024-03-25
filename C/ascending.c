// Ascending.c

/*
A Small program that prints a list of numbers (upto a range) in ascending order.

Things to consider:
- user input must be a positive integer (greater than 0)
- user input must be less than 1,000,000 (1 million!)
 */

#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    // Get the limit
    int limit = get_int("Range limit: ");
    if (limit < 1 || limit > 1000000)
    {
        printf("range limit '%i': must be an integer in between (1-1000000)\n", limit);
        return 1;
    }

    // Print the numbers upto the limit (in ascending order)
    for (int i = 1; i <= limit; i++)
    {
        printf("%i\n", i);
    }

    return 0;
}

/*
### Get Int
prompts user for an integer and returns it.
*/
int get_int(char *prompt)
{
    int i;
    printf(prompt);
    scanf("%i", &i);
    return i;
}