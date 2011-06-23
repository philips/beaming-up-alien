#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static const luaL_reg lualibs[] = {
	{ "base", luaopen_base }, { NULL, NULL }
};

static void lualibs_open(lua_State *l)
{
	const luaL_reg *lib;

	for (lib = lualibs; lib->func != NULL; lib++) {
		lib->func(l);
		lua_settop(l, 0);
	}
}

static double param_get_double(lua_State *l, const char *key)
{
	double d;

	lua_getfield(l, -1, key);
	if (!lua_isnumber(l, -1))
		luaL_error(l, "’x is not a number");
	d = (double)lua_tonumber(l, -1);
	lua_pop(l, 1);
	return d;
}

int main(void)
{
	int i;
	double x, y;
	lua_State *l;
	l = lua_open();
	lualibs_open(l);

	i = luaL_loadfile(l, "config.lua");
	lua_pcall(l, 0, 0, 0);

	lua_getglobal(l, "params");
	if (!lua_istable(l, -1))
		luaL_error(l, "’params is not a table");
	
	x = param_get_double(l, "x");
	y = param_get_double(l, "y");

	printf("%f\n", pow(x, y));

	lua_close(l);

	return 0;
}
