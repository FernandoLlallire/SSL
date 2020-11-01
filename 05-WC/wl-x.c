#include <stdio.h>

#define condicion ((c=='\n')||(c=='\t')||(c==' '))
#define in 1
#define out 0

int main(void){
    int estado=out;
    char c;
    while( (c=getchar()) != EOF){
        if(estado == in){
            if(condicion){
                putchar('\n');
                estado=out;
            } else {
                putchar(c);
            }
        } else {
            if(condicion){
                break;
            } else {
                estado=in;
            }
        }
    }
}