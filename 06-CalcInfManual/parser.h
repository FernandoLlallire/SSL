#include "scanner.h"

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
ParserState setStatus(Tokens);