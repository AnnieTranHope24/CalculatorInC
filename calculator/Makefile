calc: main.o getop.o stack.o getch.o
	gcc -lm -o calc main.o getop.o stack.o getch.o
main.o: main.c getop.o stack.o calc.h
	gcc -c main.c
getop.o: getop.c calc.h
	gcc -c getop.c
stack.o: stack.c calc.h
	gcc -c stack.c
getch.o: getch.c
	gcc -c getch.c
clean:
	rm -f *.o
	rm -f calc
