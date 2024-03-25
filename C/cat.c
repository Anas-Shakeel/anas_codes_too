#include <stdint.h>
#include <stdio.h>

// Custom datatype `BYTE` (one byte storage)
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Get the Filename from command-line arguments
    if (argc != 2)
    {
        printf("Command-line error: Invalid filename.\n");
        return 1;
    }
    char *filename = argv[1];

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File can't be opened.");
        return 1;
    }

    // Read the file byte-by-byte and print on screen
    BYTE b;
    while (fread(&b, sizeof(BYTE), 1, file))
    {
        printf("%c", b);
    }

    return 0;
}

// Cat.c
/*
Program to replicate the linux cat command which takes as argument a text file
and prints every character on screen.
 */