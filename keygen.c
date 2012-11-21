#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
    char *oKey = argv[1]; // original key

    printf("Text: ");
    char plaintext[512];
    fgets(plaintext, 512, stdin);

    printf("oKey: %s\n", oKey);
    
    int oKeyLen = strlen(oKey); // length of key
    int pLen = strlen(plaintext);

    char *rKey = calloc(pLen, sizeof(char)); // repeat key 

    int i = 0; // track position in plaintext
    int j = 0; // track position in oKey

    while (i < pLen)
    {
        if (j > oKeyLen)
            j = i % oKeyLen;
        rKey[i] = oKey[j];
        i++;
        j++;
    }

    printf("rKey: %s\n", rKey);
    return 0;
}
