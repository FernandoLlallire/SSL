#include <stdio.h>
#include <stdlib.h>

int main() {
FILE *fp;

fp=fopen("output.txt", "w");
if(fp == NULL)
    exit(-1);
fprintf(fp, "Hello, World!\n");
fclose(fp);
return 0;
}