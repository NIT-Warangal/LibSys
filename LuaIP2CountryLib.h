//------------------------------------------------------------------------------
#ifndef LuaIP2CountryLibH
#define LuaIP2CountryLibH
//------------------------------------------------------------------------------

#if LUA_VERSION_NUM > 501
    int RegIP2Country(lua_State *L);
#else
    void RegIP2Country(lua_State * L);
#endif
//------------------------------------------------------------------------------

#endif
