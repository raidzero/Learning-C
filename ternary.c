#include <stdio.h>

int main(void)
{
    int a = 2;
    
    // this
    char *s1 = (a==2) ? "hello" : "goodbye";
    
    /* is equivalent to 
    char *s1;
    if (a ==2)
    {
        s1 = "hello";
    }
    else
    {
        s1 = "goodbye";
    }
    */

    printf("%s\n", s1);
    return 0;
}
