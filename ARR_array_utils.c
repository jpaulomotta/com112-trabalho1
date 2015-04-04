#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para comparar 2 vetores e caso sejam iguais retornam 1 senao retorna 0
int ARR_equals(int vet_a[], int vet_b[], int n)
{
    int i;
    for (i=0; i<n ; i++)
    {
        if (vet_a[i] != vet_b[i])
        {
            return 0;
        }
    }
    return 1;
}
// Função para copiar um vetor enviado de tamanho N em um outro criado dentro da função dinamicamente
int* ARR_copiar(int vet[], int n)
{
    int *vet_cop;
    int i;

    vet_cop = ((int*)malloc(n*sizeof(int)));

    for (i=0;i<n;i++)
    {
        *((vet_cop)+i)= vet[i];
    }
    return vet_cop;
}
// Função para Criar um Vetor Aleatoriamente
int* ARR_criar_aleatorio(int n, unsigned int semente)
{
    srand(semente);
    int i;
    int *vet_alea;

    vet_alea = ((int*)malloc(sizeof(int)*n));

    for (i=0;i<n;i++)
    {
        *(vet_alea+i) = rand();
    }
    return vet_alea;
}
