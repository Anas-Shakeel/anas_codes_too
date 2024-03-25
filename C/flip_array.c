#include <stdio.h>

void flip(int array[], int len);

int main(void)
{
    // Array to flip
    int arr[] = {1, 2, 3, 4, 5};

    // Length of the array
    int len = (int)(sizeof(arr) / sizeof(int));

    // Flip the array
    flip(arr, len); // pass the array, and its length

    return 0;
}

// Flip the array horizontally
void flip(int array[], int len)
{
    // Will hold values temporarily
    int temp;

    // Iterate upto mid of array
    for (int i = 0; i < len / 2; i++)
    {
        // Store the current element in temp
        temp = array[i];
        // Swap the current element with mirror one
        array[i] = array[len - 1 - i];
        // Swap the mirror element with temp
        array[len - 1 - i] = temp;
    }
}

// Flip an array (horizontally)
/*
What does this program do?
This programs flips an array horizontally.
for example, the array {1, 2, 3, 4, 5} will be flipped like:
                 array {5, 4, 3, 2, 1}.


How?
array = {1, 2, 3, 4, 5}
len = 5
5 / 2 == 2.5 > 2
n = 2
Repeat for n/2 times:
    swap array[i] with the last element array[len - i]
    swap array[len-i] with the array[i]

*/