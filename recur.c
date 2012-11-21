#include <stdio.h>

void recur(long long i)
{
    if (i==261772) // on my system this is the stack size or somethign like that
    {
        printf("Recursion depth met. exiting.\n");
        return;
    }
    printf("%lli\n", i);
    recur(i+1);
}

int main()
{
    long long i = 0;
    recur(i);
}
