#include <stdio.h>
#include <pthread.h>
// COMPILE WIH -pthread flag

#define MAX_THREADS 20

void *helloThread(void *arg) {
    int id = (int)arg;
    printf("Hello World %d\n", id);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_create(
            &threads[i],
            NULL,
            helloThread,
            (void *) i);
    }
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(
            threads[i],
            NULL);
    }
    return 0;
}