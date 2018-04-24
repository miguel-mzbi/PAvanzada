#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
// #include <stdlib.h>

int main() {
    int pid;
    pid = fork();
    if(pid == 0) {
        pid = fork();
        if(pid == 0) {
            printf("I'm the daemon\n");
            fclose(stdin);
            fclose(stdout);
            fclose(stderr);
            umask(0);
            chdir("/tmp");
            while(1) {

            }
        }
    }
    return 0;
}