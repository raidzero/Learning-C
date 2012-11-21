#include <stdio.h>

int main(void)
{
    int i;
    for (i=0; i<10; i++)
    {
        printf("%d\n", i);
    }
    
    // this will not work
    printf("the value of i is: %d\n", i);
    
    return 0;
}   
