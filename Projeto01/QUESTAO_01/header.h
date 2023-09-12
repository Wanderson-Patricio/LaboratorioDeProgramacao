#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct queue Queue;

Queue* createQueue(int n);

void deleteQueue(Queue* q);

void enqueue(Queue* q, int n);

int dequeue(Queue* q);

void DecToBin(int n);

#endif // HEADER_H_INCLUDED
