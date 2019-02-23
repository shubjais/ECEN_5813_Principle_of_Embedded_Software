edit: main.o help.o exit.o allocate.o free.o
	  cc -o edit main.o help.o exit.o allocate.o free.o

main.o: main.c main.h help.h exit.h allocate.h free.h
		cc -c main.c

help.o: help.c help.h
		cc -c help.c
		
exit.o: exit.c exit.h
		cc -c exit.c
		
allocate.o: allocate.c allocate.h
			cc -c allocate.c
			
free.o: free.c free.h allocate.h
		cc -c free.c
clean: 
		rm edit main.o help.o exit.o allocate.o free.o
