#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* SERVERS[] = {
    "192.168.1.1:router",
    "192.168.1.101:nexus",
    "192.168.1.110:fakeserver",
}; 

int main()
{
    int serverCount = sizeof(SERVERS)/sizeof(char*);
    
    int i;
    for (i=0; i<serverCount; i++)
    {
        
        // use strtok() to split our string, after allocating some ram for the line of text
        char* serverLine = malloc(strlen(SERVERS[i]) + i * sizeof(char));
        strcpy(serverLine, SERVERS[i]); // copy SERVERS[i] into our fresh block of memory

        char* ADDRESS = strtok(serverLine, ":");
        char* HOSTNAME = strtok(NULL, ":");  
        
        // set up the ping command
        char *CMD = malloc(strlen("ping 255.255.255.255 -c 1 -W 1 &>/dev/null") + 1 * sizeof(char));
        sprintf(CMD, "ping %s -c 1 -W 1 &>/dev/null", ADDRESS);
        
        // do it and set status vars
        char* STATUS = "OFFLINE"; char* COLOR = "#ff0000";
        if (!system(CMD))
        {
            STATUS = "ONLINE"; COLOR = "#00ff00";
        } 
        // print the result
        printf("${color0}%s (%s)${alignr}${color %s}%s\n", HOSTNAME, ADDRESS, COLOR, STATUS);
    }
    return 0;
}  
