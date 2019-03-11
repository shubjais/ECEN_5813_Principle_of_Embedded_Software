edit: main.o help.o exit.o allocate.o free.o displaymem.o writemem.o invert.o writepattern.o verifypattern.o
	cc -o edit main.o help.o exit.o allocate.o free.o displaymem.o writemem.o invert.o writepattern.o verifypattern.o

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

displaymem.o: displaymem.c displaymem.h allocate.h
	cc -c displaymem.c

writemem.o: writemem.c writemem.h allocate.h
	cc -c writemem.c

invert.o: invert.c invert.h allocate.h
	cc -c invert.c

writepattern.o: writepattern.c writepattern.h allocate.h 
	cc -c writepattern.c

verifypattern.o: verifypattern.c verifypattern.h allocate.h writepattern.h
	cc -c verifypattern.c

test: edit test.txt
	./edit < test.txt

clean: 
	rm edit main.o help.o exit.o allocate.o free.o displaymem.o writemem.o invert.o writepattern.o verifypattern.o
