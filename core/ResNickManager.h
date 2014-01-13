//

//---------------------------------------------------------------------------
#ifndef ResNickManagerH
#define ResNickManagerH
//---------------------------------------------------------------------------

class clsReservedNicksManager {
private:
    struct ReservedNick {   
        char *sNick;

        ReservedNick *prev, *next;

        uint32_t ui32Hash;

        bool bFromScript;

        ReservedNick();
        ~ReservedNick();

        static ReservedNick * CreateReservedNick(const char * nick, uint32_t ui32NickHash);
    };

    ReservedNick *ReservedNicks;
public:
    static clsReservedNicksManager * mPtr;

	clsReservedNicksManager();
	~clsReservedNicksManager();

    bool CheckReserved(const char * sNick, const uint32_t &hash) const;
    void AddReservedNick(const char * sNick, const bool &bFromScript = false);
    void DelReservedNick(char * sNick, const bool &bFromScript = false);
};
//---------------------------------------------------------------------------

#endif
