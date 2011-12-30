/*
################################################################################
##                              diskstat.c                                    ##
################################################################################
## diskstat returns (or will soon return to be more precice) webified diskstat for specific disk, should change to     ##
## XML'ified info at some point.....                                          ##
################################################################################
*/

#include <sys/statvfs.h>

int main( int argc, char *argv[] )
{
        struct statvfs fiData;
        struct statvfs *fpData;
        char fnPath[128];
        int i;

        if( argc < 2 ) {
                printf("Usage, webdisk DEVICE0 ..... DEVICEX\n");
                return(2);
        }

        //Lets loopyloop through the argvs
        for( i = 1 ; i<argc; i++ ) {
                strcpy(fnPath, argv[i]);
                if((statvfs(fnPath,&fiData)) < 0 ) {
                        printf("Failed to stat %s:\n", fnPath);
                } else {
                        printf("Disk %s: \n", fnPath);
                        printf("\tblock size: %u\n", fiData.f_bsize);
                        printf("\ttotal no blocks: %i\n", fiData.f_blocks);
                        printf("\tfree blocks: %i\n", fiData.f_bfree);
                }
        }
}