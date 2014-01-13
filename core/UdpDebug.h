//

//---------------------------------------------------------------------------
#ifndef UdpDebugH
#define UdpDebugH
//---------------------------------------------------------------------------
struct User;
//---------------------------------------------------------------------------

class clsUdpDebug {
private:
    struct UdpDbgItem {
        UdpDbgItem();
        ~UdpDbgItem();

#ifdef _WIN32
        SOCKET s;
#else
		int s;
#endif
        sockaddr_storage sas_to;
        int sas_len;

        uint32_t ui32Hash;
        char *Nick;

        UdpDbgItem *prev, *next;
        bool bIsScript;
    };

public:
    static clsUdpDebug * mPtr;

    UdpDbgItem *llist, *ScriptList;

	clsUdpDebug();
	~clsUdpDebug();

	void Broadcast(const char * msg) const;
	void Broadcast(const char * msg, const size_t &szLen) const;
    void Broadcast(const string & msg) const;
	bool New(User *u, const int32_t &port);
	bool New(char * sIP, const uint16_t &usPort, const bool &bAllData, char * sScriptName);
	bool Remove(User * u);
	void Remove(char * sScriptName);
	bool CheckUdpSub(User * u, bool bSndMess = false) const;
	void Send(char * sScriptName, char * sMsg, const size_t &szLen) const;
	void Cleanup();
};
//---------------------------------------------------------------------------

#endif
