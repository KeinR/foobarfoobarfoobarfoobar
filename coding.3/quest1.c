#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int a = 100;
    pid_t p = fork();
    if (p == 0) {
        printf("In child: %i\n", a);
        a = 21;
    } else if (p > 0) {
        printf("In parent: %i\n", a);
        a = 66;
    } else {
        abort();
    }
    printf("parent: %s, a: %i\n", p > 0 ? "true" : "false", a);

    return 0;
}

/******************************
*  Orion Musselman, 学生です。作戦始まります！
*  Q1: 100
*  Q2: The value of a is precisely what the parent and child processesies
*  changed it to, as the programs are entirely different (they forked, clearly).
*
*******************************/
