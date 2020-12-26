%{

#include "parser.h"

int sintaxError = false;
int isExpresionInsideParentesis = false;
void yyerror(char const *s){printf ("Error in parser: %s", s);}
extern int yylex();

%}
%union{
    int number;
    char identifier[100];
}

%start Lista_de_sentencias

%token <number>        tokens_add
%token <identifier>    tokens_identifier
%token <number>        tokens_fdt 0
%token <number>        tokens_invalid
%token <number>        tokens_multiply
%token <number>        tokens_number
%token <number>        tokens_lexicalError
%token <number>        tokens_left_bracket
%token <number>        tokens_right_bracket
%token <number>        tokens_equals
%token <number>        tokens_interpreter
%token <number>        tokens_new_line

%type  <number>        Lista_de_sentencias
%type  <number>        Sentencia
%type  <number>        Expresion
%type  <number>        Termino
%type  <number>        Factor
%%

Lista_de_sentencias: Sentencia tokens_fdt
| Sentencia tokens_new_line Lista_de_sentencias tokens_fdt
;

Sentencia: tokens_interpreter tokens_identifier {printf("variable $%s = %d\n", $2, getVariable($2));}
| tokens_identifier tokens_equals Expresion { addVariable($1, $3);
                                              printf("Variable %s asignada con el valor %d\n", $1, $3);} 
;

Expresion: Termino {$$ = $1;}
| Termino tokens_add  Expresion {$$ = $1 + $3;}
;

Termino: Factor {$$ = $1;}
| Factor tokens_multiply Termino {$$ = $1 * $3;}
;

Factor: tokens_number {$$ = $1;}
| tokens_identifier {$$ = getVariable($1);}
| tokens_left_bracket Expresion tokens_right_bracket {$$ = $2;}
;

%%

//static int yylex(void){   
//    return GetNextToken();
//}

//void parser(){
//  yyparse();
//}
