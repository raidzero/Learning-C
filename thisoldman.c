#include <stdio.h>

void chorus(int number)
{
    char *num;
    char *thing;

    switch (number)
    {
        case 1: 
            num = "one";
            thing = "on my thumb";
            break;
        case 2:
            num = "two";
            thing = "on my shoe";
            break;
        case 3:
            num = "three";
            thing = "on my knee";
            break;
        case 4:
            num = "four";
            thing = "on my door";
            break;
        case 5:
            num = "five";
            thing = "on my hive";
            break;
        case 6:
            num = "six";
            thing = "on my sticks";
            break;
        case 7:
            num = "seven";
            thing = "up in heaven";
            break;
        case 8:
            num = "eight";
            thing = "on my gate";
            break;
        case 9:
            num = "nine";
            thing = "on my spine";
            break;
        case 10:
            num = "ten";
            thing = "once again";
            break;
    }

    printf("This old man, he played %s\n", num);
    printf("He played knick-knack %s\n", thing);
    printf("Knick-knack paddywhack, give your dog a bone\n");
    printf("This old man came rolling home\n");
    printf("\n");
}

int main(void)
{
    int i;
    for (i=1; i<=10; i++)
    {
        chorus(i);
    }
    return 0;
}
