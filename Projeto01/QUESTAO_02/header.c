#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

typedef struct lista{
    char label[50];
    int size;
    int front;
    int* array;
}Lista;

Lista* createList(int n, char* label){
    Lista* l = (Lista*)malloc(sizeof(Lista));

    if(l != NULL){
        strcpy(l->label, label);
        l->size = n;
        l->front = 0;
        l->array = (int*)malloc(n*sizeof(int));
    }

    return l;
}

void deleteList(Lista* l){
    free(l);
}

int isIn(Lista* l, int n){
    for(int i=0; i < l->front; i++){
        if(*(l->array + i) == n) return 1;
    }

    return 0;
}

int insertInList(Lista* l, int n){
    if(l == NULL || l->array == NULL || isIn(l, n) == 1 || l->front == l->size){
        return 0;
    }

    *(l->array + l->front) = n;
    l->front++;
    return 1;
}

int removeFromList(Lista* l, int i){
    if(l == NULL || l->array == NULL || l->front == 0 || i >= l->front){
        return 0;
    }

    int removed = *(l->array + i);
    for(int j=i; j<l->size-1; j++){
        *(l->array + j) = *(l->array + j+1);
    }

    l->front--;
    return removed;
}

Lista* fillList(int n){
    char label[50];
    printf("Qual o nome rotulo da lista: ");
    fgets(label, 50, stdin);
    Lista* l = createList(n, label);
    int aux;
    for(int i=0; i < n; i++){
        printf("Digite l[%d]: ", i);
        scanf("%d", &aux);

        while(isIn(l, aux) == 1){
            printf("Valor já inserido. Digite novamente: ");
            scanf("%d", &aux);
        }

        int inseriu = insertInList(l, aux);
        if(!inseriu){
            i = i-1;
        }
    }

    return l;
}

void printList(Lista* l){
    if(l==NULL || l->array == NULL) return;
    printf("Valores da Lista %s \n", l->label);
    for(int i=0; i<l->front; i++){
        printf("a[%d] = %d \n", i, *(l->array + i));
    }
}
