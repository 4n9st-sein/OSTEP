#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        char* myargs[2];
        myargs[0] = "ls";
        myargs[1] = NULL; 
        execvp("ls", myargs);
    } else {
        wait(NULL);
        return 0;
    }
}