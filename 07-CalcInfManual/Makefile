exec:
	rm -f calc
	gcc calc.c scanner.c parser.c semantic.c -o calc
delete:
	rm  -f calc.o parser.o scanner.o ouput
run: exec delete
	./calc < test > ouput

# https://www.thegeekstuff.com/2012/10/gcc-compiler-options/
# https://opensource.com/article/18/8/what-how-makefile
# https://stackoverflow.com/questions/13919505/how-to-build-multiple-targets-from-one-makefile