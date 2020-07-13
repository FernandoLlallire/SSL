#include <stdio.h>
typedef enum  {IN,OUT} State;
int main() {
  char c = ' ';
  int nc, nw, nl;
  nc = nw = nl = 0;
  State s = OUT;

  out:
    if((c = getchar()) != EOF) {
      ++nc;
      if(c == '\n')
        ++nl;
      if (c == ' ' || c == '\n' || c == '\t') {
        goto out;
      } else {
        goto in;
      }
    }
    goto end;

  in:
    if(s = OUT){
      s = IN;
      ++nw;
    }
    goto out;

  end:
    printf("Lines: %d, Words: %d Characters: %d\n",nl,nw,nc);
}
