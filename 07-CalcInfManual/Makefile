exec:
	rm -f calc
	gcc calc.c scanner.c parser.c semantic.c -o calc
delete:
	rm  -f calc.o parser.o scanner.o ouput
run: exec delete
	./calc < test > ouput
