#include "parser.h"

int sintaxError = false;
int isExpresionInsideParentesis = false;

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
        listOfSentences();
        Match(tokens_fdt);
        return;
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
            printf("variable $%s = %d\n", getLexema(), getVariable(getLexema()));
        }
    }

    return;
}

//expreson = value1 + value2
int expresion() {
    Tokens expresionToken;
    int value1;
    value1 = termino();
    expresionToken = GetNextToken();
    if (expresionToken == tokens_right_bracket && isExpresionInsideParentesis) {
        isExpresionInsideParentesis = false;
        return value1; // para devolver el valor que tiene la expresion
    }
    if (expresionToken == tokens_new_line) {
       /* 
        Si hay un \n se lo devuelve al stream de stdin para que 
        listOfCentences llame a centence()
       */
        ungetc('\n', stdin);
        return value1;
    } else if (expresionToken == tokens_add) {
        int valor2= expresion();
        return value1 + valor2;
    } else if (expresionToken == tokens_fdt) {
        ungetc(EOF, stdin);         
        return value1;
    }else {
        sintaxError = true;
    }
}

//termino = value1 * value2
int termino() {
    Tokens expresionToken;
    int value1;
    value1 = factor();
    expresionToken = GetNextToken();
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
    } else if (expresionToken == tokens_fdt) {
        ungetc(EOF, stdin);
        return value1;
    } else if (expresionToken == tokens_multiply) {
        return value1 * termino();
    } else if (expresionToken == tokens_right_bracket && isExpresionInsideParentesis) {
        /*
        Necesario para propagar el final del termino en parentesis
        */
        ungetc(')', stdin);
        return value1;        
    } else {
        sintaxError = true;
    }
}

//termino = numero | identificador | (Expresion)
int factor() {
    Tokens expresionToken = GetNextToken();
    if(isExpresionInsideParentesis) {
        /*
        Logica necesaria para poder diferenciar cuando es un 
        parentesis y tenemos que devolver el valor de la expresion.
        esto es al terminar el termino en parentesis
        */
        if (expresionToken == tokens_right_bracket) {
            isExpresionInsideParentesis = false;
            expresionToken = updateToken();
        }
    } else if (expresionToken == tokens_new_line) {
        ungetc('\n', stdin);
        return 0;
    } else if (expresionToken == tokens_fdt) {
        ungetc(EOF, stdin);
    }
    if (expresionToken == tokens_number) {
        return atoi(getLexema());
    } else if (expresionToken == tokens_identifier) {
        return getVariable(getLexema());
    } else if (expresionToken == tokens_left_bracket) {
        /*
        Aca vamos a ver el manejo de parentesis el cual cierra el ciclo con la expresion
        */
        isExpresionInsideParentesis = true;
        int resultado = expresion();
        return resultado;
    } else {
        sintaxError = true;
        printf("Error en factor\n");
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

Tokens updateToken(){
    if(isdigit(getLexema())) {
        return tokens_number; 
    } else if (isalpha(getLexema())) {
        return tokens_identifier;
    }
}