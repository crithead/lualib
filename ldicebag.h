#ifndef LDICEBAG_H
#define LDICEBAG_H
/*
 * The Lua library interface to the dicebag library.
 */

#include "ldicebag.h"

/**
 * Open dicebag library
 */
extern LUAMOD_API int luaopen_dicebag( lua_State *L ) {
    luaL_newlib( L, dicebaglib );
    return 1;
}

#endif // LDICEBAG_H

