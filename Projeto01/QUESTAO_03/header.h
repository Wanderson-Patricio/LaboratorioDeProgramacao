#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define MAX 50

typedef struct pessoa{
    char nome[50];
    int senha;
}Pessoa;

typedef struct fila{
    int qtd, inicio, fim;
    Pessoa dados[MAX];
}Fila;

Pessoa criaPessoa(char* nome, int senha);

Fila* criaFila();

void destruir(Fila *fe);

int tamanho(Fila *fe);

int cheia(Fila* fe);

int vazia(Fila* fe);

int tamanho(Fila *fe);

int inserir(Fila *fe, Pessoa novo);

int remover(Fila *fe, Pessoa* p);

#endif // HEADER_H_INCLUDED
