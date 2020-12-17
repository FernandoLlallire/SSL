#include "scanner.h"



Tokens GetNextToken() {
  if (flagToken) {
    return scanner();
  }
  return tokens_invalid;
}

Tokens scanner() {
  clearLexema();
  char c = getchar();
  if (isFDT(c)) {
    writeToken(c);
    return tokens_fdt;
  } else if (isalpha(c)) {
    writeToken(c);
    isIdentifier();
    return tokens_identifier;
  } else if (isdigit(c)) {
    writeToken(c);
    isNumber();
    return tokens_number;
  } else if (isMultiply(c)) {
    writeToken(c);
    endToken();
    return tokens_multiply;
  } else if (isAdd(c)) {
    writeToken(c);
    endToken();
    return tokens_add;
  } else if (isLeftBracket(c)) {
    writeToken(c);
    endToken();
    return tokens_left_bracket;
  } else if (isRightBracket(c)) { 
    writeToken(c);
    endToken();
    return tokens_right_bracket;
  } else if (isNewLine(c)) {
    return tokens_new_line;
  } else if (isspace(c)) {
    return GetNextToken();
  } else if (isEquals(c)) {
    writeToken(c);
    endToken();
    return tokens_equals;
  } else if (isInterpreter(c)){
    writeToken(c);
    endToken();
    return tokens_interpreter;
  } else {
    lexicalError();
    flagToken = false;
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

void lexicalError() {
  printf("Error Lexico\n");
}

void writeToken(char c) {
  if(index_scaner < lexemaSize) {
    lexema[index_scaner++] = c;
  }
  return;
}

const char * getLexema() {
  return lexema;
}

void endToken() {
  writeToken('\0');
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
    writeToken(c);
    isIdentifier();
  } else {
    endToken();
    return;
  }
}

/**
 * Aca vamos a tomar un lexema que es numero (Ver reglas en index.md)
*/
void isNumber() {
  char c = getChar();
  if (isdigit(c)) {
    writeToken(c);
    isNumber();
  } else {
    endToken();
    return;
  }
}