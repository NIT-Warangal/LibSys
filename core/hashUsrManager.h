//---------------------------------------------------------------------------
#ifndef hashUsrManagerH
#define hashUsrManagerH
//---------------------------------------------------------------------------
struct User;
//---------------------------------------------------------------------------

class clsHashManager {
private:
    struct IpTableItem {
        IpTableItem *prev, *next;
        User * FirstUser;
        uint16_t ui16Count;
    };

    User *nicktable[65536];
    IpTableItem *iptable[65536];
public:
    static clsHashManager * mPtr;

    clsHashManager();
    ~clsHashManager();

    bool Add(User * u);
    void Remove(User * u);

    User * FindUser(char * sNick, const size_t &szNickLen);
    User * FindUser(User * u);
    User * FindUser(const uint8_t * ui128IpHash);

    uint32_t GetUserIpCount(User * u) const;
};
//---------------------------------------------------------------------------

#endif
