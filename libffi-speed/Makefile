CFLAGS=-lffi -g

all: ffi linked
clean:
	@-rm -R ffi linked *.dSYM output
ffi: ffi.c times.h
linked: linked.c times.h

run: all
	./run
.PHONY: run
