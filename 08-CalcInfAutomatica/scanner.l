%{

#include "scanner.h"
int index_scaner = 0;

char lexema[lexemaSize];
bool flagToken = true;
//por que no puedo hacer ungetlexx del EOF
bool isEOF = false;
%}

number  [0-9]+
identifier [A-Za-z][0-9A-Za-z]*

%option noyywrap
%%
<<EOF>>         {
    isEOF = true;
    return tokens_fdt;
}
{identifier}    {
    writeLexema(yytext);
    return tokens_identifier;
}
{number}        {
    writeLexema(yytext);
    return tokens_number;
}
\*               {
    writeLexema(yytext);
    return tokens_multiply;  
}
\+               {
    writeLexema(yytext);
    return tokens_add;  
}
\(               {
    writeLexema(yytext);
    return tokens_left_bracket;  
}
\)               {
    return tokens_right_bracket;  
}
\n               {
    return tokens_new_line;  
}
[ \t]            ;
=               {
    return tokens_equals;  
}
\$               {
    return tokens_interpreter;  
}
.                {
    if (isEOF) {
        return tokens_fdt;
    }
    printf("Error Lexico: caracter invalido %s\n", yytext);
    printf("value: %d\n", (int) yytext[0]);
    return tokens_invalid;
}
%%

/*
https://josemariasola.github.io/reference/Lex%20-%20A%20Lexical%20Analyzer%20Generator%20(1975).pdf
{definitions}
%%
{rules}
%%
{user subroutines}
*/

Tokens GetNextToken() {
  return yylex();
}

void writeLexema(char* text) {
  strcpy(lexema,text);
}

char * getLexema() {
  return lexema;
}

void ungetLex(char c) {
    unput(c);
}
