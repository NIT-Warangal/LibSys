//

//---------------------------------------------------------------------------
#ifndef LuaScriptH
#define LuaScriptH
//---------------------------------------------------------------------------
struct User;
struct Script;
//---------------------------------------------------------------------------

struct ScriptBot {
    char *sNick;
    char *sMyINFO;
    
    ScriptBot *prev, *next;

    bool bIsOP;

    ScriptBot();
    ~ScriptBot();

    static ScriptBot * CreateScriptBot(char * sNick, const size_t &szNickLen, char * sDescription, const size_t &szDscrLen, char * sEmail, const size_t &szEmailLen, const bool &bOP);
};
//------------------------------------------------------------------------------

struct ScriptTimer {
    static char sDefaultTimerFunc[];

#ifdef _WIN32
    UINT_PTR uiTimerId;
#else
	timer_t TimerId;
#endif

    char * sFunctionName;

    int iFunctionRef;

    ScriptTimer *prev, *next;

    ScriptTimer();
    ~ScriptTimer();

#ifdef _WIN32
    static ScriptTimer * CreateScriptTimer(UINT_PTR uiTmrId, char * sFunctName, const size_t &szLen, const int &iRef);
#else
	static ScriptTimer * CreateScriptTimer(char * sFunctName, const size_t &szLen, const int &iRef);
#endif
};
//------------------------------------------------------------------------------

struct Script {
    enum LuaFunctions {
		ONSTARTUP         = 0x1,
		ONEXIT            = 0x2,
		ONERROR           = 0x4,
		USERCONNECTED     = 0x8,
		REGCONNECTED      = 0x10,
		OPCONNECTED       = 0x20,
		USERDISCONNECTED  = 0x40,
		REGDISCONNECTED   = 0x80,
		OPDISCONNECTED    = 0x100
	};

    uint32_t ui32DataArrivals;

    char * sName;

    lua_State * LUA;

    Script *prev, *next;

    ScriptBot *BotList;

    ScriptTimer *TimerList;

	uint16_t ui16Functions;

    bool bEnabled, bRegUDP, bProcessed;

    Script();
    ~Script();

    static Script * CreateScript(char *Name, const bool &enabled);
};
//------------------------------------------------------------------------------

bool ScriptStart(Script * cur);
void ScriptStop(Script * cur);

int ScriptGetGC(Script * cur);

void ScriptOnStartup(Script * cur);
void ScriptOnExit(Script * cur);

void ScriptPushUser(lua_State * L, User * u, const bool &bFullTable = false);
void ScriptPushUserExtended(lua_State * L, User * u, const int &iTable);

User * ScriptGetUser(lua_State * L, const int &iTop, const char * sFunction);

void ScriptError(Script * cur);

#ifdef _WIN32
    void ScriptOnTimer(const UINT_PTR &uiTimerId);
#else
	void ScriptOnTimer(ScriptTimer * AccTimer);
#endif

int ScriptTraceback(lua_State * L);
//------------------------------------------------------------------------------

#endif
