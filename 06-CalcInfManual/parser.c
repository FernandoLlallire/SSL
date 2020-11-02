#include "parser.h"

int parser(){
    ParserState state = parser_init;
    Result result;
    Tokens token;
    while((token = GetNextToken()) != tokens_fdt) {
        switch (state) {   
            case parser_init:
                if( token == tokens_number || token == tokens_character ) {
                    state = setStatus(token);
                    result = result_ok;
                } else {
                        state = parser_error;
                        return result_fail;
                }
                break;
            case parser_character:
            case parser_number:
                if( token == tokens_add || token == tokens_multiply) {
                    state = parser_operation;
                    result = result_ok;
                } else {
                    state = parser_error;
                    return result_fail;
                }
                break;
            case parser_operation:
                if( token == tokens_number || token == tokens_character ) {
                    state = setStatus(token);
                    result = result_ok;
                } else {
                        state = parser_error;
                        return result_fail;
                }
                break;
            default:
            if (token == tokens_invalid)
                return result_fail;
            break;
        }
    }
    return result;
}

ParserState setStatus(Tokens token){
    if (token == tokens_number) {
        return parser_number;
    }
       return parser_character;
}