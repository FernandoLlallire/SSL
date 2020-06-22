#include "String.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void){
    //Testeamos el GetLength
    printf("Testeamos GetLength\n");
    assert(GetLength("mockString") == 10);
    //Testeamos el IsEmpty
    printf("Testeamos IsEmpty\n");
    assert(IsEmpty("mockString") == false);
    assert(IsEmpty("") == true);
    //Testeamos el Power
    printf("Testeamos Power\n");
    assert(strcmp(Power("mockString",2), "mockStringmockString") == 0);
    assert(strcmp(Power("mockString",2), "anotherMock") != 0);
    //Testeamos el Concat
    printf("Testeamos Concat\n");
    assert(strcmp(Concat("mock","String"), "mockString") == 0);
    assert(strcmp(Concat("mock","String"), "anotherMock") != 0);
}