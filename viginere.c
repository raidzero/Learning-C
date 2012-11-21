/* viginere.c - implements viginere cipher */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char *keygen(char*, char*); // generates a key for the plaintext
char caesar(char, int); // shifts a character by a shift amount

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Must supply a key!\n");
        return 1;
    }

    char *oKey = argv[1];

    // check for any non alpha in rKey
    int n; 
    int kLen = strlen(oKey);
    for (n = 0 ; n < kLen; n++)
    {
        if (!isalpha(oKey[n]))
        {
            printf("Invalid character in key!\n");
            return 1;
        }
    }
    
    // grab plaintext from user (length up to 512 bytes)
    printf("Please enter plaintext: ");
    char p[512];
    fgets(p, 512, stdin);

    char* rKey = keygen(p, oKey);

    int i;
    int pLen = strlen(p);
    int shift;

    char *result = calloc(strlen(p) , sizeof(char));
    
    for (i=0; i<pLen; i++)
    {
        if (isalpha(p[i]))
        {
            // determine shift from rKey by subtracing the ascii value of the beginning of the alphabet
            if (isupper(rKey[i]))
            {
                shift = rKey[i] - 'A';
            }
            else
            {
                shift = rKey[i] - 'a';
            }
            char res = caesar(p[i], shift);
            //printf("shifting %c by %d: %c\n", p[i], shift, res);
            result[i] = res;
        }
        else
        {
            result[i] = p[i];
        }
    }

    printf("%s", p);
    //printf("%s\n", rKey);
    printf("%s", result);

    return 0;
}

char *keygen(char* p, char* oKey)
{
    char *rKey = calloc(strlen(p), sizeof(char)); // allocate enough memory to hold the repeated key

    int oKeyLen = strlen(oKey);
    int pLen = strlen(p);

    int i = 0;
    int j = 0;
    int pos = 0;

    while (i<pLen)
    {
        if (!isalpha(p[i]))
            rKey[i] = ' '; // space in rKey at i if not a letter   
        else
        {
            if (i > 0)
                 pos = j % oKeyLen; // determine which part of okey to use based on a position irrespective of spaces in p
            if (isupper(p[i]))
                rKey[i] = toupper(oKey[pos]); // print upper char
            else
                rKey[i] = tolower(oKey[pos]); // lower char
            j++; // increment position in oKey
        }
        i++; // increment position in p
    }
    
    rKey[i] = '\0'; // cant forget the allmighty null-terminator

    return rKey;
}

char caesar(char c, int shift)
{
    if (isupper(c))
    {
        // would it overrun for uppercase?
        if (c + shift > 'Z')
        {
            return 'A' + (c + shift) % 'Z' - 1; // print the wrap around
        }
        else
        {
            return c + shift;
        }
    }
    else
    {
        // would it overrun for lowercase?
        if (c + shift > 'z')
        {
            return 'a' + (c + shift) % 'z' - 1;
        }
        else
        {
            return c + shift;
        }        
    }
}
