

CFLAGS= -Wall -pedantic

.PHONY: all
	all: self-linker

self-linker: self-linker.o
	gcc -g -o $@ $^ -ldl

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -f self-linker self-linker.o
