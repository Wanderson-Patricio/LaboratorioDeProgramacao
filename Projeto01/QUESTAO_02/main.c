#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    int n = 3;
    Lista* l = fillList(n);
    printList(l);
    deleteList(l);
    return 0;
}
