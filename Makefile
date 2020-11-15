timer: timer.c
	gcc -o timer -Wall -O3 timer.c

.PHONY: install

install: timer
	mv timer /usr/bin/
