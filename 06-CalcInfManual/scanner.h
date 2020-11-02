#include "stdbool.h"
#include "ctype.h"
#include "stdio.h"

typedef enum{
    tokens_add,
    tokens_character,
    tokens_fdt,
    tokens_invalid,
    tokens_multiply,
    tokens_number,
    tokens_lexicalError,
    tokens_left_bracket,
    tokens_right_bracket,
    tokens_equals
} Tokens;
void writeToken(int);
void lexicalError();
bool isAdd(const int);
bool isMultiply(const int);
bool isFDT(const int);
bool isRightBracket(const int);
bool isLeftBracket(const int);
bool isEquals(const int);
Tokens scanner();
Tokens GetNextToken();