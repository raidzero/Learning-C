#include <stdio.h>

int main(void)
{
    int i;
    for(i=0; i<2; i++)
    {
        printf("%d\n", i);
    }

    int j = 0;
    while (j<10)
    {
        printf("%d\n",j );
        j++;
    }
    printf("Done!\n");

    return 0;
}
