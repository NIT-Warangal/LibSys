//---------------------------------------------------------------------------
#ifndef zlibutilityH
#define zlibutilityH
//---------------------------------------------------------------------------

class clsZlibUtility {
private:
    size_t szZbufferSize;
    char *sZbuffer;
public:
    static clsZlibUtility * mPtr;

	clsZlibUtility();
	~clsZlibUtility();
	
    char * CreateZPipe(const char *sInData, const size_t &sInDataSize, uint32_t &iOutDataLen);
    char * CreateZPipe(char *sInData, const size_t &sInDataSize, char *sOutData, size_t &szOutDataLen, size_t &szOutDataSize);
    char * CreateZPipe(char *sInData, const unsigned int &sInDataSize, char *sOutData, unsigned int &iOutDataLen, unsigned int &iOutDataSize, size_t (* pAllignFunc)(size_t n));
};
//---------------------------------------------------------------------------

#endif
