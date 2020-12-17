#include "stdbool.h"
#include "ctype.h"
#include "stdio.h"
#include "string.h"

typedef enum{
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
} Tokens;

int index_scaner = 0;
const int lexemaSize = 100;

char lexema[lexemaSize];

const char * getLexema();

void writeToken(char);
void lexicalError();
void clearLexema();
void isIdentifier();
void isNumber();
void endToken();

bool isAdd(char);
bool isMultiply(char);
bool isFDT(char);
bool isRightBracket(char);
bool isLeftBracket(char);
bool isEquals(char);
bool flagToken = true;

Tokens token;
Tokens scanner();
Tokens GetNextToken();