calc:
	gcc calc.c scanner.c parser.c -o calc
delete:
	rm -f calc.o parser.o scanner.o
run: calc delete
	./calc < test > ouput
	