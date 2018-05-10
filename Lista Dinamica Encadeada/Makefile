main:	main.o 	listaDinEncad.o
	gcc main.o listaDinEncad.o -o execLista

main.o: main.c
	gcc -c main.c

listaDinEncad.o: listaDinEncad.c listaDinEncad.h
	gcc -c listaDinEncad.c

clean:
	rm *.o execLista