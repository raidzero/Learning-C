#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

static unsigned int total = 0;

int sum(const char *fpath, const struct stat *sb, int typeflag) {
    total += (sb->st_size/1024);
    return 0;
}

int main(int argc, char **argv) {
    if (!argv[1] || access(argv[1], R_OK)) {
        return 1;
    }
    if (ftw(argv[1], &sum, 1)) {
        perror("ftw");
        return 2;
    }
    printf("%s: %u\n", argv[1], total);
    return 0;
}
