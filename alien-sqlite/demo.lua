require 'luarocks.loader'
require 'alien'

require 'sqliteh'
local sqlite = alien.load("sqlite3")

sqlite.sqlite3_open:types("int", "string", "pointer")
sqlite.sqlite3_exec:types("int", "pointer", "string", "int", "int", "int")
-- SQLITE_API int sqlite3_exec(
--	sqlite3*,
--	const char *sql,
--	int (*callback)(void*,int,char**,char**),
--	void *,
--	char **errmsg);
sqlite.sqlite3_prepare_v2:types("pointer", "pointer", "string", "int", "pointer", "pointer")
sqlite.sqlite3_step:types("int", "pointer")
sqlite.sqlite3_column_int:types("int", "pointer", "int")
sqlite.sqlite3_column_text:types("string", "pointer", "int")
sqlite.sqlite3_finalize:types("int", "pointer")
sqlite.sqlite3_close:types("int", "pointer")

conn_ptr = alien.buffer(8)
res_ptr = alien.buffer(8)
tail_ptr = alien.buffer(8)

ret = sqlite.sqlite3_open("ship.sqlite3", conn_ptr)
if (ret < 0) then
	print(string.format("open failed: %i", ret))
end
conn = conn_ptr:get(1, "pointer")

ret = sqlite.sqlite3_exec(conn, "update ship set name='NCC-1701-D' where id=3", 0, 0, 0)
if (ret < 0) then
	print(string.format("exec failed: %i", ret))
end

ret = sqlite.sqlite3_prepare_v2(conn, "select id,name from ship order by id", 1000, res_ptr, tail_ptr)

res = res_ptr:get(1, "pointer")
while (sqlite.sqlite3_step(res) == SQLITE_ROW) do
	print(sqlite.sqlite3_column_int(res, 0))
	print(sqlite.sqlite3_column_text(res, 1))
end

sqlite.sqlite3_finalize(res)

sqlite.sqlite3_close(conn)
