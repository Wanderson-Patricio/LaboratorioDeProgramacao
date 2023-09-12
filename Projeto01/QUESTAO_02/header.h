#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct lista Lista;

Lista* createList(int n, char* label);

void deleteList(Lista* l);

int isIn(Lista* l, int n);

int insertInList(Lista* l, int n);

int removeFromList(Lista* l, int i);

Lista* fillList(int n);

void printList(Lista* l);

#endif // HEADER_H_INCLUDED
