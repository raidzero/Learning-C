#include <stdio.h>

int main(void)
{
    printf("The size of a char is %ld bytes.\n", sizeof(short));
    printf("The size of an int is %ld bytes.\n", sizeof(int));
    printf("The size of a long is %ld bytes.\n", sizeof(long));
    printf("The size of a long long is %ld bytes.\n", sizeof(long long));
    printf("The size of a float is %ld bytes.\n", sizeof(float));
    printf("The size of a double is %ld bytes.\n", sizeof(double));

    return 0;
}
