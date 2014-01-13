//

//------------------------------------------------------------------------------
#ifndef LuaProfManLibH
#define LuaProfManLibH
//------------------------------------------------------------------------------

#if LUA_VERSION_NUM > 501
    int RegProfMan(lua_State *L);
#else
    void RegProfMan(lua_State * L);
#endif
//------------------------------------------------------------------------------

#endif
