
//---------------------------------------------------------------------------
#ifndef eventqueueH
#define eventqueueH
//---------------------------------------------------------------------------

class clsEventQueue {
private:
    struct event {
        char * sMsg;

        event *prev, *next;

        uint8_t ui128IpHash[16];
        uint8_t ui8Id;
    };

    event *NormalE, *ThreadE;

#ifdef _WIN32
	CRITICAL_SECTION csEventQueue;
#else
	pthread_mutex_t mtxEventQueue;
#endif
public:
    static clsEventQueue * mPtr;

	enum {
        EVENT_RESTART, 
        EVENT_RSTSCRIPTS, 
        EVENT_RSTSCRIPT, 
        EVENT_STOPSCRIPT, 
        EVENT_STOP_SCRIPTING, 
        EVENT_SHUTDOWN, 
        EVENT_REGSOCK_MSG, 
        EVENT_SRVTHREAD_MSG, 
        EVENT_UDP_SR
	};

    event *NormalS, *ThreadS;

    clsEventQueue();
    ~clsEventQueue();

    void AddNormal(uint8_t ui8Id, char * sMsg);
    void AddThread(uint8_t ui8Id, char * sMsg, const sockaddr_storage * sas = NULL);
    void ProcessEvents();
};
//---------------------------------------------------------------------------

#endif
