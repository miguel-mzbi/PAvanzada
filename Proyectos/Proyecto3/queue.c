#include <stdlib.h>
#include "queue.h"

// Initialize queue
Queue* createQueue(unsigned int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0; 
    queue->rear = capacity - 1;
    queue->array = (unsigned int*) malloc(queue->capacity * sizeof(unsigned int));
    return queue;
}
 
// Queue is full when size equals capacity 
int isFull(Queue *queue) {  
    return (queue->size == queue->capacity);  
}
 
// Queue is empty when size is 0
int isEmpty(Queue *queue) {
    return (queue->size == 0);
}
 
// Add an item to the queue.  
void enqueue(Queue* queue, unsigned int item) {
    if(isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
 
// Remove an item from queue. 
unsigned int dequeue(Queue* queue) {
    if(isEmpty(queue)) return 0;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Get front of queue
unsigned int front(Queue* queue) {
    if (isEmpty(queue)) return 0;
    return queue->array[queue->front];
}
 
// Get rear of queue
unsigned int rear(Queue* queue) {
    if (isEmpty(queue)) return 0;
    return queue->array[queue->rear];
}