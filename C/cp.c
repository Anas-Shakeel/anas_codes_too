#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Get the filenames from command line arguments
    if (argc != 3)
    {
        printf("USAGE: .\\cp.exe src dst\n");
        return 1;
    }
    char *src_filename = argv[1];
    char *dst_filename = argv[2];

    // Open the (source) and (destination) file
    FILE *src = fopen(src_filename, "r");
    FILE *dst = fopen(dst_filename, "w");

    // Read the bytes from src and write them to dst file
    BYTE b;
    while (fread(&b, sizeof(BYTE), 1, src))
    {
        fwrite(&b, sizeof(BYTE), 1, dst);
    }

    // Close the files
    fclose(src);
    fclose(dst);

    return 0;
}

// CP.c
/*
This linux command CP which copies a file to another location.
This program implements the same idea
 */