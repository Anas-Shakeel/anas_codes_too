from string import ascii_letters, punctuation, digits


def main():
    # Get the string from user
    string: str = input("Enter string: ")

    # Call matrix
    matrix(string)


def matrix(string: str):
    """ Matches a string Verbosely """
    # Characters used in the string
    CHARS: str = ascii_letters + digits + punctuation

    final: str = ""
    temp: str = ""
    length: int = len(string)

    for i in range(length):

        if string[i] == " ":
            final += string[i]
            continue

        # Iterate through CHARS
        for char in CHARS:
            temp = final
            temp += char
            if string.startswith(temp):
                final = temp
                print(final)
                break
            print(temp)


if __name__ == "__main__":
    main()
