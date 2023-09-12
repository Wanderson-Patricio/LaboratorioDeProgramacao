#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

typedef struct queue{
    int size;
    int top;
    int* list;
}Queue;

Queue* createQueue(int n){
    Queue* q = (Queue*)malloc(sizeof(Queue));

    if(q != NULL){
        q->size = n;
        q->top = 0;
        q->list = (int*)malloc(n*sizeof(int));
    }

    return q;
}

void deleteQueue(Queue* q){
    free(q);
}

void enqueue(Queue* q, int n){
    if(q == NULL || q->list == NULL || q->top == q->size){
        printf("Erro ao inserir.\n");
        return;
    }

    *(q->list + q->top) = n;
    q->top++;
}

int dequeue(Queue* q){
    if(q == NULL || q->list == NULL || q->top == 0){
        printf("Não e possivel remover.\n");
        return -1;
    }

    int removed = *(q->list + q->top - 1);
    q->top--;
    return removed;
}

void DecToBin(int n){
    if(n == 0){
        printf("0 na base 10 = 0 na base 2.\n");
        return;
    }

    Queue* q = createQueue(ceil(log(n)/log(2))+1);

    int aux = n;
    while(aux >= 2){
        enqueue(q, aux%2);
        aux = aux/2;
    }

    enqueue(q, aux);

    printf("%d na base 10 = ");

    while(q->top > 0){
        aux = dequeue(q);
        if(aux == 1){
            printf("1");
        }else{
            printf("0");
        }
    }

    printf(" na base 2.\n");
    deleteQueue(q);
}
