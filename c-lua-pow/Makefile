MACOSX_DEPLOYMENT_TARGET="10.6"

CFLAGS=-lm -llua

LIB=pow.so
OBJ=pow.o
SRC=pow.c

all: pow.c
	$(CC) -O2 -fno-common -c -o $(OBJ) $(SRC)
	$(CC) -bundle -Wl,-bind_at_load -undefined dynamic_lookup -o $(LIB) $(OBJ)

clean:
	@-rm $(LIB) $(OBJ)
.PHONY: clean
