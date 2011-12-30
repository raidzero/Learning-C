#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

//2011-12-23.18.38.17 - CWM: %F.%H.%M.%S
//GWK74-BDCSA-20111226-0444 - RZR: %Y%m%d-%H%M 
char timestamp[64];

void get_timestamp()
{
    char            fmt[64];
    struct timeval  tv;
    struct tm       *tm;

    gettimeofday(&tv, NULL);
    if((tm = localtime(&tv.tv_sec)) != NULL)
    {
            strftime(fmt, sizeof fmt, "%Y%m%d-%H%M", tm);
            snprintf(timestamp, sizeof timestamp, fmt, tv.tv_usec);
    }
}

int main()
{
  get_timestamp();
  printf("Timestamp: %s\n", timestamp);
  return 0;
}