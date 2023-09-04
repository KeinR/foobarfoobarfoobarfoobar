#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int ends[2];
    assert(pipe(ends) == 0);
    pid_t p0 = fork();
    if (p0 == 0) {
        dup2(ends[1], STDOUT_FILENO);
        close(ends[1]);
        assert(printf("Foobar from p0\n") > 0);
    } else if (p0 > 0) {
        pid_t p1 = fork();
        if (p1 == 0) {
            dup2(ends[0], STDIN_FILENO);
            close(ends[0]);
            char buf[64];
            assert(read(STDIN_FILENO, buf, 64) > 0);
            printf("p1: pipe from p0: '%s'\n", buf);
        } else if (p1 > 0) {
            wait(NULL);
            wait(NULL);
        } else {
            abort();
        }
    } else {
        abort();
    }

    return 0;
}

/******************************
*  Orion Musselman, 学生です。作戦始まります！
* WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
*
*******************************/
