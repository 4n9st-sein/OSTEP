#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){

    int fd[2];
    pipe(fd);
    printf("pid: %d\n", getpid());
    pid_t pid1 = fork();

    if (pid1 < 0) {
        fprintf (stderr, "fork()");
        exit(1);
    } else if (pid1 == 0) {
        //child1
        close(fd[0]);
        char buf[21];
        printf("pid: %d\n", getpid());
        printf("put message less than 20 letters\n");
        scanf("%s", buf);
        write(fd[1], buf, 21);
        close(fd[1]);
    } else {
        wait(NULL);
        pid_t pid2 = fork();
        if (pid2 < 0) {
            fprintf(stderr, "fork()");
            exit(1);
        } else if (pid2 == 0) {
            close(fd[1]);
            char buf[21];
            printf("pid: %d\n", getpid());
            read(fd[0], buf, 21);
            printf("%s\n", buf);
            close (fd[0]);
        } else {
            printf("pid: %d\n", getpid());
            wait(NULL);
        }
    }
    return 0;
}