CFLAGS=-lsqlite3

all: sqlite ship.sqlite3
clean:
	@rm -R sqlite ship.sqlite3
sqlite: sqlite.c
ship.sqlite3: data.sql
	sqlite3 ship.sqlite3 < data.sql
