#include <stdio.h>

float average(int array[], int length);

int main(void)
{
    // Array of integers
    int arr[] = {1, 2, 3, 4, 5, 50, 100};
    int len = (int)(sizeof(arr) / sizeof(int));

    // Calculate the average
    float avg = average(arr, len);

    printf("Average: %.02f\n", avg);
    return 0;
}

float average(int array[], int length)
{
    // Sum all integers
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    // Calculate & return the average
    return (sum / (float)length);
}

// Average of array
/*
Program to find the average of all integers in an array
 */