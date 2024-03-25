#include <stdio.h>

int get_int(char *prompt);
void swap(int *a, int *b);

int main(void)
{
    // Get the values from user
    int a = get_int("Enter a: ");
    int b = get_int("Enter b: ");

    printf("Before: a=%i, b=%i\n", a, b);

    // Swap the values
    swap(&a, &b);

    printf("After: a=%i, b=%i\n", a, b);
    return 0;
}

// Get integer from user
int get_int(char *prompt)
{
    int temp;
    printf(prompt);
    scanf("%i", &temp);
    return temp;
}

// Swap two (int) variables
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swap variables

/*
What is this program?
This program implements a function called 'swap',
that takes address of 2 variables and swaps their values

Example:
>> int a = 10;
>> int b = 20;
>> printf("before: a=%i, b=%i\n", a, b);
>> swap(&a, &b); //passing addresses of variables
>> printf("after: a=%i, b=%i\n", a, b);
Output:
before: a=10, b=20
after: a=20, b=10

Why?
doing so, we learn about pointers and how to pass addresses of variables
to functions, and manipulate their values.
*/
