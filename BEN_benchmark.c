#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <stdlib.h>
#include <stdio.h>
#include "BEN_benchmark.h"



struct _benchmark
{
    clock_t tempo_inicio;
    clock_t tempo_termino;
    MEDIDA comparadas;
    MEDIDA copiados;
};


/* Funcoes */

Benchmark BEN_criar()
{
    Benchmark b = (Benchmark) malloc(sizeof(struct _benchmark));
    return b;
}


Benchmark BEN_destruir(Benchmark benchmark)
{
    free(benchmark);
    return 0;
}


void BEN_iniciar_medicao(Benchmark b)
{
    b->tempo_inicio = clock();
    b->tempo_termino = 0;
    b->comparadas = 0;
    b->copiados = 0;
}


void BEN_terminar_medicao(Benchmark b)
{
    b->tempo_termino = clock();
}


void BEN_comparou_chave(Benchmark b)
{
    b->comparadas++;
}   


void BEN_copiou_registro(Benchmark b)
{
    b->copiados++;
}


clock_t BEN_tempo_processamento(Benchmark b)
{
    if(b->tempo_termino)
    {
        return  b->tempo_termino - b->tempo_inicio;
    }
    return clock() - b->tempo_inicio;
}


MEDIDA BEN_chaves_comparadas(Benchmark b)
{
    return b->comparadas;
}

MEDIDA BEN_registros_copiados(Benchmark b)
{
    return b->copiados;
}


void BEN_imprimir(Benchmark b)
{
    printf("Benchmark\n------------------------------\n\n");
    printf("Tempo total de processamento:\t%f clicks\n", (double)BEN_tempo_processamento(b));
    printf("Total de chaves comparadas:\t%llu\n", b->comparadas);
    printf("Total de registros copiados:\t%llu\n", b->copiados);
    printf("\n");
}
