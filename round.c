#include <math.h>
#include <stdio.h>

int main(void)
{
    float crap = 0.416;
    float fCrap;
    fCrap = round(100 * crap) / 100;

    printf("%f\n", fCrap);
    return 0;
}


