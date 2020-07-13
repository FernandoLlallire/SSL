#include <stdio.h>

typedef enum  {IN,OUT} State;

int main(void){
    int c,nl,nw,nc;
    State s = OUT;
    nl=nw=nc=0;

    while ((c = getchar())!= EOF){
        ++nc;
        switch (c){
            case '\n':
                ++nl;
                s = OUT;
            break;
            case ' ':
                s = OUT;
            break;
            case '\t':
                s = OUT;
            break;
            default:
                if (s == OUT){
                    ++nw;
                    s = IN;
                }
            break;
        }
    }
   printf("Lines: %d, Words: %d Characters: %d\n",nl,nw,nc);
}
