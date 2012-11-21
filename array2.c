#include <stdio.h>

int main(void)
{
    // ask for and get an int from the user
    int array_size;
    printf("Enter an array size: ");
    scanf("%d", &array_size);

    // declare an array of ints of array_size
    int x_array[array_size];

    //int *x_array = malloc(sizeof(int) * array_size);

    // initialize each element in the array to i * 2
    for (int i = 0; i < array_size; i++)
    {
        x_array[i] = i * 2;
    }
    
    // print out each element of the array and its index number
    for (int i = 0; i < array_size; i++)
    {
        printf("%d: %d\n", i, x_array[i]);
    }

    //int calculated_size = sizeof(x_array)/sizeof(int);

    //printf("The size of this array is: %d\nThe block of memory is %ld bytes.\nThe size of each int/element is %ld bytes.\n", calculated_size, sizeof(x_array), sizeof(int));

    return 0;
    
}
