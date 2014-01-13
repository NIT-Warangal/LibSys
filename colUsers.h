//---------------------------------------------------------------------------
#ifndef colUsersH
#define colUsersH
//---------------------------------------------------------------------------
struct User;
//---------------------------------------------------------------------------
static const uint32_t NICKLISTSIZE = 1024*64;
static const uint32_t OPLISTSIZE = 1024*32;
static const uint32_t ZLISTSIZE = 1024*16;
static const uint32_t ZMYINFOLISTSIZE = 1024*128;
//---------------------------------------------------------------------------

class clsUsers {
private:
    struct RecTime {
        uint64_t ui64DisConnTick;
        uint32_t ui32NickHash;
        RecTime *prev, *next;
        char * sNick;
        uint8_t ui128IpHash[16];
    };

    uint64_t iChatMsgsTick, iChatLockFromTick;

    uint16_t iChatMsgs;

    RecTime * RecTimeList;

	User *elist;

    bool bChatLocked;

	char msg[1024];
public:
    static clsUsers * mPtr;

    uint32_t myInfosLen, myInfosSize, iZMyInfosLen, iZMyInfosSize;
    uint32_t myInfosTagLen, myInfosTagSize, iZMyInfosTagLen, iZMyInfosTagSize;
    uint32_t nickListLen, nickListSize, iZNickListLen, iZNickListSize;
    uint32_t opListLen, opListSize, iZOpListLen, iZOpListSize;
    uint32_t userIPListSize, userIPListLen, iZUserIPListSize, iZUserIPListLen;

    char *nickList, *sZNickList, *opList, *sZOpList, *userIPList, *sZUserIPList; 
    char *myInfos, *sZMyInfos, *myInfosTag, *sZMyInfosTag;

    User *llist;
    
    uint16_t ui16ActSearchs, ui16PasSearchs;

    clsUsers();
    ~clsUsers();

    void DisconnectAll();
    void AddUser(User * u);
    void RemUser(User * u);
    void Add2NickList(User * u);
    void AddBot2NickList(char * Nick, const size_t &szNickLen, const bool &isOp);
    void Add2OpList(User * u);
    void DelFromNickList(char * Nick, const bool &isOp);
    void DelFromOpList(char * Nick);
    void SendChat2All(User * cur, char * sData, const size_t &szChatLen, void * pToUser);
	void Add2MyInfos(User * u);
	void DelFromMyInfos(User * u);
    void Add2MyInfosTag(User * u);
	void DelFromMyInfosTag(User * u);
    void AddBot2MyInfos(char * MyInfo);
	void DelBotFromMyInfos(char * MyInfo);
	void Add2UserIP(User * cur);
	void DelFromUserIP(User * cur);
	void Add2RecTimes(User * curUser);
	bool CheckRecTime(User * curUser);
};
//---------------------------------------------------------------------------

#endif
