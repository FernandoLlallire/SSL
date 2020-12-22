exec:
	rm -f calc
	gcc calc.c scanner.c parser.c semantic.c -o calc
delete:
	rm  -f calc.o parser.o scanner.o semantic.o output
flex: bison
	rm -f scanner.c
	flex -l -o scanner.c scanner.l
bison:
	rm -f parserTokens.h
	bison -o parser.c parser.y --defines=parserTokens.h
run: bison flex exec delete
	./calc < test > ouput

# https://www.thegeekstuff.com/2012/10/gcc-compiler-options/
# https://opensource.com/article/18/8/what-how-makefile
# https://stackoverflow.com/questions/13919505/how-to-build-multiple-targets-from-one-makefile

# https://opensource.com/article/18/8/what-how-makefile
# https://stackoverflow.com/questions/13919505/how-to-build-multiple-targets-from-one-makefile
# como compilar flex
# https://stackoverflow.com/questions/778431/how-do-i-use-c-in-flex-and-bison