#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t p = fork();
    if (p == 0) {
        printf("Hello, ");
        fflush(stdout);
    } else if (p > 0) {
        assert(p == waitpid(p, NULL, 0));
        printf("and goodbye.\n");
    } else {
        abort();
    }

    return 0;
}

/******************************
*  Orion Musselman, 学生です。作戦始まります！
*  Q1: If you spawn multible child processes and need to wait for a particular
*  one.
*
*******************************/
