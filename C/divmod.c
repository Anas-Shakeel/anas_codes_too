#include <stdio.h>

// Custom structure to hold divmod values
typedef struct
{
    int quotient;
    int remainder;

} DIVMOD;

// Function prototype
int get_int(char *prompt);
DIVMOD divmod(int divisor, int dividend);

int main(void)
{
    // Get the values from the user
    int divisor = get_int("Enter divisor : ");
    int dividend = get_int("Enter dividend: ");

    // Calculate the divmod
    DIVMOD result = divmod(divisor, dividend); // DIVMOD

    printf("%i, %i\n", result.quotient, result.remainder);
    return 0;
}

int get_int(char *prompt)
{
    int temp;
    printf(prompt);
    scanf("%i", &temp);
    return temp;
}

DIVMOD divmod(int divisor, int dividend)
{
    // Construct a DIVMOD
    DIVMOD result;

    // Calculate the qoutient and remainder
    result.quotient = divisor / dividend;
    result.remainder = divisor % dividend;

    return result;
}

// Program to implement the divmod function from python