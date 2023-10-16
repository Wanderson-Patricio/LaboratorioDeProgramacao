#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

void mergeOriginal(int* vet, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio +1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(vet[p1]< vet[p2]){
                    temp[i] = vet[p1];
                    p1++;
                }else{
                    temp[i] = vet[p2];
                    p2++;
                }
                if(p1>meio){
                    fim1 = 1;
                }
                if(p2>fim){
                    fim2 = 1;
                }
            }else{
                if(!fim1){
                    temp[i] = vet[p1];
                    p1++;
                }else{
                    temp[i] = vet[p2];
                    p2++;
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            vet[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSortOriginal(int *vet, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        mergeSortOriginal(vet, inicio, meio);
        mergeSortOriginal(vet, meio+1, fim);
        mergeOriginal(vet, inicio, meio, fim);
    }
}


void mergeGPT(int* vet, int inicio, int meio, int fim) {
    int tamanho = fim - inicio + 1;
    int* temp = (int*)malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        int p1 = inicio;
        int p2 = meio + 1;
        for (int i = 0; i < tamanho; i++) {
            if (p1 <= meio && (p2 > fim || vet[p1] <= vet[p2])) {
                temp[i] = vet[p1];
                p1++;
            } else {
                temp[i] = vet[p2];
                p2++;
            }
        }
        for (int j = 0, k = inicio; j < tamanho; j++, k++) {
            vet[k] = temp[j];
        }
        free(temp);
    }
}

void mergeSortGPT(int* vet, int inicio, int fim) {
    if (inicio < fim) {
        if (fim - inicio < 5) {
            // Use insertion sort for small arrays
            for (int i = inicio; i <= fim; i++) {
                int key = vet[i];
                int j = i - 1;
                while (j >= inicio && vet[j] > key) {
                    vet[j + 1] = vet[j];
                    j--;
                }
                vet[j + 1] = key;
            }
        } else {
            int meio = inicio + (fim - inicio) / 2;
            mergeSortGPT(vet, inicio, meio);
            mergeSortGPT(vet, meio + 1, fim);
            mergeGPT(vet, inicio, meio, fim);
        }
    }
}

void insertionSortOriginal(int *vet, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i;
        while(j > 0 && aux < vet[j-1]){
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = aux;
    }
}

void insertionSortGPT(int *vet, int n) {
    for (int i = 1; i < n; i++) {
        int temp = vet[i];
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (temp < vet[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        for (int j = i; j > low; j--) {
            vet[j] = vet[j - 1];
        }
        vet[low] = temp;
    }
}
