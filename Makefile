

CFLAGS= -Wall -pedantic -g

.PHONY: all
	all: self-linker

self-linker: self-linker.o
	gcc -o $@ $^ -ldl

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -f self-linker self-linker.o
