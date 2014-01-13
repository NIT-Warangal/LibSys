
//---------------------------------------------------------------------------
#ifndef HubCommandsH
#define HubCommandsH
//---------------------------------------------------------------------------
struct User;
//---------------------------------------------------------------------------

class clsHubCommands {
private:
    static char msg[1024];

    static bool Ban(User * curUser, char * sCommand, bool fromPM, bool bFull);
    static bool BanIp(User * curUser, char * sCommand, bool fromPM, bool bFull);
    static bool NickBan(User * curUser, char * sNick, char * sReason, bool bFromPM);
    static bool TempBan(User * curUser, char * sCommand, const size_t &dlen, bool fromPM, bool bFull);
    static bool TempBanIp(User * curUser, char * sCommand, const size_t &dlen, bool fromPM, bool bFull);
    static bool TempNickBan(User * curUser, char * sNick, char * sTime, const size_t &szTimeLen, char * sReason, bool bFromPM);
    static bool RangeBan(User * curUser, char * sCommand, const size_t &dlen, bool fromPM, bool bFull);
    static bool RangeTempBan(User * curUser, char * sCommand, const size_t &dlen, bool fromPM, bool bFull);
    static bool RangeUnban(User * curUser, char * sCommand, bool fromPM);
    static bool RangeUnban(User * curUser, char * sCommand, bool fromPM, unsigned char cType);

    static void SendNoPermission(User * user, const bool &fromPM);
    static int CheckFromPm(User * curUser, const bool &fromPM);
    static void UncountDeflood(User * curUser, const bool &fromPM);
public:
    static bool DoCommand(User * curUser, char * sCommand, const size_t &szCmdLen, bool fromPM = false);
};
//---------------------------------------------------------------------------

#endif
