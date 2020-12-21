calc:
	gcc calc.c scanner.c parser.c -o calc
delete:
	rm -f calc.o parser.o scanner.o
run: calc delete
	./calc < test > ouput


# https://opensource.com/article/18/8/what-how-makefile
# https://stackoverflow.com/questions/13919505/how-to-build-multiple-targets-from-one-makefile