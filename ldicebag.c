/*
 * The Lua library interface to the dicebag library.
 */

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "dicebag.h"

static int l_dicebag_roll( lua_State *L ) {
    lua_pushinteger( L, dicebag_roll( luaL_checkinteger( L, 1 ) ) );
    return 1;
}

static int l_dicebag_range( lua_State *L ) {
    lua_pushinteger( L, dicebag_range( luaL_checkinteger( L, 1 ),
                                       luaL_checkinteger( L, 2 ) ) );
    return 1;
}

static int l_dicebag_dice( lua_State *L ) {
    lua_pushinteger( L, dicebag_dice( luaL_checkinteger( L, 1 ),
                                      luaL_checkinteger( L, 2 ) ) );
    return 1;
}

static int l_dicebag_best( lua_State *L ) {
    lua_pushinteger( L, dicebag_best( luaL_checkinteger( L, 1 ),
                                      luaL_checkinteger( L, 2 ),
                                      luaL_checkinteger( L, 3 ) ) );
    return 1;
}

static const luaL_Reg dicebaglib[] = {
    { "roll",  l_dicebag_roll },
    { "range", l_dicebag_range },
    { "dice",  l_dicebag_dice },
    { "best",  l_dicebag_best },
    { NULL,    NULL },
};
 
/*
 * Open dicebag library
 */
LUAMOD_API int luaopen_dicebag( lua_State *L ) {
#if 0
	luaL_newlib( L, dicebaglib );
#else
	luaL_newlibtable( L, dicebaglib );
	luaL_setfuncs( L, dicebaglib, 0 );
	/* Initialize the library when it is loaded */
	dicebag_init();
#endif //0
    return 1;
}

