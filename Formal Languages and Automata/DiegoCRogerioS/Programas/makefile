parser: lex.o parser.o
	gcc parser.o lex.o -g -o parser
lex.o: lex.h lex.c
	gcc -c lex.c -g
parser.o: parser.h parser.c
	gcc -c parser.c -g
