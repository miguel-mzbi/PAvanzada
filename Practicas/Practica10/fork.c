#include <unistd.h>
#include <stdio.h>

int main() {
    int pid;
    
    pid = fork();
    if(pid == 0) {
        printf("SOY EL HIJO\n");
        execl("/usr/bin/gnome-calculator", "Calculator Cool", (char *)0);
    }
    else {
        printf("SOY EL PADRE\n");
    }
    return 0;
}