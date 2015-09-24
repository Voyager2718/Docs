cc = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500

maccess+:maccess+.o
	$(cc) -o $@ $^

maccess+.o:maccess+.c
	$(cc) $(CFLAGS) -c maccess+.c

maccess:maccess.o
	$(cc) -o $@ $^

maccess.o:maccess.c
	$(cc) $(CFLAGS) -c macces.c






clean:
	$(RM) *.o

