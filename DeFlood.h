// DeFlooding Header Requirement.

//---------------------------------------------------------------------------
#ifndef DeFloodH
#define DeFloodH
//---------------------------------------------------------------------------

enum DefloodTypes {
    DEFLOOD_GETNICKLIST, 
    DEFLOOD_MYINFO, 
    DEFLOOD_SEARCH, 
    DEFLOOD_CHAT, 
    DEFLOOD_PM, 
    DEFLOOD_SAME_SEARCH, 
    DEFLOOD_SAME_PM,
    DEFLOOD_SAME_CHAT, 
    DEFLOOD_SAME_MULTI_PM, 
    DEFLOOD_SAME_MULTI_CHAT, 
    DEFLOOD_CTM, 
    DEFLOOD_RCTM, 
    DEFLOOD_SR, 
    DEFLOOD_MAX_DOWN, 
    INTERVAL_CHAT, 
    INTERVAL_PM, 
    INTERVAL_SEARCH
};
//---------------------------------------------------------------------------

bool DeFloodCheckForFlood(User * u, const uint8_t &ui8DefloodType, const int16_t &ui16Action,
    uint16_t &ui16Count, uint64_t &ui64LastOkTick, 
    const int16_t &ui16DefloodCount, const uint32_t &ui32DefloodTime, char * sOtherNick = NULL);
bool DeFloodCheckForSameFlood(User * u, const uint8_t &ui8DefloodType, const int16_t &ui16Action,
    uint16_t &ui16Count, const uint64_t &ui64LastOkTick, 
    const int16_t &ui16DefloodCount, const uint32_t &ui32DefloodTime, 
    char * sNewData, const size_t &ui32NewDataLen, 
    char * sOldData, const uint16_t &ui16OldDataLen, bool &bNewData, char * sOtherNick = NULL);
bool DeFloodCheckForDataFlood(User * u, const uint8_t &ui8DefloodType, const int16_t &ui16Action,
    uint32_t &ui16Count, uint64_t &ui64LastOkTick, 
    const int16_t &ui16DefloodCount, const uint32_t &ui32DefloodTime);
void DeFloodDoAction(User * u, const uint8_t &ui8DefloodType, const int16_t &ui16Action,
    uint16_t &ui16Count, char * sOtherNick);
bool DeFloodCheckForWarn(User * u, const uint8_t &ui8DefloodType, char * sOtherNick);
const char * DeFloodGetMessage(const uint8_t ui8DefloodType, const uint8_t ui8MsgId);
void DeFloodReport(User * u, const uint8_t ui8DefloodType, char *sAction);
bool DeFloodCheckInterval(User * u, const uint8_t &ui8DefloodType, 
    uint16_t &ui16Count, uint64_t &ui64LastOkTick, 
    const int16_t &ui16DefloodCount, const uint32_t &ui32DefloodTime, char * sOtherNick = NULL);
//---------------------------------------------------------------------------

#endif
