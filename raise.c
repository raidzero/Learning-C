/*
 * raise.c 
 * demonstrates the use of passing a struct to a function by reference
 */
#include <stdio.h>

// make a person datatype using typedef
typedef struct {
    char* name;
    float salary;
} person;

void giveRaise(person *p, float percent)
{
    // to access a member of a struct passed by reference we need to use ->
    printf("Give a %.2f%% raise to %s\n", percent*100, p->name);
    p->salary = (percent*p->salary)+p->salary;
}
    
int main(void)
{
    printf("Enter Paul's salary: ");
    float salary;
    scanf("%f", &salary);

    // make a person called paul
    person paul = { "Paul Osborn", salary};

    printf("%s: $%.2f\n", paul.name, paul.salary);
    
    // ask the user how much of a raise to give
    int percent;
    printf("Enter a percentage to raise: ");
    scanf("%d", &percent);
    
    // apply the raise
    giveRaise(&paul, percent/100.0); // pass the person by reference

    printf("%s: $%.2f\n", paul.name, paul.salary);

    return 0;
}
