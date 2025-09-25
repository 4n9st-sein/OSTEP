#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// int main(void){
    // int rc = fork();
    // if (rc < 0) {
         
        // fprintf(stderr,"fork() failed!");
        // exit(1);
    // } else if (rc == 0) {
        // printf("hello\n");
    // } else {
        // sleep(1);
        // printf("goodbye\n");
    // }
    // return 0;
// }

int main(void) {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
    }
    if (pid == 0) {
        close(fd[0]);
        printf("hello\n");
        fflush(stdout);
        write(fd[1], "x", 1);
        close(fd[1]);
    } else {
        close(fd[1]);
        char buf;
        read(fd[0], &buf, 1);
        printf("goodbye\n");
        close(fd[0]);
    }
    return 0;
}