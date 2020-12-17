#include "scanner.h"

typedef struct {
    char variable[lexemaSize];
    int number;
} Variable;

Variable variables[lexemaSize];

//Como no podemos saber cuantos elementos hay populados tenemos que hacer esto 
int quantityOfVariables = 0;

void addVariable(char [], int);
int getVariable(char []);