#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
int encrypt(char letter, int key);
int decrypt(char letter, int key);

int main(int argc, char *argv[])
{
    // Get the command-line arguments
    if (argc != 4)
    {
        printf("USAGE: ./caesar [mode] [text] [key]");
        return 1;
    }
    char *mode = argv[1];
    char *text = argv[2];
    int key = atoi(argv[3]);

    // Length of the text
    int length = strlen(text);
    char letter; // Holds encrypted/decrypted letter

    for (int i = 0; i < length; i++)
    {
        if (strcmp(mode, "-e") == 0)
        {
            // Encrypt the letter and print
            letter = encrypt(text[i], key);
        }
        else if (strcmp(mode, "-d") == 0)
        {
            // Decrypt the letter and print
            letter = decrypt(text[i], key);
        }
        else
        {
            printf("Invalid mode.");
            return 1;
        }
        printf("%c", letter);
    }

    printf("\n");

    return 0;
}

int encrypt(char letter, int key)
{
    // Will hold the resulting value to return
    int result;

    // If not alphabetic, return the same
    if (!isalpha(letter))
    {
        return letter;
    }

    // Store as ascii value
    result = letter;

    if (isupper(letter))
    {
        // Char is uppercase
        result -= 65;
        result = ((result + key) % 26) + 65;
    }
    else
    {
        // Char is lowercase
        result -= 97;
        result = ((result + key) % 26) + 97;
    }

    return result;
}

int decrypt(char letter, int key)
{
    // Will hold the resulting value to return
    int result;

    // If not alphabetic, return the same
    if (!isalpha(letter))
    {
        return letter;
    }

    // Store as ascii value
    result = letter;

    if (isupper(letter))
    {
        // Char is uppercase
        result -= 65;
        result = ((result - key + 26 * 1000) % 26);
        result += 65;
    }
    else
    {
        // Char is lowercase
        result -= 97;
        result = ((result - key + 26 * 1000) % 26);
        result += 97;
    }

    return result;
}

/*
Implements the caesar cipher.


What is Caesar's Cipher?
Caesar cipher is an encryption method used by Julius Caesar to
encrypt information and messages.

How does it work?
Caesar's cipher works by rotating the letters by a key.

* How to encrypt?
? What do we need?
    a string to be encrypted
    a key integer (to rotate the letters)

? Method?
    to encrypt a string e.g "abc" with key=3

    we we'll need to shift every letter by 3 places
        So,
        `a` becomes `d`
        `b` becomes `e`
        `c` becomes `f`

? How to Ecnrypt : PSEUDO CODE?
    For every char in plaintext
        if char is uppercase:
            get the char's ascii value
            subtract 65 from it to make it zero indexed
            add key to it and mod it to be in the range
            add back the 65
            convert to char and concatenate to `ciphertext` string

        else if lowercase:
            get the char's ascii value
            subtract 97 from it to make it zero indexed
            add key to it and mod it to be in the range
            add back the 97
            convert to char and concatenate to `ciphertext` string

        else if char is not alphabet:
            concatenate into `ciphertext` string without shifting

    return the ciphertext


? Considerations?
    while shifting the letters, we need to take into consideration that
    if we shift letters more than the available alphabets, we'll get an error.
    Example:
        if we encrypt `xyz` by 3 places
            `x` becomes ! Error

            Because 3 places ahead of x is nothing!

        That's why we have to wrap the letters to avoid this type of error

        By wrapping:
            `x` becomes `a`
            `y` becomes `b`
            `z` becomes `c`


* How to decrypt?
? What do we need?
    to decrypt a ciphertext encrypted using Caesar cipher,
        We need the ciphertext
        and the key which was used to decrypt the ciphertext

? Method ?
    To decrypt a ciphertext e.g "def" with key=3,

    We'll need to shift down the alphabets by 3 places (making sure it wraps around)
    So,
        `d` becomes `a`
        `e` becomes `b`
        `f` becomes `c`


* Program Outline
Program should implement two methods `encrypt()` and `decrypt()`
Both take a string and a key as arguments.
    One of them encrypts the key
    The other decrypt the key

Example:
? execution syntax
>> ./caesar.exe [mode] [text] [key]

>> .caesar.exe -e "abc" 3
'def'

>> .caesar.exe -d "def" 3
'abc'


* Consideration:
Lowercase and uppercase letters should output upper and lowercase.
Only rotate the alphabets (not digit, symbols etc)

*/