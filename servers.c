#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* SERVERS[] = {
    "192.168.1.1:router",
    "192.168.1.101:nexus",
    "192.168.1.110:fakeserver",
    NULL    
}; 

int arraySize(char* array[])
{
    int i = 0;
    int res = 0;
    while ( array[i] != NULL)
    {
        i++;
        res++;
    }
    return res;
}

/* - replaced by strtok() - no need to roll my own function when there is one in stdlib

char** chopString(char* s, char delim)
{
    int i;
    char* res[2];
    res[0] = malloc(strlen(s) + sizeof(char));
    res[1] = malloc(strlen(s) + sizeof(char));
    
    // split the first part 
    for (i=0; i<strlen(s); i++)
    {
        if (s[i] == delim)
        {
            break;
        }
        res[0][i] = s[i];
    }
    res[0][i++] = '\0';    
    // split the second part
    int j = 0;
    for (i; i<strlen(s); i++)
    {
        res[1][j] = s[i];
        j++;
    }
    res[1][i++] = '\0'; // the almighty null-terminator
   
    return res;
}
*/

int main()
{
    int serverCount = arraySize(SERVERS);
    int i;

    for (i=0; i<serverCount; i++)
    {
        // split up string into two parts        
        /* deprecated by strtok()
        char* ADDRESS = chopString(SERVERS[i], ':')[0];
        char* HOSTNAME = chopString(SERVERS[i], ':')[1];
        */
        // vars to hold stuff
        char* ADDRESS;
        char* HOSTNAME;
        char* STATUS;
        char* COLOR;   
        
        // use strtok() to split our string, after allocating some ram for the line of text
        char* serverLine = calloc(strlen(SERVERS[i]) + i, sizeof(char));
        strcpy(serverLine, SERVERS[i]); // copy SERVERS[i] into opur fresh block of memory

        ADDRESS = strtok(serverLine, ":");
        HOSTNAME = strtok(NULL, ":");  
        
        // set up the ping command
        char CMD[50];
        sprintf(CMD, "ping %s -c 1 -W 1 &>/dev/null", ADDRESS);
        
        // do it and set status vars
        if (!system(CMD))
        {
            STATUS = "ONLINE"; COLOR = "#00ff00";
        } 
        else
        {
            STATUS = "OFFLINE"; COLOR = "#ff0000";
        }
        // print the result
        printf("${color0}%s (%s)${alignr}${color %s}%s\n", HOSTNAME, ADDRESS, COLOR, STATUS);
    }
    return 0;
}  
