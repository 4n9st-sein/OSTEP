#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(void) {
    int x = 100;
    int y = 0;
    int p = &y;

    printf("pid: %d x: %d y: %d\n", getpid(), x, y);
    int rc= fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        y += 50;
        printf("pid: %d x: %d y: %d\n", getpid(), x, y);
    } else {
        y += 100;
        printf("pid: %d x: %d y: %d\n", getpid(), x, y);
        int rc_wait = wait(NULL);
    }
    return 0;
}

