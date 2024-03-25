// Even or Odd

/*
A small program that takes a positive integer ands prints "EVEN" if
it is even, "ODD" otherwise.
 */

#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    // Get the number
    int number = get_int("Enter a positive number: ");
    if (number < 0 || number > 9999999999)
    {
        printf("number must be in range (0 to 9999999999)\n");
        return 1;
    }

    // Check Even/Odd
    if (number % 2 == 0)
    {
        printf("Even.\n");
    }
    else
    {
        printf("Odd.\n");
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
