//

//---------------------------------------------------------------------------
#ifndef serviceLoopH
#define serviceLoopH
//---------------------------------------------------------------------------
struct User;
//---------------------------------------------------------------------------

class clsServiceLoop {
private:
    struct AcceptedSocket {
#ifdef _WIN32
        SOCKET s;
#else
		int s;
#endif

        sockaddr_storage addr;

        AcceptedSocket *next;
    };

    uint64_t iLstUptmTck;

#ifdef _WIN32
    CRITICAL_SECTION csAcceptQueue;
#else
	pthread_mutex_t mtxAcceptQueue;
#endif

	AcceptedSocket *AcceptedSocketsS, *AcceptedSocketsE;

#ifndef _WIN32
    int iSIG;

    siginfo_t info;

    sigset_t sst;

    struct timespec zerotime;
#endif

	char msg[1024];

    void AcceptUser(AcceptedSocket * AccptSocket);
protected:
public:
    static clsServiceLoop * mPtr;

	clsServiceLoop();
	~clsServiceLoop();

#ifdef _WIN32
    static UINT_PTR srvLoopTimer;
#endif

    double dLoggedUsers, dActualSrvLoopLogins;

    uint32_t iLastSendRest, iSendRestsPeak, iLastRecvRest, iRecvRestsPeak, iLoopsForLogins;
    bool bRecv;

#ifdef _WIN32
	void AcceptSocket(const SOCKET &s, const sockaddr_storage &addr);
#else
	void AcceptSocket(const int &s, const sockaddr_storage &addr);
#endif
	void ReceiveLoop();
	void SendLoop();
	void Looper();
};
//---------------------------------------------------------------------------

#endif
