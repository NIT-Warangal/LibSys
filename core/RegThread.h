//

//---------------------------------------------------------------------------
#ifndef RegThreadH
#define RegThreadH
//---------------------------------------------------------------------------

class clsRegisterThread {
private:
    struct RegSocket {
        RegSocket();
        ~RegSocket();

        uint64_t iTotalShare;

#ifdef _WIN32
        SOCKET sock;
#else
		int sock;
#endif

        uint32_t iRecvBufLen, iRecvBufSize, iSendBufLen, iTotalUsers;

        uint32_t ui32AddrLen;

		char *sAddress, *sRecvBuf, *sSendBuf, *sSendBufHead;

        RegSocket *prev, *next;    
    };

#ifdef _WIN32
    unsigned int threadId;

    HANDLE threadHandle;
#else
	pthread_t threadId;
#endif

    RegSocket *RegSockListS, *RegSockListE;

    bool bTerminated;

    char sMsg[2048];

	void AddSock(char * sAddress, const size_t &ui32Len);
	bool Receive(RegSocket * Sock);
    static void Add2SendBuf(RegSocket * Sock, char * sData);
    bool Send(RegSocket * Sock);
    void RemoveSock(RegSocket * Sock);
public:
    static clsRegisterThread * mPtr;

    uint32_t iBytesRead, iBytesSent;

	clsRegisterThread();
	~clsRegisterThread();

	void Setup(char * sAddresses, const uint16_t &ui16AddrsLen);
	void Resume();
	void Run();
	void Close();
	void WaitFor();
};
//---------------------------------------------------------------------------

#endif
