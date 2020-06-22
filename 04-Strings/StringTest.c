#include "String.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void){
    //Testeamos el GetLength
    assert(GetLength("mockString") == 10);
    //Testeamos el IsEmpty
    assert(IsEmpty("mockString") == false);
    assert(IsEmpty("") == true);
    //Testeamos el Power
    assert(strcmp(Power("mockString",2), "mockStringmockString") == 0);
    assert(strcmp(Power("mockString",2), "anotherMock") != 0);
    //Testeamos el Concat
    assert(strcmp(Concat("mock","String"), "mockString") == 0);
    assert(strcmp(Concat("mock","String"), "anotherMock") != 0);
}