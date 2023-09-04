#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>

#define PROG "/bin/ls"

int main(int argc, char **argv) {
    pid_t p = fork();
    if (p == 0) {
        // execl(PROG, PROG, ".");
        // execlp(PROG, PROG, ".");
        // execle(PROG, PROG, ".");
        char *lst[] = {strdup(PROG), strdup("."), NULL};
        // execv(PROG, lst);
        // execvp(PROG, lst);
        // execvpe(PROG, lst, lst); // Not defined?
        free(lst[0]);
        free(lst[1]);
    } else if (p > 0) {
        printf("lol\n");
    } else {
        abort();
    }

    return 0;
}

/******************************
*  Orion Musselman, 学生です。作戦始まります！
*  Q1: Well, I mean, it's convineint for the people using them, and there are
*  lots of ways to go about calling programs that you might want to do.
*
*******************************/
