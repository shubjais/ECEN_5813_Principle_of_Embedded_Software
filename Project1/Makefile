edit: main.o help.o
	  cc -o edit main.o help.o

main.o: main.c help.h
		cc -c main.c

help.o: help.c help.h
		cc -c help.c

clean: 
		rm edit main.o help.o
