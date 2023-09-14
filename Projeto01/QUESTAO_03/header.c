#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "header.h"

Pessoa criaPessoa(char* nome, int senha){
    Pessoa p;
    strcpy(p.nome, nome);

    p.senha = senha;
    return p;
}

Fila* criaFila(){
    Fila* fe = (Fila*)malloc(sizeof(Fila));

    if(fe != NULL){
        fe->fim = 0;
        fe->inicio = 0;
        fe->qtd = 0;
    }

    return fe;
}

void destruir(Fila *fe){
    free(fe);
}

int tamanho(Fila *fe){
    if(fe == NULL){
        return -1;
    }else{
        return fe->qtd;
    }
}

int cheia(Fila* fe){
    if(fe == NULL) return -1;
    if(fe->qtd == MAX) return 1;

    return 0;
}

int vazia(Fila* fe){
    if(fe == NULL) return -1;
    if(fe->qtd == 0) return 1;

    return 0;
}

int inserir(Fila *fe, Pessoa novo){
    if(fe == NULL){
        return 0;
    }else if(cheia(fe)){
        return 0;
    }else{
        fe->dados[fe->fim] = novo;
        fe->qtd++;
        fe->fim = (fe->fim +1)%MAX;
        return 1;
    }
}

int remover(Fila *fe, Pessoa* p){
    if(fe == NULL){
        return 0;
    }else if(vazia(fe)){
        return 0;
    }else{
        *p = fe->dados[fe->inicio];
        fe->inicio = (fe->inicio+1)%MAX;
        fe->qtd--;
        return 1;
    }
}
