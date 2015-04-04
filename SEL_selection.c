#include <stdio.h>
#include <stdlib.h>
#include "SEL_selection.h"
#include "BEN_benchmark.h"

void troca(int *v1, int *v2, Benchmark b){
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
    BEN_copiou_registro(b);
    return;
}

int encontra_menor(int *v, int posicao, int tam, Benchmark b){
    int menor = v[posicao], menor_posi = posicao;
    while(posicao < tam){
        BEN_comparou_chave(b);
        if(v[posicao] < menor){
            menor = v[posicao];
            menor_posi = posicao;
        }
        posicao = posicao + 1;
    }
    return menor_posi;
}

void SEL_sort(int *v, int tam, Benchmark b){
    BEN_iniciar_medicao(b);
    int i, pos;
    for(i = 0; i < tam; i++){
        pos = encontra_menor(v, i, tam, b);
        troca((v + i), (v + pos), b);
    }
    BEN_terminar_medicao(b);
    return;
}
