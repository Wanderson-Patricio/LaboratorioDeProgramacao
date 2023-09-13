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

int menor(int a, int b);

Lista* Uniao(Lista* c1, Lista* c2);
Lista* Intersecao(Lista* c1, Lista* c2);
Lista* Diferenca(Lista* c1, Lista* c2);

#endif // HEADER_H_INCLUDED
