#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>

#define LOCK "no_nicities"

int main(int argc, char **argv) {
    unlink(LOCK);
    pid_t p = fork();
    if (p == 0) {
        printf("Hello, ");
        fflush(stdout);
        int fd = open(LOCK, O_CREAT | O_RDWR, S_IRWXU);
        assert(fd != -1);
        close(fd);
    } else if (p > 0) {
        while (open(LOCK, O_RDONLY) == -1);
        printf("and goodbye.\n");
    } else {
        abort();
    }

    return 0;
}

/******************************
*  Orion Musselman, 学生です。作戦始まります！
*  Q1: Yes, yes I think I can.
*
*******************************/
