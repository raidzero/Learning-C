#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Enter a string: ");
    char s[256];
    fgets(s, 256, stdin);

    int i;
    int lCount = i;
    int len = strlen(s);

    for (i=0; i<len; i++)
    {
        if (isalpha(s[i]))
        {
            lCount++;
        }
        if (lCount % 2 == 0)
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", tolower(s[i]));
        }
    }

    printf("\n");
    return 0;
}
