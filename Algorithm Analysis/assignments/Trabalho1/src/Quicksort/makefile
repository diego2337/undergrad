TRACE=DEBUG

LOADLIBS=-L -lm
cflags= -c -D_REENTRANT -g -Wall -I -D$(TRACE) -pedantic -std=c99

compile = gcc

program = quick

csources = $(program).c

cobjects = $(csources:.c=.o)


$(program): $(cobjects)
	$(compile) -o $(program)-$(TRACE) $(cobjects) $(LOADLIBS)

.c.o: 
	$(compile) -o $@ $*.c $(cflags)

clean:
	rm *.o
