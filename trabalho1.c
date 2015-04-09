// Trabalho 1 de COM112
// Grupo do Selection e Heap Sort


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BEN_benchmark.h"
#include "HEA_heap.h"
#include "SEL_selection.h"
#include "ARR_array_utils.h"


int ler_parametros(int argc, char** argv, char* nome_entrada, char* nome_saida, int* semente)
{
    if(argc != 4)
    {
        printf("Erro: Parametros invalidos. Entrar com semente nome_de_arquivo_entrada nome_de_arquivo_de_saida");
        return 0;
    }

    *semente = atoi(argv[1]);
    strcpy(nome_entrada, argv[2]);
    strcpy(nome_saida, argv[3]);
    return 1;
}

void ler_arquivo_entrada(FILE* arquivo, int** tamanhos_array, int* n)
{
    int i;
    fscanf(arquivo, "%d", n);
    *tamanhos_array = (int*) malloc(sizeof(int)*(*n));
    for(i = 0; i<(*n); i++)
    {
        fscanf(arquivo, "%d", (*tamanhos_array)+i);
    }
}

void imprimir_benchmark_arquivo(FILE* fp, Benchmark b)
{
    fprintf(fp, "Tempo total de processamento:\t%f ticks\n", (double)BEN_tempo_processamento(b));
    fprintf(fp, "Total de chaves comparadas:\t%llu\n", BEN_chaves_comparadas(b));
    fprintf(fp, "Total de registros copiados:\t%llu\n", BEN_registros_copiados(b));
    fprintf(fp, "\n");
}

void executar_benchmark(int* tamanhos_array, int n, FILE* fp, int semente)
{
    int i;
    Benchmark benchmark = BEN_criar();
    int* vet, *vet_copia;
    for(i = 0; i < n; i++)
    {
        if(i!=0) fprintf(fp, "\n-------------------------\n\n");
        fprintf(fp, "Array %d - Tamanho: %d\n", i, tamanhos_array[i]);

        vet = ARR_criar_aleatorio(tamanhos_array[i], semente);
        vet_copia = ARR_copiar(vet, tamanhos_array[i]);

        fprintf(fp, "Selection Sort\n");
        SEL_sort(vet, tamanhos_array[i], benchmark);
        imprimir_benchmark_arquivo(fp, benchmark);

        fprintf(fp, "Heap Sort\n");
        HEA_sort(vet_copia, tamanhos_array[i], benchmark);
        imprimir_benchmark_arquivo(fp, benchmark);

        free(vet);
        free(vet_copia);
    }

    BEN_destruir(benchmark);
}

int main(int argc, char** argv)
{
    int semente;
    char nome_entrada[100];
    char nome_saida[100];
    int n;
    int* tamanho_array;
    
    FILE* arquivo_entrada, *arquivo_saida;

    if(!ler_parametros(argc, argv, nome_entrada, nome_saida, &semente))
    {
        return -1;
    }

    printf("Lendo %s.\n", nome_entrada);

    arquivo_entrada = fopen(nome_entrada, "r");
    arquivo_saida = fopen(nome_saida, "w");

    ler_arquivo_entrada(arquivo_entrada, &tamanho_array, &n);

    printf("Executando benchmark e imprimindo saida em %s.\n", nome_saida);
    executar_benchmark(tamanho_array, n, arquivo_saida, semente);

    fclose(arquivo_entrada);
    fclose(arquivo_saida);
    free(tamanho_array);

    return 0;
}
