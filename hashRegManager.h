//---------------------------------------------------------------------------
#ifndef hashRegManagerH
#define hashRegManagerH
//---------------------------------------------------------------------------
struct User;
//---------------------------------------------------------------------------

struct RegUser {
    char * sNick;

    union {
        char * sPass;
        uint8_t * ui8PassHash;
    };

    RegUser *prev, *next;
    RegUser *hashtableprev, *hashtablenext;

    time_t tLastBadPass;

    uint32_t ui32Hash;

    uint16_t ui16Profile;

    uint8_t ui8BadPassCount;

    bool bPassHash;

    RegUser();
    ~RegUser();

    static RegUser * CreateReg(char * sRegNick, size_t szRegNickLen, char * sRegPassword, size_t szRegPassLen, uint8_t * ui8RegPassHash, const uint16_t &ui16RegProfile);
    bool UpdatePassword(char * sNewPass, size_t &szNewLen);
}; 
//---------------------------------------------------------------------------

class clsRegManager {
private:
    RegUser *table[65536];

    uint8_t ui8SaveCalls;

    void LoadXML();
public:
    static clsRegManager * mPtr;

    RegUser *RegListS, *RegListE;

    clsRegManager(void);
    ~clsRegManager(void);

    bool AddNew(char * sNick, char * sPasswd, const uint16_t &iProfile);

    void Add(RegUser * Reg);
    void Add2Table(RegUser * Reg);
    static void ChangeReg(RegUser * pReg, char * sNewPasswd, const uint16_t &ui16NewProfile);
    void Delete(RegUser * pReg, const bool &bFromGui = false);
    void Rem(RegUser * Reg);
    void RemFromTable(RegUser * Reg);

    RegUser* Find(char * sNick, const size_t &szNickLen);
    RegUser* Find(User * u);
    RegUser* Find(uint32_t hash, char * sNick);

    void Load(void);
    void Save(const bool &bSaveOnChange = false, const bool &bSaveOnTime = false);

    void HashPasswords();
};
//---------------------------------------------------------------------------

#endif
