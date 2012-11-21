#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Enter a string: ");
    char s[256];
    fgets(s, 256, stdin);

    int lenCount = 0;
    int len = strlen(s);

    // 32 positions between ascci upper and lower

    for (int i=0; i<len; i++)
    {
        if (s[i] >= 65 && s[i] <= 122)
        {
            lenCount++;
            if (lenCount % 2 == 0)
            {
                printf("%s", s[i] - 32);
            }
            else
            {
                printf("%c", s[i]);
            }                
        }
        else
        {
            printf("%c", s[i]);
        }        
    }    
    
    printf("\n");
    return 0;
}
