#include <stdio.h>

int main(void)
{
    /* boolean training

    int x = 1;
    int y = 2;

    if (x == 10 || (y == 5 || y ==2))
    {
        printf("yes!\n");
    }
    */

    /* pointers 
    int x = 1;
    int *y = &x;

    printf("x: %d\ny: %d\n", x, *y);

    x++; // increment x
    printf("\nx: %d\ny: %d\n", x, *y);
    */
    
    /* typecasting */
    int x = 80;
    float y = 3.14159;
    char letter = 'P';

    printf("%c\n", (char) x);

    char string[10];
    printf("Enter a string: ");
    scanf("%s", &string);

    int i;
    for (i=0; i<strlen(string); i++)
    {
        printf("%x", (int) string[i]);
    }
}
