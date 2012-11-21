#include <stdio.h>

int main(void)
{
    int numbers[5];

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    numbers[4] = 5;

    int i;
    for (i = 0; i<5; i++)
    {
        printf("%d: %d\n", i, numbers[i]);
    }    

    return 0;

}
