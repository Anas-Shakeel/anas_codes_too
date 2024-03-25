#include <stdio.h>

long sum(int arr[], int length);
long multiply(int arr[], int length);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    // Calculate the sum & multiplication
    long sum_result = sum(arr, 8);
    long mult_result = multiply(arr, 8);

    printf("Sum: %li, Multiply: %li\n", sum_result, mult_result);
    return 0;
}

long sum(int arr[], int length)
{
    long sum = 0;

    // Iterate through the array and calculate their sum
    for (int i = 0; i < length; i++)
    {
        // Add current integer into sum
        sum += arr[i];
    }

    return sum;
}

long multiply(int arr[], int length)
{
    long result = arr[0];

    // Iterate through the array and multiply with result
    for (int i = 1; i < length; i++)
    {
        // Multiply current integer with result
        result *= arr[i];
    }

    return result;
}

// Sum of array
/*
Program to find the sum of all integers in an array
*/