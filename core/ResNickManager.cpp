//

//---------------------------------------------------------------------------
#include "stdinc.h"
//---------------------------------------------------------------------------
#include "ResNickManager.h"
//---------------------------------------------------------------------------
#include "ServerManager.h"
#include "utility.h"
//---------------------------------------------------------------------------
#ifdef _WIN32
	#pragma hdrstop
#endif
//---------------------------------------------------------------------------
clsReservedNicksManager * clsReservedNicksManager::mPtr = NULL;
//---------------------------------------------------------------------------

clsReservedNicksManager::ReservedNick::ReservedNick() {
    sNick = NULL;

	prev = NULL;
    next = NULL;

    ui32Hash = 0;

    bFromScript = false;
}
//---------------------------------------------------------------------------

clsReservedNicksManager::ReservedNick::~ReservedNick() {
#ifdef _WIN32
	if(sNick != NULL && HeapFree(clsServerManager::hLibHeap, HEAP_NO_SERIALIZE, (void *)sNick) == 0) {
        AppendDebugLog("%s - [MEM] Cannot deallocate sNick in clsReservedNicksManager::ReservedNick::~ReservedNick\n", 0);
    }
#else
	free(sNick);
#endif
}
//---------------------------------------------------------------------------

clsReservedNicksManager::ReservedNick * clsReservedNicksManager::ReservedNick::CreateReservedNick(const char * nick, uint32_t ui32NickHash) {
    ReservedNick * pReservedNick = new ReservedNick();

    if(pReservedNick == NULL) {
        AppendDebugLog("%s - [MEM] Cannot allocate new pReservedNick in ReservedNick::CreateReservedNick\n", 0);

        return NULL;
    }

    size_t szNickLen = strlen(nick);
#ifdef _WIN32
    pReservedNick->sNick = (char *)HeapAlloc(clsServerManager::hLibHeap, HEAP_NO_SERIALIZE, szNickLen+1);
#else
	pReservedNick->sNick = (char *)malloc(szNickLen+1);
#endif
    if(pReservedNick->sNick == NULL) {
        AppendDebugLog("%s - [MEM] Cannot allocate %" PRIu64 " bytes in ReservedNick::CreateReservedNick\n", (uint64_t)(szNickLen+1));

        delete pReservedNick;
        return NULL;
    }
    memcpy(pReservedNick->sNick, nick, szNickLen);
    pReservedNick->sNick[szNickLen] = '\0';

	pReservedNick->ui32Hash = ui32NickHash;

    return pReservedNick;
}
//---------------------------------------------------------------------------

clsReservedNicksManager::clsReservedNicksManager() {
    ReservedNicks = NULL;

	TiXmlDocument doc;
#ifdef _WIN32
	if(doc.LoadFile((clsServerManager::sPath+"\\cfg\\ReservedNicks.xml").c_str()) == false) {
		TiXmlDocument doc((clsServerManager::sPath+"\\cfg\\ReservedNicks.xml").c_str());
#else
	if(doc.LoadFile((clsServerManager::sPath+"/cfg/ReservedNicks.xml").c_str()) == false) {
		TiXmlDocument doc((clsServerManager::sPath+"/cfg/ReservedNicks.xml").c_str());
#endif
		doc.InsertEndChild(TiXmlDeclaration("1.0", "windows-1252", "yes"));
		TiXmlElement reservednicks("ReservedNicks");
		const char* Nicks[] = { "Hub-Security", "Admin", "Client", "Lib", "OpChat" };
		for(uint8_t ui8i = 0; ui8i < 5; ui8i++) {
			AddReservedNick(Nicks[ui8i]);
			TiXmlElement reservednick("ReservedNick");
			reservednick.InsertEndChild(TiXmlText(Nicks[ui8i]));

			reservednicks.InsertEndChild(reservednick);
		}
		doc.InsertEndChild(reservednicks);
		doc.SaveFile();
    }

#ifdef _WIN32
	if(doc.LoadFile((clsServerManager::sPath+"\\cfg\\ReservedNicks.xml").c_str())) {
#else
	if(doc.LoadFile((clsServerManager::sPath+"/cfg/ReservedNicks.xml").c_str())) {
#endif
		TiXmlHandle cfg(&doc);
		TiXmlNode *reservednicks = cfg.FirstChild("ReservedNicks").Node();
		if(reservednicks != NULL) {
			TiXmlNode *child = NULL;
			while((child = reservednicks->IterateChildren(child)) != NULL) {
				TiXmlNode *reservednick = child->FirstChild();
                    
				if(reservednick == NULL) {
					continue;
				}

				char *sNick = (char *)reservednick->Value();
                    
				AddReservedNick(sNick);
			}
        }
    }
}
//---------------------------------------------------------------------------
	
clsReservedNicksManager::~clsReservedNicksManager() {
    ReservedNick *next = ReservedNicks;

    while(next != NULL) {
        ReservedNick *cur = next;
        next = cur->next;

        delete cur;
    }
}
//---------------------------------------------------------------------------

// Check for reserved nicks true = reserved
bool clsReservedNicksManager::CheckReserved(const char * sNick, const uint32_t &hash) const {
    ReservedNick *next = ReservedNicks;

    while(next != NULL) {
        ReservedNick *cur = next;
        next = cur->next;

		if(cur->ui32Hash == hash && strcasecmp(cur->sNick, sNick) == 0) {
            return true;
        }
    }

    return false;
}
//---------------------------------------------------------------------------

void clsReservedNicksManager::AddReservedNick(const char * sNick, const bool &bFromScript/* = false*/) {
    uint32_t ulHash = HashNick(sNick, strlen(sNick));

    if(CheckReserved(sNick, ulHash) == false) {
        ReservedNick * pNewNick = ReservedNick::CreateReservedNick(sNick, ulHash);
        if(pNewNick == NULL) {
			AppendDebugLog("%s - [MEM] Cannot allocate pNewNick in clsReservedNicksManager::AddReservedNick\n", 0);
        	return;
        }

        if(ReservedNicks == NULL) {
            ReservedNicks = pNewNick;
        } else {
            ReservedNicks->prev = pNewNick;
            pNewNick->next = ReservedNicks;
            ReservedNicks = pNewNick;
        }

        pNewNick->bFromScript = bFromScript;
    }
}
//---------------------------------------------------------------------------

void clsReservedNicksManager::DelReservedNick(char * sNick, const bool &bFromScript/* = false*/) {
    uint32_t hash = HashNick(sNick, strlen(sNick));

    ReservedNick *next = ReservedNicks;
    while(next != NULL) {
        ReservedNick *cur = next;
        next = cur->next;

        if(cur->ui32Hash == hash && strcmp(cur->sNick, sNick) == 0) {
            if(bFromScript == true && cur->bFromScript == false) {
                continue;
            }

            if(cur->prev == NULL) {
                if(cur->next == NULL) {
                    ReservedNicks = NULL;
                } else {
                    cur->next->prev = NULL;
                    ReservedNicks = cur->next;
                }
            } else if(cur->next == NULL) {
                cur->prev->next = NULL;
            } else {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }

            delete cur;
            return;
        }
    }
}
//---------------------------------------------------------------------------
