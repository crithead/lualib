/*
 * The Lua library interface to the dicebag library.
 */

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "dicebag.h"

static int l_dicebag_init( lua_State *L ) {
    dicebag_init();
    return 0;
}

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
    { "init",  l_dicebag_init },
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
#endif //0
/* How do I get a reference to the loaded library in the the global namespace
 * without manually putting it there?
 *
 * Can I put ia reference in the global namespace that points to
 * "_G.package.loaded.dicebag" ?
 */
    return 1;
}

