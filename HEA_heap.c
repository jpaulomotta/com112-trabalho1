#include "HEA_heap.h"
#include "BEN_benchmark.h"


void criaHeap (int *vet, int i, int f, Benchmark b){
    int aux = vet[i];
    int j = i*2+1;
    while (j<=f){
        if (j < f)
        {
            BEN_comparou_chave(b);
            if (vet[j] < vet[j+1])
            {
                j +=1;
            }
        }
        BEN_comparou_chave(b);
        if (aux<vet[j]){
            BEN_copiou_registro(b);
            vet[i] = vet[j];
            i=j;
            j = 2*i+1;
        }
        else
            j = f+1;
    }
    vet[i] = aux;
}

void HEA_sort (int *vet, int n, Benchmark b){
    int i, aux;
    BEN_iniciar_medicao(b);

    for (i=(n-1)/2; i>=0; i--){
        criaHeap (vet, i, n-1, b);
    }
    for (i=n-1; i>=1; i--){
        BEN_copiou_registro(b);
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap (vet, 0, i-1, b);
    }

    BEN_terminar_medicao(b);
}

