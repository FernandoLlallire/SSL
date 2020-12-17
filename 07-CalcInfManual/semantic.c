#include "semantic.h"

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
    printf("variable not defined");
    return 0;
}