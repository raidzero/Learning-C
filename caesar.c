#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s [SHIFT]\n", argv[0]);
        return 1;
    }

    printf("Please enter a string to shift: ");
    char input[256];
    fgets(input, 256, stdin);

    int shift = atoi(argv[1]);

    if (shift > 26)
        shift = shift - 26;

    /* ASCII references
     A = 65, Z = 90, a = 97, z = 122 */
    
    int i;
    int len = strlen(input);
    int pass = 0;
    int overrun = 0;

    for (i=0; i<len; i++)
    {
        pass = 0;
        if (input[i] < 65 || input[i] > 122 || (input[i] > 90 && input[i] < 97))
            pass = 1;

        if (!pass)
        {
            if (input[i] >= 'A' && input[i] <= 'Z') // uppercase overrun
            {
                if (input[i] + shift > 'Z') 
                {
                    overrun = (input[i] + shift) - 'Z'; // how far past did we go?
                    printf("%c", (char) 'A' - 1 + overrun);
                }
                else
                {
                    printf("%c", input[i] + shift); // print just the shifted value
                }
            }
            else if (input[i] >= 'a' && input[i] <= 'z') // lowercase overrun
            {
                if (input[i] + shift > 'z')
                {
                    overrun = (input[i] + shift) - 'z'; // same as above but for lowercase values
                    printf("%c", (char) 'a' - 1 + overrun);
                }
                else
                {
                    printf("%c", input[i] + shift); // print just the shifted value
                }                
            }
        }
        else
        {
            printf("%c", input[i]); // print a non-shifted character
        }
    } 
    printf("\n");

    return 0;
}


