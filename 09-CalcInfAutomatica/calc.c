#include "stdio.h"
#include "stdlib.h"
#include "parser.h"



int main(void)
{
    /*
    Este es un pequeño cambio aplicado, 
    en realidad com veniamos trabajando se tendria que llamar parser()
    pero como ya es creado directamente por bison, dejamos para usar el
    metodo que viene por defecto directamente
    */
    yyparse(); 
}
