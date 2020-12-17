#include "parser.h"

int parser(){
    listOfSentences();
}

/**
 * Este es el GIC con el que trabajamos para el analisis sintactico, ver index.md
*/
void listOfSentences() {
    Tokens nextToken;
    sentence();
    nextToken = GetNextToken();
    //Si solo es una linea de texto
    if( nextToken == tokens_fdt) {
        return;
    }
    else if (nextToken == tokens_new_line) {
        sentence();
        Match(tokens_fdt);
    }
}

void sentence() {
    char identifier[lexemaSize];
    int number;
    sintaxError = false; //
    Tokens nextToken = GetNextToken();
    // a = lista de expresiones -> asignacion
    if (nextToken == tokens_identifier) {
        strcpy(identifier, getLexema());
        Match(tokens_equals);
        //Match(tokens_number);
        number = expresion();
        if(sintaxError) {
            printf("Error en la sintaxis");
            return; 
        }
        addVariable(identifier, number);
        printf("Variable %s asignada con el valor %d", identifier, number);
        return;
    }
    // $a -> mmuestra el valor
    if(nextToken == tokens_interpreter) {
        Match(tokens_identifier);
        printf("variable $%s = %d", getLexema(), getVariable(getLexema()));
    }

    return;
}

//expreson = value1 + value2
int expresion() {
    Tokens expresionToken;
    int value1;
    value1 = termino();
    expresionToken = GetNextToken();
    /* Si hay un \n se lo devuelve al stream de stdin para que 
       listOfCentences llame a centence()*/
    if (expresionToken == tokens_new_line) {
        ungetc('\n', stdin);
        return value1;
    } else if (expresionToken == tokens_add) {
        return value1 + expresion();
    /* Si hay un end of file se devuelve EOF al stream de stdin para que 
       podamos devolver el resultado previo y que listOfCentences se encargue de 
       manejar ese token*/
    } else if (expresionToken == tokens_fdt) {
        ungetc(EOF, stdin);
        return value1;
    } else {
        sintaxError = true;
    }
}

//termino = value1 * value2
int termino() {
    Tokens expresionToken;
    int value1;
    value1 = factor();
    expresionToken = GetNextToken();
    /* Si hay un \n se lo devuelve al stream de stdin para que 
       listOfCentences llame a centence()*/
    if (expresionToken == tokens_new_line) {
        ungetc('\n', stdin);
        return value1;
    } else if (expresionToken == tokens_multiply) {
        return value1 * expresion();
    /* Si hay un end of file se devuelve EOF al stream de stdin para que 
       podamos devolver el resultado previo y que listOfCentences se encargue de 
       manejar ese token*/
    } else if (expresionToken == tokens_fdt) {
        ungetc(EOF, stdin);
        return value1;
    } else {
        sintaxError = true;
    }
}

//termino = numero | identificador | (Expresion)
int factor() {
    Tokens expresionToken = GetNextToken();
    if (expresionToken == tokens_number) {
        return atoi(getLexema());
    } else if (expresionToken == tokens_identifier) {
        return getVariable(getLexema());
    } else if (expresionToken == tokens_left_bracket) {
        expresion();
        Match(tokens_right_bracket);
    } else {
        sintaxError = true;
        if (expresionToken == tokens_new_line) {
            ungetc('\n', stdin);
        } else if (expresionToken == tokens_fdt) {
            ungetc(EOF, stdin);
        }
        return 0;
    }
}

void Match(Tokens token) {
    if(token == GetNextToken()) {
        return;
    }
    sintaxError = true;
    return;
}
ParserState setStatus(Tokens token){
    if (token == tokens_number) {
        return parser_number;
    }
       return parser_character;
}
