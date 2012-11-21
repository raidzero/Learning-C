#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    char s[512];
    printf("Please enter a string: ");
    fgets(s, 512, stdin);

    int sLen = strlen(s);
    int key = atoi(argv[1]);
    int overrun = 0;

    for (int i = 0; i < sLen; i++)
    {
        char letter = s[i];

        if (isalpha(letter))
        {
            if (isupper(letter))
            {
                if (letter + key > 'Z')
                {
                    printf("%c", 'A' + (letter + key) % 'Z' - 1);
                }
                else // we didnt overrun
                {
                    printf("%c", letter + key);
                }
            }
            else if (islower(letter))
            {
                if (letter + key > 'z')
                {
                    printf("%c", 'a' + (letter + key) % 'z' - 1);
                }
                else // we didnt overrun
                {
                    printf("%c", letter + key);
                }
            }
        }
        if (!isalpha(letter))
        {
            printf("%c", letter);
        }
    }

    return 0;
}
