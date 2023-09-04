#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv) {
    int fd = open("test.foobar", O_TRUNC | O_CREAT | O_RDWR);
    if (fd == -1) {
        abort();
    }
    pid_t p = fork();
    if (p == 0) {
        const char *str = "foobar Is Treasure";
        size_t intent = strlen(str);
        ssize_t n = write(fd, str, intent);
        printf("child | intent: %i, n: %i, str: '%s'\n", intent, n, str);
    } else if (p > 0) {
        printf("fd: %i\n", fd);
        const char *str = "Change the world, my final message, goodbye.";
        size_t intent = strlen(str);
        ssize_t n = write(fd, str, intent);
        printf("parent | intent: %i, n: %i, str: '%s'\n", intent, n, str);
    } else {
        abort();
    }

    return 0;
}

/******************************
*  Orion Musselman, 学生です。作戦始まります！
*  Q1: Yes, it would appear that they can.
*  Q2: The writes happen sequentially, even through they are being sent
*  asynchronously
*
*******************************/
