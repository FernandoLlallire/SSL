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

int sintaxError = false;
int parser();
int listOfExpresions();
int expresion();
ParserState setStatus(Tokens);