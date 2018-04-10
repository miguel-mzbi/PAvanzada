#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void receiveSignal(int sig) {
    printf("HOLA MUNDO\n");
    printf("RECIBI SEÑAL %d\n", sig);
}

int main(int argc, char **argv) {

    kill(atoi(argv[1]), atoi(argv[2]));
    
    return 0;
}