// Sum Of Odds
/*
A small program that takes a limit integer and prints the sums of all
odd numbers upto that limit.

Things to consider:
- limit must be greater than 0
- limit must be less than 50,000 (50 thousand)

*/

#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    // Get limit from user
    int limit = get_int("Limit: ");

    if (limit < 1 || limit > 50000)
    {
        printf("limit '%i': must be an integer between (1-50,000)", limit);
        return 1;
    }

    // store limit
    int i = limit;
    if (limit % 2 != 0) // if not even
    {
        i++; // make it even
    }

    // Formula to get the sum of an arithmetic series
    int sum = (i / 2) * (i / 2);

    printf("Sum of all odds (upto %i): %i\n", limit, sum);
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
