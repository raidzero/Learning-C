#include <stdio.h>

// prototype
void chorus(int);

int main(void)
{
    printf("How many bottles? ");
    
    int bottles;
    scanf("%d", &bottles);

    for (bottles; bottles>0; bottles--)
    {
        chorus(bottles); 
    }


    return 0;
}

void chorus(int b)
{
    char *s1 = (b==1) ? "bottle" : "bottles";
    char *s2 = (b==2) ? "bottles" : "bottle";

    printf("\n");
    printf("%d %s of beer on the wall.\n", b, s1);
    printf("%d %s of beer on the wall.\n", b, s1);
    printf("take one down pass it around,\n");
    printf("%d %s of beer on the wall.\n", b-1, s2);    
}
