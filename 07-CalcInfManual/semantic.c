#include "semantic.h"

//Como no podemos saber cuantos elementos hay populados tenemos que hacer esto 
int quantityOfVariables = 0;


void addVariable(char identifier[lexemaSize], int number) {
    for(int i = 0; i< quantityOfVariables ; i++) {
        if (strcmp(variables[i].variable, identifier) == 0) {
            variables[i].number = number;
            return;
        }
    }
    strcpy(variables[quantityOfVariables].variable, identifier);
    variables[quantityOfVariables++].number = number;
    return;
}

int getVariable(char identifier[lexemaSize]) {
    for (int i = 0; i < quantityOfVariables; i++) {
        if (strcmp(variables[i].variable, identifier) == 0) {
            return variables[i].number;
        }
    }
    printf("variable %s no definida\n", identifier);
    return -1;
}