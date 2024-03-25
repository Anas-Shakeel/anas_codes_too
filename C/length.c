#include <stdio.h>

int main(void)
{
    // Array initialization
    int arr[] = {0, 1, 2, 3, 4};

    // Size of array(in-bytes) / Size of its datatype
    int length = (int)(sizeof(arr) / sizeof(int));

    // Print the length
    printf("Length: %i\n", length);
    return 0;
}

// Length of an array
/*
Find the length of an array

How?
Things to consider:
    - 'sizeof' function returns the size of an object in bytes
    - arrays contain the values of same datatype
    - all elements in an array have the same size (no matter the value)

Formula to find the array length:
    "size of array / size of its datatype"
    >> int len = sizeof(array) / sizeof(int);

How does it work?
    Let's take an array:
        int array = {1, 2, 3, 4, 5}

    the datatype of the array is int
    and ints are of 4 bytes in C

    "sizeof(array)" will return the size of the whole array in bytes
    Which is 20.
        because there are 5 elements in the array, each with a size of 4 bytes.
            4 * 5 = 20 bytes

    "sizeof(int)" will return 4, because ints are of 4-bytes

    So dividing 20 with 4 will give us the length of an array.
        20 / 4 == 5

    len = 5

*/