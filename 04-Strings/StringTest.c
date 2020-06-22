#include "String.h"
#include <assert.h>

int main(void){
    //Testeamos el GetLength
    assert(GetLength("mockString") == 10);
    //Testeamos el IsEmpty
    assert(IsEmpty("mockString") == false);
    assert(IsEmpty("") == true);
    //Testeamos el Power
    assert(Power("mockString",2) == "mockStringmockString");
    fprintf("%s", Power("yanina es asu !", 5));
}