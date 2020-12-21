#include "scanner.h"

Tokens token;



Tokens GetNextToken() {
    return scanner();
}

Tokens scanner() {
  char c = getchar();
  if (isFDT(c)) {
    return tokens_fdt;
  } else if (isalpha(c)) {
    return tokens_character;
  } else if (isdigit(c)) {
    return tokens_number;
  } else if (isMultiply(c)) {
    return tokens_multiply;
  } else if (isAdd(c)) {
    return tokens_add;
  } else if (isLeftBracket(c)) {
    return tokens_left_bracket;
  } else if (isRightBracket(c)) { 
    return tokens_right_bracket;
  } else if (isspace(c)) {
    return GetNextToken();
  } else if (isEquals(c)) {
    return tokens_equals;
  } else {
    lexicalError();
    return tokens_invalid;
  }
}

bool isEquals (const int c) {
  return c == '=';
}
bool isCalculo(const int c) {
  return c == '$';
}
bool isMultiply(const int c) {
  return c == '*';
}

bool isAdd(const int c) {
    return c == '+';
}

bool isLeftBracket(const int c) {
  return c == '(';
}
bool isRightBracket(const int c) {
  return c == ')';
}

bool isFDT(const int c) {
  return c == EOF ;
}

void lexicalError() {
  printf("Error Lexico\n");
}
