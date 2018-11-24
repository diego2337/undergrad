CFLAGS= -Wall -std=c99 -pedantic

all:	clean
	gcc checkin.c hotel.c -o checkin $(CFLAGS)
	gcc checkout.c hotel.c -o checkout $(CFLAGS)
	gcc pesquisar.c hotel.c -o pesquisar $(CFLAGS)
	gcc listar_quartos.c hotel.c -o listar_quartos $(CFLAGS)

clean:
	rm -rf checkin checkout pesquisar listar_quartos

