#include "stdio.h"
#include "stdlib.h"
#include "parser.h"



int main(void)
{
    if(parser() == result_ok){
        printf("\nSintaxis valida\n");
    } else {
        printf("\nSintaxis incorrecta\n");
    }
}
