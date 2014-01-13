// linuxdcpp headers. Extracted from Linuxdcpp

//---------------------------------------------------------------------------
#ifndef DcCommandsH
#define DcCommandsH
//---------------------------------------------------------------------------
struct User;
struct PrcsdUsrCmd;
struct PassBf;
//---------------------------------------------------------------------------

class clsDcCommands {
private:
    PassBf * PasswdBfCheck;
    char msg[1024];
    
	void BotINFO(User * curUser, char * sData, const uint32_t &iLen);
    void ConnectToMe(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck, const bool &bMulti);
	void GetINFO(User * curUser, char * sData, const uint32_t &iLen);
    bool GetNickList(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck);
	void Key(User * curUser, char * sData, const uint32_t &iLen);
	void Kick(User * curUser, char * sData, const uint32_t &iLen);
    static bool SearchDeflood(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck, const bool &bMulti);
    void Search(User * curUser, char * sData, uint32_t iLen, const bool &bCheck, const bool &bMulti);
    bool MyINFODeflood(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck);
	static bool MyINFO(User * curUser, char * sData, const uint32_t &iLen);
	void MyPass(User * curUser, char * sData, const uint32_t &iLen);
	void OpForceMove(User * curUser, char * sData, const uint32_t &iLen);
	void RevConnectToMe(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck);
	void SR(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck);
	void Supports(User * curUser, char * sData, const uint32_t &iLen);
    void To(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck);
	void ValidateNick(User * curUser, char * sData, const uint32_t &iLen);
	void Version(User * curUser, char * sData, const uint32_t &iLen);
    static bool ChatDeflood(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck);
	void Chat(User * curUser, char * sData, const uint32_t &iLen, const bool &bCheck);
	void Close(User * curUser, char * sData, const uint32_t &iLen);
    
    void Unknown(User * curUser, char * sData, const uint32_t &iLen);
    void MyNick(User * pUser, char * sData, const uint32_t &ui32Len);
    
    bool ValidateUserNick(User * curUser, char * Nick, const size_t &szNickLen, const bool &ValidateNick);

	PassBf * Find(const uint8_t * ui128IpHash);
	void Remove(PassBf * PassBfItem);

    static bool CheckIP(const User * curUser, const char * sIP);
    char * GetPort(char * sData, char cPortEnd, size_t &szPortLen);
    void SendIncorrectIPMsg(User * curUser, char * sBadIP, const bool &bCTM);
    static void SendIPFixedMsg(User * pUser, char * sBadIP, char * sRealIP);

    PrcsdUsrCmd * AddSearch(User * pUser, PrcsdUsrCmd * cmdSearch, char * sSearch, const size_t &szLen, const bool &bActive) const;
protected:
public:
	clsDcCommands();
    ~clsDcCommands();

    static clsDcCommands * mPtr;

    void PreProcessData(User * curUser, char * sData, const bool &bCheck, const uint32_t &iLen);
    void ProcessCmds(User * curUser);

    static void SRFromUDP(User * curUser, char * sData, const size_t &szLen);
    
	uint32_t iStatChat, iStatCmdUnknown, iStatCmdTo, iStatCmdMyInfo, iStatCmdSearch, iStatCmdSR, iStatCmdRevCTM;
	uint32_t iStatCmdOpForceMove, iStatCmdMyPass, iStatCmdValidate, iStatCmdKey, iStatCmdGetInfo, iStatCmdGetNickList;
	uint32_t iStatCmdConnectToMe, iStatCmdVersion, iStatCmdKick, iStatCmdSupports, iStatBotINFO, iStatZPipe;
    uint32_t iStatCmdMultiSearch, iStatCmdMultiConnectToMe, iStatCmdClose;
};
//---------------------------------------------------------------------------

#endif
