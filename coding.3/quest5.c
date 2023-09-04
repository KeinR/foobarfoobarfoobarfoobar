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
        pid_t c = wait(NULL);
        printf("Child got: %i\n", c);
        printf("Hello, \n");
    } else if (p > 0) {
        // assert(p == wait(NULL));
        printf("and goodbye.\n");
    } else {
        abort();
    }

    return 0;
}

/******************************
*  Orion Musselman, 学生です。作戦始まります！
*  Q1: The PID of the child process.
*  Q2: Nothing. There is no one to wait for. wait() returns with error.
*
*******************************/
