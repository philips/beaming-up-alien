CONSTANTS="/usr/local/lib/luarocks/lib/luarocks/rocks/alien/0.5.0-1/bin/constants"

sqliteh.lua: sqlite3.h
	$(CONSTANTS) sqlite3.h sqlite3-const.c sqliteh.lua
	gcc -o sqlite3-const sqlite3-const.c
	./sqlite3-const
	@rm sqlite3-const.c ./sqlite3-const

clean:
	@rm sqliteh.lua

.PHONY: clean
