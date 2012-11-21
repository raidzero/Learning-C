#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("O hai! ");
    int qUsed = 0; int dUsed = 0; int nUsed = 0; int pUsed = 0;
    float change;
    do 
    {
        printf("How much change is owed? ");
        scanf("%f", &change);
    }
    while (change < 0);
    
    // round the change to 2 decimal places
    change = ceilf(change * 100) / 100;
    
    // now that we have the value, let's calculate quarters
    while (change > 0.24)
    {
        change -= 0.25;
        qUsed++;
    }
    // dimes
    while (change > 0.09)
    {
    
        change -= 0.10;
        dUsed++;
    }
    // nickels
    while (change > 0.04)
    {
        change -= 0.05;
        nUsed++;
    }
    // pennies
    while (change < 0.04 && change > 0.001)
    {
        change -= 0.01;
        pUsed++;
    }
    printf("%d\n", qUsed + dUsed + nUsed + pUsed);
    printf("(%d quarters, %d dimes, %d nickels, %d pennies)\n", qUsed, dUsed, nUsed, pUsed);
    
    return 0;
}
