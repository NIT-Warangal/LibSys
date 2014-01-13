//

//---------------------------------------------------------------------------
#ifndef UDPThreadH
#define UDPThreadH
//---------------------------------------------------------------------------

class UDPThread {
private:
#ifdef _WIN32
    SOCKET sock;

    unsigned int threadId;

    HANDLE threadHandle;
#else
    int sock;

    pthread_t threadId;
#endif

    bool bTerminated;

	char rcvbuf[4096];
public:
    static UDPThread * mPtrIPv4;
    static UDPThread * mPtrIPv6;

	UDPThread();
	~UDPThread();

    bool Listen(const int &iAddressFamily);
    void Resume();
    void Run();
	void Close();
	void WaitFor();

    static UDPThread * Create(const int &iAddressFamily);
    static void Destroy(UDPThread * pUDPThread);
};
//---------------------------------------------------------------------------

#endif
