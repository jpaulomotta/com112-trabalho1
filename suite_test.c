#include <stdio.h>
#include "TST_suite.h"


int main(int argc, char** argv)
{
    TST_iniciar();
    
    TST_assert(1 == 1, "Este teste é verdadeiro e deve passar");
    TST_assert((2+2) == 5, "Este teste deve falhar 2 + 2 = 5");
    
    TST_assert_not((3*3) == 900, "Este teste deve passar");
    TST_assert_not((2+2) == 4, "Este teste deve falhar");
    
    //Dois testes devem passar e deois devem falhar
    TST_finalizar();
    return 0;
}
