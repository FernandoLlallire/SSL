#include "parser.h"

int sintaxError = false;


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
    printf("Estoy iniciando una nueva sentencia\n");
    Tokens nextToken = GetNextToken();
    // a = lista de expresiones -> asignacion
    if (nextToken == tokens_identifier) {
        strcpy(identifier, getLexema());
        Match(tokens_equals);
        //Match(tokens_number);
        number = expresion();
        if(sintaxError) {
            printf("Error en la sintaxis \n");
            return; 
        }
        addVariable(identifier, number);
        printf("Variable %s asignada con el valor %d\n", identifier, number);
        return;
    }
    // $a -> mmuestra el valor
    if(nextToken == tokens_interpreter) {
        Match(tokens_identifier);
        int value = getVariable(getLexema());
        if(value != -1) {
            printf("variable $%s = %d", getLexema(), getVariable(getLexema()));
        }
    }

    return;
}

//expreson = value1 + value2
int expresion() {
    printf("Entre a trabjar en la expresion \n");
    Tokens expresionToken;
    int value1;
    value1 = termino();
    printf("despues del termino() en expresion()\n");
    expresionToken = GetNextToken();
    /* Si hay un \n se lo devuelve al stream de stdin para que 
       listOfCentences llame a centence()*/
       printf("valor del token %d\n", expresionToken);
    if (expresionToken == tokens_new_line) {
        ungetc('\n', stdin);
        return value1;
    } else if (expresionToken == tokens_add) {
        int valor2= expresion();
        printf("Expresion retorna el valor compuesto %d + %d\n", value1, valor2);
        return value1 + valor2;
    /* Si hay un end of file se devuelve EOF al stream de stdin para que 
       podamos devolver el resultado previo y que listOfCentences se encargue de 
       manejar ese token*/
    } else if (expresionToken == tokens_fdt) {
        ungetc(EOF, stdin);
        printf("Expresion retorna el valor %d por que llego un fdt\n", value1);
        return value1;
    } else if(expresionToken == tokens_right_bracket){
        printf("Expresion detecto un ) en stdin\n");
        ungetc(')', stdin);
        printf("Expresion retorna el valor %d por que le llego un ')'\n", value1);
        return value1;
    }else {
        sintaxError = true;
    }
}

//termino = value1 * value2
int termino() {
    printf("Entre a trabajar en el termino\n");
    Tokens expresionToken;
    int value1;
    value1 = factor();
    expresionToken = GetNextToken();
    /* Si hay un \n se lo devuelve al stream de stdin para que 
       listOfCentences llame a centence()*/
    if (expresionToken == tokens_new_line) {
        ungetc('\n', stdin);
        return value1;
        /*
        El preoblema es que como agarro un caracter el signo mas lo estaba sacando
        */
    } else if (expresionToken == tokens_add){
        ungetc('+', stdin);
        return value1;
    } else if (expresionToken == tokens_interpreter){
        ungetc('$', stdin);
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
    printf("Entre a trabajar en el factor\n");
    Tokens expresionToken = GetNextToken();
    if (expresionToken == tokens_number) {
        printf("factor devuelve el numero %s\n", getLexema());
        return atoi(getLexema());
    } else if (expresionToken == tokens_identifier) {
       printf("devuefactor devuelvelvp VARIABLE\n");
        return getVariable(getLexema());
    } else if (expresionToken == tokens_left_bracket) {
        printf("factor devuelve (\n");
        int resultado = expresion();
        printf("El resultado del parentesis es  = %d\n", resultado);
        Match(tokens_right_bracket);
        return sintaxError? : resultado;
    } else {
        sintaxError = true;
        if (expresionToken == tokens_new_line) {
            ungetc('\n', stdin);
        } else if (expresionToken == tokens_fdt) {
            ungetc(EOF, stdin);
        } else if (expresionToken == tokens_right_bracket) {
            ungetc(')', stdin);
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
