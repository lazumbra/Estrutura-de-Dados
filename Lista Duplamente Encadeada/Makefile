main: main.o listDuplaEnc.o
	gcc main.o listDuplaEnc.o -o listDuplaEnc

main.o: main.c
	gcc -c main.c

listaDulpEncad.o: listDuplaEnc.c listDuplaEnc.h
	gcc -c listDuplaEnc.c

clean:
	rm *.o listDuplaEnc