//

//---------------------------------------------------------------------------
#ifndef UpdateCheckThreadH
#define UpdateCheckThreadH
//---------------------------------------------------------------------------

class clsUpdateCheckThread {
private:
    SOCKET sSocket;

	uint32_t ui32FileLen;

    uint32_t ui32RecvBufLen, ui32RecvBufSize;
    uint32_t ui32BytesRead, ui32BytesSent;

    HANDLE hThread;

    char * sRecvBuf;
    
    bool bOk, bData, bTerminated;

	char sMsg[2048];

    static void Message(char * sMessage, const size_t &szLen);
    bool Receive();
    bool SendHeader();
public:
    static clsUpdateCheckThread * mPtr;

	clsUpdateCheckThread();
	~clsUpdateCheckThread();

    void Resume();
    void Run();
	void Close();
	void WaitFor();
};
//---------------------------------------------------------------------------

#endif
