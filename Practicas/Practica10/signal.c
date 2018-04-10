#include <signal.h>
#include <stdio.h>

void receiveSignal(int sig) {
    printf("HOLA MUNDO\n");
    printf("RECIBI SEÑAL %d\n", sig);
}

int main() {

    signal(SIGTERM, receiveSignal);

    while(1);
    
    return 0;
}