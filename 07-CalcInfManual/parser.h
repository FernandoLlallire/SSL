#pragma once
#include "semantic.h"

typedef enum {
    parser_init,
    parser_number,
    parser_operation,
    parser_character,
    parser_error
} ParserState;

typedef enum{
  result_ok,
  result_fail
} Result;

int parser();
int listOfExpresions();
int expresion();
int termino();
int factor();

void sentence();
void Match();
void listOfSentences();

Tokens updateToken();
ParserState setStatus(Tokens);