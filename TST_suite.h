#ifndef TST_SUITE_H
#define TST_SUITE_H

void TST_iniciar();

void TST_assert(int condicao, char* mensagem);

void TST_assert_not(int condicao, char* mensagem);

void TST_finalizar();

#endif
