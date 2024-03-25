#include <stdio.h>

int min(int array[], int len);
int max(int array[], int len);

int main(void)
{
    // Array initialization
    int arr[] = {11, 2, 5, 11, 17, 4, 10};

    // Find the minimum value
    int minimum = min(arr, 7);
    // Find the maximum value
    int maximum = max(arr, 7);

    // Print the returned maximum value
    printf("Minimum: %i\n", minimum);
    printf("Maximum: %i\n", maximum);
    return 0;
}

// Return the minimum from an array
int min(int array[], int len)
{
    // Ints can store upto 2 billion
    int min = 2147483647;

    for (int i = 0; i < len; i++)
    {
        if (array[i] < min)
        {
            // Set min to array[i]
            min = array[i];
        }
    }
    return min;
}

// Return the maximum from an array
int max(int array[], int len)
{
    int max = 0;

    for (int i = 0; i < len; i++)
    {
        if (array[i] > max)
        {
            // Set max to array[i]
            max = array[i];
        }
    }
    return max;
}

// Minimum/Maximum of an array
/*
Find the minimum or maximum value from an array
of integers of length 'n'
*/