
TRACE=NODEBUG

LOADLIBS=-L $(GLPK)/lib -lglpk -lm
cflags= -c -D_REENTRANT -g -Wall -I $(GLPK)/include -D$(TRACE)

compile = gcc

program = rcp

csources = $(program).c

cobjects = $(csources:.c=.o)


$(program): $(cobjects)
	$(compile) -o $(program) $(cobjects) $(LOADLIBS)

.c.o: 
	$(compile) -o $@ $*.c $(cflags)

clean:
	rm *.o
	rm *.lp
