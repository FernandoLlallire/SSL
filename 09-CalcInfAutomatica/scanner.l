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
    strcpy(yylval.identifier, yytext);
    return tokens_identifier;
}
{number}        {
    yylval.number=atoi(yytext);
    return tokens_number;
}
\*               {
    return tokens_multiply;  
}
\+               {
    return tokens_add;  
}
\(               {
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

//int GetNextToken() {
//  return yylex();
//}

void ungetLex(char c) {
    unput(c);
}
