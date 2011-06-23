#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int l_pow(lua_State *L)
{
	double x = lua_tonumber(L, 1);
	double y = lua_tonumber(L, 2);
	lua_pushnumber(L, pow(x, y));
	return 1;
}

static int l_favorite_number(lua_State *L)
{
	lua_pushnumber(L, 42);
	return 1;
}

static const struct luaL_Reg powlib [] = {
	{"pow", l_pow}, {"favorite_number", l_favorite_number},
	{NULL, NULL}
};

int luaopen_pow(lua_State *L)
{
	luaL_register(L, "powlib", powlib);
	return 1;
}
