// Queue structure
struct Queue {
    unsigned int capacity, size, rear, front;
    unsigned int *array;
} typedef Queue;

Queue* createQueue(unsigned int);
int isFull(Queue *);
int isEmpty(Queue *);
void enqueue(Queue*, unsigned int);
unsigned int dequeue(Queue*);
unsigned int front(Queue*);
unsigned int rear(Queue*);