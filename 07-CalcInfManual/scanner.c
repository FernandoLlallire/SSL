#include "scanner.h"

int index_scaner = 0;

char lexema[lexemaSize];

Tokens GetNextToken() {
  return scanner();
}

Tokens scanner() {
  char c = getchar();
  if (isFDT(c)) {
    clearLexema();
    writeLexema(c);
    return tokens_fdt;
  } else if (isalpha(c)) {
    clearLexema();
    writeLexema(c);
    isIdentifier();
    return tokens_identifier;
  } else if (isdigit(c)) {
    clearLexema();
    writeLexema(c);
    isNumber();
    return tokens_number;
  } else if (isMultiply(c)) {
    clearLexema();
    writeLexema(c);
    endToken();
    return tokens_multiply;
  } else if (isAdd(c)) {
    clearLexema();
    writeLexema(c);
    endToken();
    return tokens_add;
  } else if (isLeftBracket(c)) {
    clearLexema();
    writeLexema(c);
    endToken();
    return tokens_left_bracket;
  } else if (isRightBracket(c)) { 
    //endToken();
    //ungetc(')',stdin);
    //writeLexema(c);
    return tokens_right_bracket;
  } else if (isNewLine(c)) {
    //writeLexema(c);
    endToken();
    return tokens_new_line;
  } else if (isspace(c)) {
    //printf("tomo el carcter como espacio \n");
    return GetNextToken();
  } else if (isEquals(c)) {
    writeLexema(c);
    endToken();
    return tokens_equals;
  } else if (isInterpreter(c)){
    writeLexema(c);
    endToken();
    return tokens_interpreter;
  } else {
    printf("caracter invalido '%c'\n", c);
    return tokens_invalid;
  }
}

bool isEquals (char c) {
  return c == '=';
}
bool isInterpreter(char c) {
  return c == '$';
}
bool isMultiply(char c) {
  return c == '*';
}

bool isAdd(char c) {
    return c == '+';
}

bool isLeftBracket(char c) {
  return c == '(';
}
bool isRightBracket(char c) {
  return c == ')';
}

bool isFDT(char c) {
  return c == EOF ;
}

bool isNewLine(char c) {
  return c == '\n' ;
}

void writeLexema(char c) {
  if(index_scaner < lexemaSize) {
    lexema[index_scaner++] = c;
  }
  return;
}

char * getLexema() {
  return lexema;
}

void endToken() {
  writeLexema('\0');
}

void clearLexema() {
  index_scaner = 0;
  lexema[index_scaner] = '\0';
}

/**
 * Aca vamos a tomar un lexema que es identificador (Ver reglas en index.md)
*/
void isIdentifier() {
  char c =  getchar();
  if ( isalpha(c) || isdigit(c) ) {
    writeLexema(c);
    isIdentifier();
  } else {
    endToken();
    // Esto se hace para poder ver los caracteres de EOF y \n
    ungetc(c, stdin);
    return;
  }
}

/**
 * Aca vamos a tomar un lexema que es numero (Ver reglas en index.md)
*/
void isNumber() {
  char c = getchar();
  if (isdigit(c)) {
    writeLexema(c);
    isNumber();
  } else {
    endToken();
        // Esto se hace para poder ver los caracteres de EOF y \n
    ungetc(c, stdin);
    return;
  }
}