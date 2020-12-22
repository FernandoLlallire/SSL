#include "stdbool.h"
#include "ctype.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "parserTokens.h"
#define lexemaSize 100
/*typedef enum{
    tokens_add,
    tokens_identifier,
    tokens_fdt,
    tokens_invalid,
    tokens_multiply,
    tokens_number,
    tokens_lexicalError,
    tokens_left_bracket,
    tokens_right_bracket,
    tokens_equals,
    tokens_interpreter,
    tokens_new_line
} Tokens;*/

char * getLexema();

void writeLexema(char *);
void lexicalError();
void isIdentifier();
void isNumber();
void endToken();

bool isAdd(char);
bool isMultiply(char);
bool isFDT(char);
bool isRightBracket(char);
bool isLeftBracket(char);
bool isEquals(char);
bool isNewLine(char);
bool isInterpreter(char);

void ungetLex(char);
//Tokens token;
//Tokens scanner();
int GetNextToken();