#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "BEN_benchmark.h"
#include "TST_suite.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif



void dormir(int s)
{
    #ifdef _WIN32
    Sleep(s); 
    #else
    sleep(s);
    #endif
}


int main(int argc, char** argv)
{
    clock_t tempo_a = 0, tempo_b = 0, tempo_final = 0, tempo_final_2 = 0;

    TST_iniciar();
    
    Benchmark b = BEN_criar();

    TST_assert((long long int)b, "o ponteiro deve ser nao nulo");

    
    BEN_iniciar_medicao(b);
    TST_assert((int)BEN_chaves_comparadas(b)==0, "Inicia com contador de chaves = 0");
    TST_assert_not(BEN_registros_copiados(b), "Inicia com contador de registros = 0");
    
    dormir(1);
    
    tempo_a = BEN_tempo_processamento(b);
    
    TST_assert(tempo_a, "Tempo de processamento deve ser > 0");
    
    dormir(1);
    tempo_b = BEN_tempo_processamento(b);
    TST_assert(tempo_b > tempo_a, "O tempo no futuro deve ser maior do que no passado");
   
    dormir(1);
    BEN_terminar_medicao(b);
    tempo_final = BEN_tempo_processamento(b);
    dormir(1);
    tempo_final_2 = BEN_tempo_processamento(b);
    TST_assert(tempo_final == tempo_final_2, "O tempo de processamento deve permanecer inalterado");
   
    TST_finalizar();
    return 0;
}
