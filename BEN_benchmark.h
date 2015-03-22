#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

#ifndef BEN_BENCHMARK_H

#define BEN_BENCHMARK_H

/**Alias para um ponteiro para o struct de tipo _benchmark. Este struct fica encapsulado 
dentro do modulo e não é possivel acessar seus valores diretamente. */
typedef struct _benchmark* Benchmark;


typedef unsigned long long MEDIDA;




/* Funcoes */

Benchmark BEN_criar();


Benchmark BEN_destruir(Benchmark benchmark);


void BEN_iniciar_medicao(Benchmark benchmark);


void BEN_terminar_medicao(Benchmark benchmark);


void BEN_comparou_chave(Benchmark benchmark);


void BEN_copiou_registro(Benchmark benchmark);


clock_t BEN_tempo_processamento(Benchmark benchmark);


MEDIDA BEN_chaves_comparadas(Benchmark benchmark);

MEDIDA BEN_registros_copiados(Benchmark benchmark);

void BEN_imprimir(Benchmark benchmark);


#endif
