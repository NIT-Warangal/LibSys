//

//------------------------------------------------------------------------------
#ifndef LuaScriptManLibH
#define LuaScriptManLibH
//------------------------------------------------------------------------------

#if LUA_VERSION_NUM > 501
    int RegScriptMan(lua_State *L);
#else
    void RegScriptMan(lua_State * L);
#endif
//------------------------------------------------------------------------------

#endif
