#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char **argv) {
	sqlite3 *conn;
	sqlite3_stmt *res;
	int err = 0, cnt = 0;
	const char *err_msg;
	const char *tail;

	err = sqlite3_open("ship.sqlite3", &conn);
	if (err) {
		printf("Can not open database\n");
		return 1;
	}

	err = sqlite3_exec(conn,
			     "update ship set name=\'NCC-1701-D\' where id=3",
			     0, 0, 0);

	err = sqlite3_prepare_v2(conn,
				   "select id,name from ship order by id",
				   1000, &res, &tail);

	if (err != SQLITE_OK) {
		printf("Select failed");
		return 1;
	}

	while (sqlite3_step(res) == SQLITE_ROW) {
		printf("%u ", sqlite3_column_int(res, 0));
		printf("%s\n", sqlite3_column_text(res, 1));
		cnt++;
	}

	sqlite3_finalize(res);

	sqlite3_close(conn);

	return 0;
}
