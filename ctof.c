#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Enter a temperature (append C/F): ");
    char temp[256];
    fgets(temp, 256, stdin);

    char res_unit = 'Z';
    char temp_unit = 'Z';

    // determine if this is in C or F
    int i;
    for (i=0; i<strlen(temp)+1; i++)
    {   
        if (temp[i] == ' ')
        {
            continue;
        }
        if (temp[i] == 'c' || temp[i] == 'C')
        {
            res_unit = 'F'; temp_unit = 'C';
            break;
        }
        else if (temp[i] == 'f' || temp[i] == 'F')
        {
            res_unit = 'C'; temp_unit = 'F';
            break;
        }
    }

    // did it not find a unit?
    if (res_unit == 'Z' || temp_unit == 'Z')
    {
        printf("Need a unit at the end of the input!\n");
        return 1;
    }

    // now remove that last character from the string
    char c_input[20];
    for (i=0; i<strlen(temp)+1; i++)
    {
        if (temp[i] == ' ')
        {
            // we dont want no damn spaces
            continue;
        }
        c_input[i] = temp[i];
    }    
    c_input[i+1] = '\0'; // almighty null-terminator
    
    float res, input;
    sscanf(c_input, "%f", &input); // w00t thats just awesome

    if (temp_unit == 'c' || temp_unit == 'C')
    {
        res = ((input * 9) / 5.0) + 32; // convert to F
    }
    if (temp_unit == 'f' || temp_unit == 'F')
    {
        
        res = ((input - 32) * 5) / 9.0; // convert to C
    }
    
    printf("%.1f%c is %.1f%c\n", input, temp_unit, res, res_unit);
    
    return 0;
}
