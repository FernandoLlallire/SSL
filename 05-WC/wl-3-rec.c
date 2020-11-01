#include <stdio.h>

void in(void);
void out(void);

int main()
{
  out();
}


void out(void)
{
    char c;
    if((c = getchar()) != EOF){
        if( c == '\n' || c == ' ' || c == '\t'){
            out();
        } else {
            putchar(c);
            in();
        }
    }
}

void in(void)
{
    char c;
    if((c = getchar()) != EOF){
        if( c == '\n' || c == ' ' || c == '\t'){
            putchar('\n');
            out();
        } else {
            putchar(c);
            in();
        }
    }
}