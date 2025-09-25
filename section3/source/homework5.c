#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("hello (pid: %d)\n", (int) getpid());
    pid_t pid = getpid();
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        //child (nex process)
        int rc_wait = waitpid(pid, NULL, NULL);
        printf("parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    } else {
        //present goes down this path (main)
        printf("child (pid:%d)\n", (int) getpid());
        
    }
    return 0;
}