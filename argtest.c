#include <stdio.h>

typedef char* string;

int main(int argc, string argv[])
{
    printf("I was called with %d arguments.\n", argc);

    int count;
    for (count = 0; count < argc; count++)
    {
        printf("%d - %s\n", count, argv[count]);
    }

    return 0;
}
