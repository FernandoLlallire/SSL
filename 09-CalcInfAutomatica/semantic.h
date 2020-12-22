#pragma once
#include "scanner.h"

typedef struct {
    char variable[lexemaSize];
    int number;
} Variable;

Variable variables[lexemaSize];

void addVariable(char [], int);
int getVariable(char []);