#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions.h"

void preenche_vet(int* vet, int n, int maximo){
    for(int i=0; i<n; i++){
        vet[i] = rand()%maximo + 1;
    }
}

void copia_vet(int* vet1, int* vet2, int n){
    for(int i=0; i<n; i++){
        vet2[i] = vet1[i];
    }
}

int main(){
    srand(time(NULL));

    int max_n = 5;

    int n, tam = pow(10,max_n), maximo = 1000000;
    int vet[tam], vet_aux[tam];

    clock_t start, end;
    double cpu_time_used;

    printf("MERGE SORT \n");

    for(int j = 1; j<=max_n; j++){
        n = pow(10, j);
        printf("Experimento com vetores de tamanho %d: \n\n", n);

        for(int i = 0; i<10; i++){
            preenche_vet(vet, n, maximo);

            // Original
            copia_vet(vet, vet_aux, n);
            start = clock();
            mergeSortOriginal(vet_aux, 0, n-1);
            end = clock();
            cpu_time_used = (double) (end-start)/CLOCKS_PER_SEC;
            printf("Experimento %d ::: Original: %.4f s --- ",i+1, cpu_time_used);

            // Chat-GPT
            copia_vet(vet, vet_aux, n);
            start = clock();
            mergeSortGPT(vet_aux, 0, n-1);
            end = clock();
            cpu_time_used = (double) (end-start)/CLOCKS_PER_SEC;
            printf("GPT: %.4f s \n", cpu_time_used);
        }

        printf("\n\n");
    }

    printf("INSERTION SORT \n");

    for(int j = 1; j<=max_n; j++){
        n = pow(10, j);
        printf("Experimento com vetores de tamanho %d: \n\n", n);

        for(int i = 0; i<10; i++){
            preenche_vet(vet, n, maximo);

            // Original
            copia_vet(vet, vet_aux, n);
            start = clock();
            insertionSortOriginal(vet_aux, n);
            end = clock();
            cpu_time_used = (double) (end-start)/CLOCKS_PER_SEC;
            printf("Experimento %d ::: Original: %.4f s --- ",i+1, cpu_time_used);

            // Chat-GPT
            copia_vet(vet, vet_aux, n);
            start = clock();
            insertionSortGPT(vet_aux, n);
            end = clock();
            cpu_time_used = (double) (end-start)/CLOCKS_PER_SEC;
            printf("GPT: %.4f s \n", cpu_time_used);
        }

        printf("\n\n");
    }

    return 0;
}
