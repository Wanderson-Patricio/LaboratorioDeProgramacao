#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    int n = 3;
    Lista* a = fillList(n);
    Lista* b = fillList(n);
    Lista* uniao = Uniao(a, b);
    Lista* intersecao = Intersecao(a, b);
    Lista* dif = Diferenca(a, b);

    printList(uniao);
    printList(intersecao);
    printList(dif);

    deleteList(a);
    deleteList(b);
    deleteList(uniao);
    deleteList(intersecao);
    deleteList(dif);
    return 0;
}
