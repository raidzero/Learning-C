#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Enter a temperature (append C/F): ");
    char temp[20];
    scanf("%s", temp);

    //printf("You entered: %s\n", temp);

    // determine if this is in C or F
    int position = strlen(temp)-1;
    char lastChar = temp[position]; // -1 because of the null-terminator

    //printf("lastChar: %c\n", lastChar);
    char res_unit;
    if (lastChar == 'f' || lastChar == 'F')
    {
        res_unit = 'C';
    }
    else
    {
        res_unit = 'F';
    }

    // now remove that last character from the string
    int i;
    char c_input[20];
    for (i=0; i<position; i++)
    {
        if (temp[i] == ' ')
        {
            // we dont want no damn spaces
            continue;
        }
        //printf("temp[%d]: %c\n", i, temp[i]);
        c_input[i] = temp[i];
    }    
    c_input[i+1] = '\0'; // almighty null-terminator

    //printf("c_input: %s\n", c_input);
    
    float res, input;
    sscanf(c_input, "%f", &input); // w00t thats just awesome

    //printf("input: %f\n", input);

    if (lastChar == 'c' || lastChar == 'C')
    {
        res = ((input - 32) * 5) / 9.0; // convert to F
    }
    if (lastChar == 'f' || lastChar == 'F')
    {
        res = ((input * 9) / 5.0) + 32; // convert to C
    }
    
    printf("%.1f%c is %.1f%c\n", input, lastChar, res, res_unit);
    
    return 0;
}
