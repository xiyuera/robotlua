#include "robotlua.h"

/**
 * mouse functions
 */
static const luaL_Reg robotlua_mouse_functions[] = {
	{NULL, NULL}
};

/**
 * keyboard functions
 */
static const luaL_Reg robotlua_keyboard_functions[] = {
	{NULL, NULL}
};

/**
 * screen functions
 */
static const luaL_Reg robotlua_screen_functions[] = {
	{NULL, NULL}
}

/**
 * inject mouse functions
 */
static void robotlua_mouse_init(lua_State *L) {
	lua_pushstring(L, "mouse")
	luaL_newlib(L, robotlua_mouse_functions);
	lua_rawset(L, -3)
}

/**
 * inject keyboard functions
 */
static void robotlua_keyboard_init(lua_State *L) {
	lua_pushstring(L, "keyboard");
	luaL_newlib(L, robotlua_keyboard_functions);
	lua_rawset(L, -3);
}

/**
 * inject screen functions
 */
static void robotlua_screen_init(lua_State *L) {
	lua_pushstring(L, "screen");
	luaL_newlib(L, robotlua_screen_functions);
	lua_rawset(L, -3);
}

/**
 * robotlua lua open
 */
LUALIB_API int luaopen_robotlua (lua_State *L) {
	lua_createtable(L, 0, 2);

	robotlua_mouse_init(lua_State *L);
	robotlua_keyboard_init(lua_State *L);
	robotlua_screen_init(lua_State *L);

	return 1;
}