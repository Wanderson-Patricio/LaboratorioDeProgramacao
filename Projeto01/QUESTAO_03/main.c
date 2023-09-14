#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    Fila* par = criaFila();
    Fila* impar = criaFila();
    Pessoa p1, p2;
    char nome[50];
    int opcao, senha, inseriu, removeu;

    while(1){
        printf("O que deseja fazer?\nInserir uma nova pessoa - Digite qualquer numero\n0-sair\n");
        scanf("%d", &opcao);

        if(opcao == 0){
            break;
        }
        system("cls");

        printf("Digite o nome da pessoa:\n");
        fflush(stdin);
        //fgets(nome, 50, stdin);
        scanf("%[^\n]s", nome);

        printf("Digite a senha dela:\n");
        scanf("%d", &senha);

        if(senha%2 == 0){
            inseriu = inserir(par, criaPessoa(nome, senha));
        }else{
            inseriu = inserir(impar, criaPessoa(nome, senha));
        }

        if(inseriu == 1){
            printf("Inserido com sucesso.\n");
        }else{
            printf("Erro ao inserir.\n");
        }

        if(tamanho(par) > 0 && tamanho(impar) > 0){
            removeu = remover(par, &p1);
            removeu = remover(impar, &p2);

            if(removeu){
               printf("Uma nova dupla foi formada.\n");
               printf("%s(senha %d) e %s(senha %d)\n", p1.nome, p1.senha, p2.nome, p2.senha);
            }

        }

        system("pause");
        system("cls");

    }

    destruir(par);
    destruir(impar);
    return 0;
}
