#include <stdio.h>


int main()
{
    typedef struct {
        char* NAME;
        int AGE;
    } person;

    person p = {"Paul", 27};

    printf("%s is %d years old and has %d years left to live.\n", p.NAME, p.AGE, 80 - p.AGE);
    return 0;
}
