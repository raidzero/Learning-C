#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>

int reboot_afterwards;

char* get_android_version()
{
  char* result;
  FILE * vers = fopen("build.prop", "r");
  if (vers == NULL) 
  {
    printf("file not found!\n");
	return NULL;
  }

  char line[512];
  while(fgets(line, sizeof(line), vers) != NULL && fgets(line, sizeof(line), vers) != EOF) //read a line
  {
	if (strstr(line, "ro.build.display.id") != NULL)
	{
	  printf("found line: %s\n", line);
	  char* strptr = strstr(line, "=") + 1; 
	  result = calloc(strlen(strptr) + 1, sizeof(char));
	  strcpy(result, strptr);  
	  printf("android_version: %s\n", result);
	  break; //leave the loop, we found what we're after
	}
  }
  //replace spaces with _
  int count;
  for (count=0; count<strlen(result); count++)
  {
	if (result[count] == ' ') result[count] = '_';  
	if (result[count] == '(' || result[count] == ')') result[count] = '.';
  }
  fclose(vers); 
  return result;
} 

int main()
{
   char* vers_string = get_android_version();
   printf("string: %s\n", vers_string);
   return 0;
 }