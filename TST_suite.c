#include <stdio.h>
#include "TST_suite.h"

int succeded_assertions;
int failed_assertions;

void TST_iniciar()
{
    
    succeded_assertions = failed_assertions = 0;
    printf("Iniciando testes\n");

}


void imprimir_mensagem_erro(char* mensagem)
{
    if(failed_assertions == 1)
    {
        printf("Testes com erro: \n");
    }   
    
    printf("\n%d) %s\n", failed_assertions, mensagem);
}

void TST_assert(int condicao, char* mensagem)
{
    if(condicao)
    {
        succeded_assertions++;
        printf(".");
        fflush(stdout);
    }
    else
    {
        failed_assertions++;
        imprimir_mensagem_erro(mensagem);
    }
}

void TST_assert_not(int condicao, char* mensagem)
{
    if(!condicao)
    {
        succeded_assertions++;
        printf(".");
        fflush(stdout);
    }
    else
    {
        failed_assertions++;
        imprimir_mensagem_erro(mensagem);
    }
}

void TST_finalizar(int condicao)
{
    printf("\n\n");
    printf("Fim dos testes.\n");
    printf("Resultado: %d verificacoes, %d passaram, %d falharam.\n", 
        succeded_assertions+failed_assertions, succeded_assertions, failed_assertions);
}
