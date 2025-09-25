#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){
    FILE *fd = fopen("homwork2.txt", "w");
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork()failed");
    } else if (rc == 0) {
        fprintf(fd, "this is written by chiled\n");
    } else {
        wait(NULL);
        fprintf(fd, "this is written by parent\n");
    }
    return 0;
}
