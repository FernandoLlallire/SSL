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
        printf("El number en sentence es %d\n", number);
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
    printf("token en expresion es %d\n", expresionToken);
    if(expresionToken == tokens_right_bracket && isExpresionInsideParentesis) {
        isExpresionInsideParentesis = false;
        //int tokenDespuesParentesis = GetNextToken();
        //if (tokenDespuesParentesis == tokens_add) {
          //  ungetc('+', stdin);
            return value1; // para devolver el valor que tiene la expresion
        //}
        //if (tokenDespuesParentesis == tokens_multiply) {
        //    ungetc('*', stdin);
        //    return value1;
       // }
    }
    /* Si hay un \n se lo devuelve al stream de stdin para que 
       listOfCentences llame a centence()*/
       printf("valor del token %d\n", expresionToken);
    if (expresionToken == tokens_new_line) {
        ungetc('\n', stdin);
        return value1;
    } else if (expresionToken == tokens_add) {
        printf("expresion encontro un caracter + y empieza a procesar expresion para obtener otro termino");
        int valor2= expresion();
        printf("Expresion retorna el valor compuesto %d + %d\n", value1, valor2);
        return value1 + valor2;
//    } else if(expresionToken == tokens_right_bracket){
//        printf("Expresion detecto un ) en stdin\n");
//        ungetc(')', stdin);
//        printf("Expresion retorna el valor %d por que le llego un ')'\n", value1);
//        return value1;
    /* Si hay un end of file se devuelve EOF al stream de stdin para que 
       podamos devolver el resultado previo y que listOfCentences se encargue de 
       manejar ese token*/
    } else if (expresionToken == tokens_fdt) {
        ungetc(EOF, stdin);
        printf("Expresion retorna el valor %d por que llego un fdt\n", value1);           
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
    printf("token en termino es %d\n", expresionToken);
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
        return value1 * termino();
    /* Si hay un end of file se devuelve EOF al stream de stdin para que 
       podamos devolver el resultado previo y que listOfCentences se encargue de 
       manejar ese token*/
    } else if (expresionToken == tokens_fdt) {
        ungetc(EOF, stdin);
        return value1;
    } else if(expresionToken == tokens_right_bracket){
        printf("termino detecto un ) en stdin\n");
        ungetc(')', stdin);
        printf("termino retorna el valor %d por que le llego un ')'\n", value1);
        return value1;        
    } else {
        printf("errror de sintaxis en termino\n ");
        sintaxError = true;
    }
}

//termino = numero | identificador | (Expresion)
int factor() {
    printf("Entre a trabajar en el factor\n");
    Tokens expresionToken = GetNextToken();
    printf("token en factor es %d\n", expresionToken);
    if(isExpresionInsideParentesis) {
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
        printf("factor devuelve el numero %s\n", getLexema());
        return atoi(getLexema());
    } else if (expresionToken == tokens_identifier) {
       printf("devuefactor devuelvelvp VARIABLE\n");
        return getVariable(getLexema());
    } else if (expresionToken == tokens_left_bracket) {
        isExpresionInsideParentesis = true;
        printf("factor devuelve (\n");
        int resultado = expresion();
        printf("El resultado del parentesis es  = %d\n", resultado);
        return resultado;
    } else {
        sintaxError = true;
        printf("Error en factor\n");
//        if (expresionToken == tokens_new_line) {
//            ungetc('\n', stdin);
 //       } else if (expresionToken == tokens_fdt) {
 //           ungetc(EOF, stdin);
//        } else if (expresionToken == tokens_right_bracket) {
//            ungetc(')', stdin);
//        }
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